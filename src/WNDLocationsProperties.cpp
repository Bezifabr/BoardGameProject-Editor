/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDLocationsProperties.cpp
// Purpose: Contains definition of Create() method from WNDLocationsProperties class.
// Changes settings of current location.
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

sfg::Window::Ptr WNDLocationsProperties::Create()
{
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	auto boxHeader = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Navigation"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Properties"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);

	auto boxCameras = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);

	auto boxTitle = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	auto boxList = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	auto boxSettings = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	auto boxLocations = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	boxHeader->SetSpacing(5.f);
	box_["Navigation"]->SetSpacing(5.f);
	box_["Properties"]->SetSpacing(5.f);
	box_["Options"]->SetSpacing(5.f);
	boxCameras->SetSpacing(5.f);
	boxSettings->SetSpacing(5.f);
	boxBody->SetSpacing(5.f);

	label_["Title"] = sfg::Label::Create("Location name");
	boxHeader->Pack(label_["Title"]);

	PackWidget("Navigation", "Left", sfg::Button::Create("<<"), std::bind(&ActionWindow::LocPropLeft, action_));
	PackWidget("Navigation", "Create", sfg::Button::Create("+"), std::bind(&ActionWindow::LocPropCreate, action_));
	
	label_["Number"] = sfg::Label::Create("0");
	box_["Navigation"]->Pack(label_["Number"]);

	PackWidget("Navigation", "Remove", sfg::Button::Create("-"), std::bind(&ActionWindow::LocPropRemove, action_));
	PackWidget("Navigation", "Right", sfg::Button::Create(">>"), std::bind(&ActionWindow::LocPropRight , action_));


	box_["ID"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	
	AddWindowOption("Properties", "Name", sf::Vector2f(200, 10));
	label_["ID"] = sfg::Label::Create("ID");
	label_["ID"]->SetRequisition(sf::Vector2f(124, 0));
	auto FixedID = sfg::Fixed::Create();
	FixedID->Put(label_["ID"], sf::Vector2f(60, 0));
	box_["ID"]->Pack(FixedID, false, true);

	entry_["ID"] = sfg::Entry::Create();
	entry_["ID"]->SetRequisition(sf::Vector2f(150, 0));
	entry_["ID"]->SetState(sfg::Entry::State::INSENSITIVE);
	box_["ID"]->Pack(entry_["ID"]);

	PackWidget("ID", "ID", sfg::Button::Create("..."), std::bind(&ActionWindow::LocationMoveOpen, action_));
	box_["Properties"]->Pack(box_["ID"]);
	AddWindowOption("Properties", "Background", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Camera x", sf::Vector2f(200, 10));
	AddWindowOption("Properties", "Camera y", sf::Vector2f(200, 10));

	PackWidget("Options", "Ok", sfg::Button::Create("Ok"), std::bind(&ActionWindow::LocationPropertiesOk, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create("Cancel"), std::bind(&ActionWindow::CloseLocationProperties, action_));
	PackWidget("Options", "Apply", sfg::Button::Create("Apply"), std::bind(&ActionWindow::LocationPropertiesApply, action_));

	boxSettings->Pack(boxHeader);
	boxSettings->Pack(box_["Navigation"]);
	boxSettings->Pack(box_["Properties"]);
	boxSettings->Pack(box_["Options"]);

	boxLocations->Pack(boxTitle);
	boxLocations->Pack(boxList);

	boxBody->Pack(boxSettings);
	boxBody->Pack(boxLocations);


	auto window_ = sfg::Window::Create(sfg::Window::BACKGROUND);
	window_->Add(boxBody);
	window_->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 225, WND_SIZE.y / 2 - 125, 450, 100));
	window_->Show(false);  // Only for debug

	return window_;
}