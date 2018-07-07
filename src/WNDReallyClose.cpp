/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDReallyClose.cpp
// Purpose: Contains definition of Create() method from WND_REALLY_CLOSE class.
// This dialog box appears when user trying to close program. It asks if he really want to leave.
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

sfg::Window::Ptr WND_REALLY_CLOSE::Create()
{
	box_["Body"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Title"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	
	box_["Title"]->SetSpacing(5.f);
	box_["Body"]->SetSpacing(5.f);
	box_["Options"]->SetSpacing(5.f);

	PackWidget("Title", "Title", sfg::Label::Create("Do you really want to quit without saving?"), std::bind(&ActionWindow::Nothing, action_));

	PackWidget("Options", "Yes", sfg::Button::Create("Yes"), std::bind(&Action::CloseAppWindow, action_));
	PackWidget("Options", "No", sfg::Button::Create("No"), std::bind(&ActionWindow::CloseReallyClose, action_));
	PackWidget("Options", "Save", sfg::Button::Create("Save"), std::bind(&ActionWindow::OpenSavingWindowReallyClose, action_));

	box_["Body"]->Pack(box_["Title"]);
	box_["Body"]->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(box_["Body"]);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 150, WND_SIZE.y / 2 - 100, 300, 70));
	window->Show(false);

	return window;
}