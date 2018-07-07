/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDFieldProperites.cpp
// Purpose: Contains definition of Create() method from WNDFieldProperties class.
// Changes variables of fields.
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
#include "WindowMgr.h"
#include "Action.h"


sfg::Window::Ptr WNDFieldProperties::Create()
{
	box_["Properties"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	box_["Properties"]->SetSpacing(5.f);
	box_["Options"]->SetSpacing(5.f);
	boxBody->SetSpacing(5.f);

	box_["Properties"]->SetRequisition(sf::Vector2f(190, 425));
	box_["Options"]->SetRequisition(sf::Vector2f(190, 25));

	AddWindowOption("Properties", "ID", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Type", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Order", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Position x", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Position y", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Track", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "First Track", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Second Track", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Next Track", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Next Location", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Location Entrance", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Texture", sf::Vector2f(200, 10));

	/*******************************************/

	PackWidget("Options", "Ok", sfg::Button::Create(FIELD_OK), std::bind(&ActionWindow::FieldPropertiesOk, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(FIELD_CANCEL), std::bind(&ActionWindow::CloseFieldProperties, action_));

	//	for (size_t i = 0; i != fieldsBar_.size(); i++)
	//		comboBox_["FieldProperties_Properties_Type"]->AppendItem(fieldsBar_[i].GetType());

	//	entry_["FieldProperties_Properties_Order"]->SetState(sfg::Entry::State::INSENSITIVE);
	boxBody->Pack(box_["Properties"]);
	boxBody->Pack(box_["Options"]);


	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(boxBody);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 125, WND_SIZE.y / 2 - 250, 325, 50));
	window->Show(false);

	return window;
}