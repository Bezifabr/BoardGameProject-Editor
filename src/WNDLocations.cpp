/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDLocations.cpp
// Purpose: Contains definition of Create() method from WNDLocations class.
// Window with operations on locations (moving, creating, removing).
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

sfg::Window::Ptr WNDLocations::Create()
{
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Header"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Navigator"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	
	box_["Header"]->SetRequisition(sf::Vector2f(190, 35));
	box_["Header"]->SetSpacing(5.f);
	box_["Navigator"]->SetRequisition(sf::Vector2f(140, 20));
	box_["Navigator"]->SetSpacing(5.f);
	boxBody->SetSpacing(5.f);
	
	label_["Name"] = sfg::Label::Create(DEFAULT_LOCATION_NAME);
	box_["Header"]->Pack(label_["Name"]);
	
	label_["Number"] = sfg::Label::Create(DEFAULT_LOCATION_NUMBER);
	box_["Header"]->Pack(label_["Number"]);
	
	auto buttonLeft = sfg::Button::Create("<<");
	auto buttonRight = sfg::Button::Create(">>");
	auto buttonCreate = sfg::Button::Create("+");
	auto buttonRemove = sfg::Button::Create("-");
	
	if (action_)
	{
		PackWidget("Navigator", "Left", sfg::Button::Create("<<"), std::bind(&ActionWindow::PreviousLocation, action_));
		PackWidget("Navigator", "Create", sfg::Button::Create("+"), std::bind(&ActionWindow::CreateLocation, action_));
		PackWidget("Navigator", "Remove", sfg::Button::Create("-"), std::bind(&ActionWindow::DeleteLocation, action_));
		PackWidget("Navigator", "Right", sfg::Button::Create(">>"), std::bind(&ActionWindow::NextLocation, action_));
		PackWidget("Navigator", "Settings", sfg::Button::Create("..."), std::bind(&ActionWindow::OpenLocationProperties, action_));
	}
	else std::cout << "ERROR: ACTION IS NOT LOADED" << std::endl;

	
	boxBody->Pack(box_["Header"]);
	boxBody->Pack(box_["Navigator"]);
	
	auto window_ = sfg::Window::Create(sfg::Window::BACKGROUND);
	window_->Add(boxBody);
	window_->SetAllocation(sf::FloatRect(WND_SIZE.x - 250, 50, 200, 50));
	window_->Show(true);


	return window_;
}