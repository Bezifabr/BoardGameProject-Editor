/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// InputMgr.cpp
// Purpose: Handles input - keyboard and mouse events.
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
#include "InputMgr.h"

InputMgr::InputMgr()
{
}
InputMgr::~InputMgr()
{
}

void InputMgr::Update(sf::Event& event)
{
	this->event_ = event;
}

bool InputMgr::KeyPressed(int key)
{
	if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)))
		return true;
	return false;

}

bool InputMgr::KeyPressed(std::vector<int> keys)
{
	for (int i = 0; i < keys.size(); i++)
		if (!KeyPressed(keys[i]))
			return false;
	return true;
}

bool InputMgr::KeyReleased(int key)
{
	if (this->event_.type == sf::Event::KeyReleased
		&& event_.key.code == key)
		return true;
	return false;
}

bool InputMgr::KeyReleased(std::vector<int> keys)
{
	for (int i = 0; i < keys.size(); i++)
		if (!KeyReleased(keys[i]))
			return false;
	return true;
}

bool InputMgr::KeyPressing(int key)
{
	if (sf::Keyboard::isKeyPressed
		(static_cast<sf::Keyboard::Key>(key)))
		return true;

	return false;
}

bool InputMgr::KeyPressing(std::vector<int> keys)
{
	for (int i = 0; i < keys.size(); i++)
		if (!KeyPressing(keys[i]))
			return false;
	return true;
}

bool InputMgr::LMBPressed()
{
	if (event_.type == sf::Event::MouseButtonPressed
		&& event_.mouseButton.button == sf::Mouse::Left)
		return true;
	return false;
}

bool InputMgr::RMBPressed()
{
	if (event_.type == sf::Event::MouseButtonPressed
		&& event_.mouseButton.button == sf::Mouse::Right)
		return true;
	return false;
}

bool InputMgr::LMBReleased()
{
	if (event_.type == sf::Event::MouseButtonReleased
		&& event_.mouseButton.button == sf::Mouse::Left)
		return true;
	return false;
}

bool InputMgr::RMBReleased()
{
	if (event_.type == sf::Event::MouseButtonReleased
		&& event_.mouseButton.button == sf::Mouse::Right)
		return true;
	return false;
}

bool InputMgr::GetCanClick()
{
	return this->canClick_;
}

void InputMgr::SetCanClick(bool value)
{
	this->canClick_ = value;
}
