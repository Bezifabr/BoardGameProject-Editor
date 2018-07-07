/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDLoadMap.cpp
// Purpose: Contains definition of Create() method from WNDLoadMap class.
// Map loading dialog.
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

sfg::Window::Ptr WNDLoadMap::Create()
{
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Title"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);

	box_["Title"]->SetRequisition(sf::Vector2f(440, 50));
	box_["Title"]->SetSpacing(5.f);
	box_["Options"]->SetSpacing(5.f);
	boxBody->SetSpacing(5.f);

	auto labelTitle = sfg::Label::Create("Type source of map file");
	box_["Title"]->Pack(labelTitle);

	entry_["LoadMap"] = sfg::Entry::Create();
	entry_["LoadMap"]->SetRequisition(sf::Vector2f(200, 40));
	box_["Title"]->Pack(entry_["LoadMap"]);

	PackWidget("Options", "Yes", sfg::Button::Create(WND_LOAD), std::bind(&ActionWindow::LoadMap, action_));
	PackWidget("Options", "No", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseLoadMap, action_));
	
	boxBody->Pack(box_["Title"]);
	boxBody->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(boxBody);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 225, WND_SIZE.y / 2 - 125, 450, 100));
	window->Show(false);
	
	return window;
}