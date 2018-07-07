/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Location.cpp
// Purpose: Contains fields, background and other settings in Location class.
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
#include "Location.h"

#include <Windows.h>


Location::Location()
{
}


Location::~Location()
{
}

bool Location::IsBackgroundLoaded()
{
	return isBackgroundLoaded_;
}

void Location::SetBackgroundTexture(std::string source)
{
	if(source != "")
		if (backgroundTexture_.loadFromFile(source))
		{
			isBackgroundLoaded_ = true;
			backgroundSprite_.setTexture(backgroundTexture_);
			backgroundSource_ = source;
		}
		else {
			MessageBox(NULL,  source.c_str() , "Cannot load",
				MB_ICONERROR | MB_OK);
		}

}

void Location::SetBackgroundTexture(sf::Texture & texture)
{
	backgroundSprite_.setTexture(texture);
}

void Location::DrawBackground(sf::RenderWindow& window)
{
	window.draw(backgroundSprite_);
}

std::vector<Field>& Location::GetFields()
{
	return fields_;
}

std::vector<Field>::iterator& Location::GetFieldsIT()
{
	return fieldIT_;
}

void Location::SetFields(std::vector<Field>& fields)
{
	for (size_t i = 0; i < fields.size(); i++)
	fields_.push_back(fields[i]);
}
std::vector<Field>::iterator & Location::GetSecondFieldsIT()
{
	return secondFieldIT_;
}