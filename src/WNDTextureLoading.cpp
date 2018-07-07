/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDTextureLoading.cpp
// Purpose: Contains definition of Create() method from WNDTextureLoading class.
// Textures importing window.
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

sfg::Window::Ptr WNDTextureLoading::Create()
{
	box_["Properties"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	PackWidget("Properties", "Title", sfg::Label::Create("Load texture file"), std::bind(&Action::Nothing, action_));
	AddWindowOption("Properties", "Id", sf::Vector2f(200, 0));
	AddWindowOption("Properties", "Source", sf::Vector2f(200, 0));

	PackWidget("Options", "Load", sfg::Button::Create(WND_LOAD), std::bind(&ActionWindow::LoadTexture, action_));
	PackWidget("Options", "Remove", sfg::Button::Create("Remove"), std::bind(&ActionWindow::RemoveTexture, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseTextureLoading, action_));

	boxBody->Pack(box_["Properties"]);
	boxBody->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(boxBody);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 125, WND_SIZE.y / 2, 325, 50));
	window->Show(false);

	return window;
}