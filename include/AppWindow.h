/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// AppWindow.h
// Purpose: Contains AppWindow class which is own version of sf::RenderWindow class
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////
#pragma once

////////////////////
// HEADERS
////////////////////
#include <SFML/Graphics.hpp>

class AppWindow
{
public:
	AppWindow() {}
	~AppWindow() {}
	
	sf::RenderWindow& Get()	{ return window_; }
private:
	sf::RenderWindow window_;


};

