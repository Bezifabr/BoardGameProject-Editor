/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// StateMgr.cpp
// Purpose: It supports all operations in the main loop
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

////////////////////
// HEADERS
////////////////////
#include "StateMgr.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <windows.h>
#include <ctime>

#define RelativeMousePosition appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()))

/////////////////////////////////////////////////////////////
/******************** STARTING METHODS *********************/
StateMgr::StateMgr()
{
}

void StateMgr::Initialize()
{
	StartingSettings();

	mapMgr_.NewLocation("New location");
	guiMgr_.Init(&desktop_, appWindow_, &mapMgr_, &data_, &fieldMgr_, &npcMgr_);
	guiMgr_.SetConsole(&console_);
	fieldMgr_.Init(&data_, &mapMgr_, &input_, appWindow_);
	npcMgr_.Init(&data_, &mapMgr_, &input_, appWindow_);

	editorMgr_.Init(&fieldMgr_, &npcMgr_, &data_);
	editorMgr_.LoadConfig();

	console_.LoadGameObjects(&mapMgr_.GetGameObjects());
	console_.LoadRenderWindow(&appWindow_->Get());
	console_.TurnOn();
}

void StateMgr::StartingSettings()
{
	elapsed_.restart();
	cameraMovementTimer_.restart();
	autoSaveTime_.restart();

	selectedTool_ = Field;
	canPressKey_ = true;
	canClick_ = true;
}
/**********************************************************/

///////////////////////////////////////////////////////////
/******************** ENDING METHODS *********************/
StateMgr::~StateMgr()
{
	ClearMap();
}

void StateMgr::ClearMap()
{
	mapMgr_.GetCurrentLocation()->GetFields().clear();
}

/*********************************************************/

///////////////////////////////////////////////////////////
/******************** MISC METHODS ********************/
void StateMgr::Update(sf::Event event)
{
	if (!console_.Running())
	{
		input_.Update(event);

		desktop_.Update(0.f);

		if (guiMgr_.IsWindowOpened() == false)
		{
			npcMgr_.ChangePosition();

			FieldEvents();
			NPCEvents();

			Autosave();  //<< Is autosaving map (temporary turned off)

			camera_.Get().setCenter(mapMgr_.GetCurrentLocation()->GetCameraPosition());
			mapMgr_.GetCurrentLocation()->SetCameraPosition(camera_.MMBCameraMoving(event, appWindow_->Get()));
			CameraMoving();
			ChangeTool();

		}

		camera_.Get().setCenter(mapMgr_.GetCurrentLocation()->GetCameraPosition());
		appWindow_->Get().setView(camera_.Get());

		if (input_.LMBReleased())
			canClick_ = true;
	}
}

void StateMgr::HandleEvents(sf::Event & event)
{
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		guiMgr_.GetActionWindow().OpenReallyClose();

	guiMgr_.HandleEvents(event);

}

void StateMgr::Draw()
{	
	/* Draws fields and other map objects */
	mapMgr_.DrawCurrentLocation(appWindow_);


	/* Draws tool handled by user */
	switch (selectedTool_)
	{
	case StateMgr::Field:
		fieldMgr_.DrawTool();
		break;
	case StateMgr::NPC:
		npcMgr_.DrawTool();
		break;
	}
}

/********************************************************/

////////////////////////////////////////////////////////////
/****************** WORKSPACE METHODS *******************/

void StateMgr::CameraMoving()
{
	if (guiMgr_.IsWindowOpened() == false)
		if (cameraMovementTimer_.getElapsedTime().asMilliseconds() > 25)
		{
			cameraMovementTimer_.restart();

			CameraArrowsMoving();		//<< Moves camera by arrows events
			CameraMouseMoving();		//<< Moves camera by mouse events

			camera_.Get().setCenter(mapMgr_.GetCurrentLocation()->GetCameraPosition());  //<<Sets camera position
		}
}


void StateMgr::ChangeTool()
{
	if (canPressKey_ == true)
	{
		ChangeToolByKey(sf::Keyboard::Q, Field);
		ChangeToolByKey(sf::Keyboard::W, NPC);
	}

	if (input_.KeyReleased(sf::Keyboard::Q) || input_.KeyReleased(sf::Keyboard::W))
		canPressKey_ = true;

}


void StateMgr::Autosave()
{
	//if (autoSaveTime_.getElapsedTime().asSeconds() >= 30)
	//{ 
	//	autoSaveTime_.restart();
	//	time_t now = time(0);


	//	tm *ltm = localtime(&now);
	//	std::string mapSource;
	//	mapSource = "Maps/Backups" + mapMgr_.GetSource() + "-" + to_string(ltm->tm_mday) + "-" + to_string(ltm->tm_mon) + "-"
	//		+ to_string(ltm->tm_year) + "_" + to_string(ltm->tm_hour) + "-" + to_string(ltm->tm_min) + "-" + to_string(ltm->tm_sec) + ".txt";

	//	std::cout << mapSource << std::endl;

	//	
	////	SaveMap(mapSource.c_str(), false);

	//	mapSource.clear();
	//}

}


void StateMgr::OpenNPCProperties()
{
	if (!npcMgr_.IsNPCBarEmpty())
	{
		if (npcMgr_.IsNPCSelected() == true && input_.KeyReleased(sf::Keyboard::Return))
			for (size_t i = 0; i != mapMgr_.GetNPCs().size(); i++)
				if (mapMgr_.GetNPCs()[i].IsSelected() == true)
				{
					guiMgr_.GetActionWindow().OpenNPCProperties(&mapMgr_.GetNPCs()[i], i, &data_);
					break;
				}
	}
	else throw exception("NPCs tool bar is empty");
}

void StateMgr::OpenFieldProperties()
{
	if (!fieldMgr_.IsFieldBarEmpty())
	{
		if (fieldMgr_.IsFieldSelected() == true && input_.KeyReleased(sf::Keyboard::Return))
			for (size_t i = 0; i != mapMgr_.GetCurrentLocation()->GetFields().size(); i++)
				if (mapMgr_.GetCurrentLocation()->GetFields()[i].IsSelected() == true)
				{
					guiMgr_.GetActionWindow().OpenFieldProperties(&mapMgr_.GetCurrentLocation()->GetFields()[i], i, &data_);
					break;
				}
	}
	else throw exception("fields tool bar is empty");
}

void StateMgr::CameraMouseMoving()
{
	if (sf::Mouse::getPosition(appWindow_->Get()).x >= WND_SIZE.x - 25)
		mapMgr_.GetCurrentLocation()->CameraMove(5, 0);

	if (sf::Mouse::getPosition(appWindow_->Get()).x <= 25)
		mapMgr_.GetCurrentLocation()->CameraMove(-5, 0);

	if (sf::Mouse::getPosition(appWindow_->Get()).y >= WND_SIZE.y - 25)
		mapMgr_.GetCurrentLocation()->CameraMove(0, 5);

	if (sf::Mouse::getPosition(appWindow_->Get()).y <= 25 && sf::Mouse::getPosition(appWindow_->Get()).x > WND_SIZE.x / 4 + 500)
		mapMgr_.GetCurrentLocation()->CameraMove(0, -5);
}

void StateMgr::CameraArrowsMoving()
{
	if (input_.KeyPressing(sf::Keyboard::Left))
		mapMgr_.GetCurrentLocation()->CameraMove(-5, 0);

	if (input_.KeyPressing(sf::Keyboard::Right))
		mapMgr_.GetCurrentLocation()->CameraMove(5, 0);

	if (input_.KeyPressing(sf::Keyboard::Down))
		mapMgr_.GetCurrentLocation()->CameraMove(0, 5);

	if (input_.KeyPressing(sf::Keyboard::Up))
		mapMgr_.GetCurrentLocation()->CameraMove(0, -5);

}

void StateMgr::ChangeToolByKey(sf::Keyboard::Key key, ToolSelected tool)
{
		if (input_.KeyPressed(key))
		{
			selectedTool_ = tool;
			canPressKey_ = false;
		}
}

void StateMgr::FieldEvents()
{
	if (selectedTool_ == StateMgr::Field) {
		fieldMgr_.Update(guiMgr_.IsMenuOpened());
		OpenFieldProperties();
	}
}

void StateMgr::NPCEvents()
{
	if (selectedTool_ == StateMgr::NPC) {
		npcMgr_.Update();
		OpenNPCProperties();
	}
}





//
//void StateMgr::SelectTrack()
//{
//	if (isTrackToolSelected_ == true && isTrackingModeEnabled_ == true)
//		for (mapMgr_.GetCurrentMap()->GetFieldsIT() = mapMgr_.GetCurrentMap()->GetFields().begin();
//		mapMgr_.GetCurrentMap()->GetFieldsIT() != mapMgr_.GetCurrentMap()->GetFields().end(); 
//		++mapMgr_.GetCurrentMap()->GetFieldsIT())
//			if (mapMgr_.GetCurrentMap()->GetFieldsIT()->GetSprite().getGlobalBounds().contains(RelativeMousePosition))
//			{
//				mapMgr_.GetCurrentMap()->GetFieldsIT()->SetTrack(selectedTool_);
//			}
//}
//void StateMgr::SelectOrder()
//{
//	if (isOrderModeEnabled_ == true && isFieldToolSelected_ == false)
//		for (mapMgr_.GetCurrentMap()->GetFieldsIT() = mapMgr_.GetCurrentMap()->GetFields().begin();
//		mapMgr_.GetCurrentMap()->GetFieldsIT() != mapMgr_.GetCurrentMap()->GetFields().end();
//		++mapMgr_.GetCurrentMap()->GetFieldsIT())
//			if (mapMgr_.GetCurrentMap()->GetFieldsIT()->GetSprite().getGlobalBounds().contains(RelativeMousePosition))
//			{
//				if (isFieldIteratorSelected_ == false)
//				{
//					selectedFieldIT_ = mapMgr_.GetCurrentMap()->GetFieldsIT();
//					isFieldIteratorSelected_ = true;
//				}
//				else if (isFieldIteratorSelected_ == true)
//				{
//					iter_swap(selectedFieldIT_, mapMgr_.GetCurrentMap()->GetFieldsIT());
//					isFieldIteratorSelected_ = false;
//				}
//			}
//}