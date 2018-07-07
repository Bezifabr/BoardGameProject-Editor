/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Camera.h
// Purpose: Contains Camera class which is own version of sf::View class
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

class Camera
{
public:
	Camera();
	~Camera();

	sf::View& Get() { return camera_; }
	sf::Vector2f MMBCameraMoving(sf::Event& event, sf::RenderWindow& window);
private:
	sf::View camera_;
	bool scrollPressed_;
	sf::Vector2f scrollClickedPosition_;
	sf::Vector2f distanceBetweenScrolls_;
};
