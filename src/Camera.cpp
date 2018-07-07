/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Camera.cpp
// Purpose: Contains definitions of methods from Camera class which is own version of sf::View class
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
#include "Camera.h"
#include "Constants.h"


Camera::Camera()
{
	camera_.setViewport(sf::FloatRect(0, 0, 1, 1.0f));
	camera_.setSize(WND_SIZE.x * 2, WND_SIZE.y * 2);
	camera_.reset(sf::FloatRect(200, 200, WND_SIZE.x, WND_SIZE.y));
}

Camera::~Camera()
{
}

sf::Vector2f Camera::MMBCameraMoving(sf::Event& event, sf::RenderWindow& window)
{
	if (scrollPressed_ == false)
		if (event.type == sf::Event::MouseButtonPressed
			&& event.mouseButton.button == sf::Mouse::Middle)
		{
			scrollPressed_ = true;
			scrollClickedPosition_ = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		}

	if (scrollPressed_ == true)
		if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{
			distanceBetweenScrolls_ = scrollClickedPosition_ - window.mapPixelToCoords(sf::Mouse::getPosition(window));
			camera_.move(distanceBetweenScrolls_);
		}

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Middle)
		scrollPressed_ = false;

	return camera_.getCenter();
}
