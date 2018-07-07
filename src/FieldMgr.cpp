/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// FieldMgr.cpp
// Purpose: Handles operations in the fields.
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

#include "FieldMgr.h"


void FieldMgr::Init(DataMgr* data, MapMgr* mapMgr, InputMgr* input, AppWindow* appWindow)
{
	data_ = data;
	mapMgr_ = mapMgr;
	input_ = input;
	appWindow_ = appWindow;


	currentField_.GetHeader().setFont(data_->GetFont("Default"));
	currentField_.GetHeader().setColor(sf::Color::White);
	currentField_.GetHeader().setPosition(300, 300);
	currentField_.GetSprite().setColor(sf::Color(128, 255, 255, 128));

	selectedTool_ = 1;
	isFieldToolSelected_ = true;
	canClick_ = true;
	clickTimer_.restart();

}

void FieldMgr::ChangeTool()
{
			for (int i = 0; i < fieldsBar_.size(); i++)
				if (input_->KeyPressing(sf::Keyboard::Num1 + i) && (selectedField_ != i || isFieldToolSelected_ == false))
				{
					selectedField_ = i;
					isFieldToolSelected_ = true;
				}
}

size_t FieldMgr::GetFieldBarSize()
{
	return fieldsBar_.size();
}

Field & FieldMgr::GetFieldTemplate(int ID)
{
	return fieldsBar_[ID];
}

bool FieldMgr::IsFieldBarEmpty()
{
	return fieldsBar_.empty();
}

bool FieldMgr::IsFieldSelected()
{
	return isFieldSelected_;
}

void FieldMgr::DrawTool()
{
	if (appWindow_)
	{
		if (isFieldToolSelected_ == true)
			appWindow_->Get().draw(fieldsBar_[selectedField_].GetSprite());
	}
	else
		std::cout << "Can't render field tool due appWindow is not loaded" << std::endl;
}

void FieldMgr::AddFieldType(std::string type)
{
	if (fieldsBar_.size() <= 10)
	{
		currentField_.SetType(type);
		currentField_.SetTextureID("P_" + type);
		currentField_.GetSprite().setTexture(data_->GetTexture("P_" + type));
		fieldsBar_.push_back(currentField_);
	}
	else std::cout << "FieldMgr::AddFieldType(): Fields limit reached" << std::endl;
}

void FieldMgr::SelectField()
{
	if (isFieldToolSelected_ == false && isFieldGrabbed_ == false)
	{
		for (mapMgr_->GetCurrentLocation()->GetFieldsIT() = mapMgr_->GetCurrentLocation()->GetFields().begin();
		mapMgr_->GetCurrentLocation()->GetFieldsIT() != mapMgr_->GetCurrentLocation()->GetFields().end();
			++mapMgr_->GetCurrentLocation()->GetFieldsIT())
		{
			int index = std::distance(mapMgr_->GetCurrentLocation()->GetFields().begin(), mapMgr_->GetCurrentLocation()->GetFieldsIT());

			if (mapMgr_->GetCurrentLocation()->GetFieldsIT()->GetSprite().getGlobalBounds().contains(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()))))
			{
				UnselectField();
				isFieldGrabbed_ = true;
				isFieldSelected_ = true;
				selectedField_ = index;
				mapMgr_->GetCurrentLocation()->GetFieldsIT()->IsSelected(true);
				mapMgr_->GetCurrentLocation()->GetFieldsIT()->GetSprite().setColor(sf::Color(255, 255, 255, 128));
				mouse_prev_location_ = appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()));
				field_prev_location_ = sf::Vector2i(mapMgr_->GetCurrentLocation()->GetFieldsIT()->GetSprite().getPosition().x, mapMgr_->GetCurrentLocation()->GetFieldsIT()->GetSprite().getPosition().y);
			}
		}
	}
}

void FieldMgr::UnselectField()
{
	if (isFieldSelected_ == true || isFieldToolSelected_ == true)
	{
		isFieldToolSelected_ = false;
		isFieldSelected_ = false;
		for (mapMgr_->GetCurrentLocation()->GetSecondFieldsIT() = mapMgr_->GetCurrentLocation()->GetFields().begin();
		mapMgr_->GetCurrentLocation()->GetSecondFieldsIT() != mapMgr_->GetCurrentLocation()->GetFields().end();
			++mapMgr_->GetCurrentLocation()->GetSecondFieldsIT())
			if (mapMgr_->GetCurrentLocation()->GetSecondFieldsIT()->IsSelected() == true)
			{
				mapMgr_->GetCurrentLocation()->GetSecondFieldsIT()->GetSprite().setColor(sf::Color(255, 255, 255, 255));
				mapMgr_->GetCurrentLocation()->GetSecondFieldsIT()->IsSelected(false);
			}
	}
}

void FieldMgr::DeleteField()
{
	if (isFieldSelected_ == true && input_->KeyReleased(sf::Keyboard::Delete))
		for (mapMgr_->GetCurrentLocation()->GetFieldsIT() = mapMgr_->GetCurrentLocation()->GetFields().begin();
	mapMgr_->GetCurrentLocation()->GetFieldsIT() != mapMgr_->GetCurrentLocation()->GetFields().end();
		++mapMgr_->GetCurrentLocation()->GetFieldsIT())
			if (mapMgr_->GetCurrentLocation()->GetFieldsIT()->IsSelected() == true)
			{
				mapMgr_->GetCurrentLocation()->GetFields().erase(mapMgr_->GetCurrentLocation()->GetFieldsIT());
				isFieldToolSelected_ = false;
				isFieldSelected_ = false;
				break;
			}
}

void FieldMgr::PlaceField()
{
		if (isFieldToolSelected_ == true)
		{
			mapMgr_->GetCurrentLocation()->GetFields().push_back(fieldsBar_[selectedField_]);
			mapMgr_->GetCurrentLocation()->GetFields()[mapMgr_->GetCurrentLocation()->GetFields().size() - 1].GetSprite().setColor(sf::Color(255, 255, 255, 255));
			mapMgr_->GetCurrentLocation()->GetFields()[mapMgr_->GetCurrentLocation()->GetFields().size() - 1].GetHeader().
				setPosition(mapMgr_->GetCurrentLocation()->GetFields()[mapMgr_->GetCurrentLocation()->GetFields().size() - 1].GetSprite().getPosition());
		}
}

void FieldMgr::MoveField()
{

	if (isFieldGrabbed_ == true)
	{
		mapMgr_->GetCurrentLocation()->GetFields()[selectedField_].GetSprite().move(
			-1 * (mouse_prev_location_.x - appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get())).x), 
			-1 * (mouse_prev_location_.y - appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get())).y));
		mapMgr_->GetCurrentLocation()->GetFields()[selectedField_].GetHeader().setPosition(mapMgr_->GetCurrentLocation()->GetFields()[selectedField_].GetSprite().getPosition());
		mouse_prev_location_ = appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()));
		field_prev_location_ = sf::Vector2i(mapMgr_->GetCurrentLocation()->GetFields()[selectedField_].GetSprite().getPosition().x, mapMgr_->GetCurrentLocation()->GetFields()[selectedField_].GetSprite().getPosition().y);
	}
}

void FieldMgr::GUIUpdate()
{
	// Set tool position
	if (isFieldToolSelected_ == true)
	{
		fieldsBar_[selectedField_].GetSprite().setColor(sf::Color(255, 255, 255, 128));
		fieldsBar_[selectedField_].GetSprite().setPosition(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get())) - sf::Vector2f(30, 30));
	}
}

void FieldMgr::Update(bool isMenuOpened)
{
	if (engineSet_ == false && clickTimer_.getElapsedTime().asMicroseconds() > 350000)
	{
		isFieldToolSelected_ = false;
		engineSet_ = true;
	}

	if (canClick_ == true)
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (clickTimer_.getElapsedTime().asMilliseconds() > 150))
		{
			clickTimer_.restart();
			canClick_ = false;
			if (isMenuOpened != true)
			{
				PlaceField();
				SelectField();
			}
		}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		canClick_ = true;
		if (isFieldGrabbed_ == true)
			isFieldGrabbed_ = false;
	}

	if (input_->RMBReleased())
	{
		UnselectField();
	}

	DeleteField();
	MoveField();
	ChangeTool();
	GUIUpdate();
}

void FieldMgr::LoadFieldsFromFile(const char * source)
{
		std::ifstream openfile(source);
		if (openfile.is_open())
		{
			std::string tempType;
			std::string tempName;
			std::string tempTexture;
			while (!openfile.eof())
			{

				std::string line;

				std::getline(openfile, line); //< Load line

				line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

				if (line.find("//") != std::string::npos)
					line.erase(line.begin(), line.end());

				else if (line.find("Field{") != std::string::npos)
					tempType = "Field";


				if (tempType == "Field")
					if (line.find("Name=") != std::string::npos || line.find("name=") != std::string::npos)
					{
						line.erase(0, line.find('=') + 1);
						tempName = line;
						std::cout << "Name(" << line << ")" << std::endl;
					}
					else if (line.find("Texture=") != std::string::npos || line.find("texture=") != std::string::npos)
					{
						line.erase(0, line.find('=') + 1);
						tempTexture = line;
						std::cout << "Texture(" << line << ")" << std::endl;
					}


				if (line.find('}') != std::string::npos)
				{
					line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
					std::cout << " Type(" << tempType << ")" << std::endl;

					if (tempType == "Field")
					{
						if (fieldsBar_.size() <= 10)
						{
							currentField_.SetType(tempName);
							currentField_.SetTextureID(tempTexture);
							currentField_.GetSprite().setTexture(data_->GetTexture(currentField_.GetTextureID()));
							fieldsBar_.push_back(currentField_);
						}
						else std::cout << "FieldMgr::AddFieldType(): Fields limit reached" << std::endl;
					}


					tempName = "";
					tempTexture = "";
					tempType = "";
				}

			}
		}
	}
