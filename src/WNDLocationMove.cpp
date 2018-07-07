/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDLocationMove.cpp
// Purpose: Contains definition of Create() method from WNDLocationMove class.
// Dialog that moves or replaces location position.
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

sfg::Window::Ptr WNDLocationMove::Create()
{
	box_["Current"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Next"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	box_["Current"]->SetSpacing(5.f);
	box_["Next"]->SetSpacing(5.f);
	box_["Options"]->SetSpacing(5.f);
	boxBody->SetSpacing(5.f);

	box_["Current"]->SetRequisition(sf::Vector2f(425, 30));
	box_["Next"]->SetRequisition(sf::Vector2f(425, 30));

	label_["Current"] = sfg::Label::Create(WND_CURRENT_LOCATION);
	label_["Current"]->SetRequisition(sf::Vector2f(150, 30));
	box_["Current"]->Pack(label_["Current"]);

	label_["Next"] = sfg::Label::Create(WND_CURRENT_LOCATION);
	label_["Next"]->SetRequisition(sf::Vector2f(150, 30));
	box_["Next"]->Pack(label_["Next"]);

	entry_["Current"] = sfg::Entry::Create();
	entry_["Current"]->SetState(sfg::Entry::State::INSENSITIVE);
	entry_["Current"]->SetRequisition(sf::Vector2f(200, 25));
	box_["Current"]->Pack(entry_["Current"]);

	entry_["Next"] = sfg::Entry::Create();
	entry_["Next"]->SetRequisition(sf::Vector2f(200, 25));
	box_["Next"]->Pack(entry_["Next"]);


	PackWidget("Options", "Move", sfg::Button::Create(LOC_MOVE), std::bind(&ActionWindow::LocationMove, action_));
	PackWidget("Options", "MoveLocation_Replace", sfg::Button::Create(LOC_REPLACE), std::bind(&ActionWindow::LocationReplace, action_));
	PackWidget("Options", "MoveLocation_Close", sfg::Button::Create(LOC_CLOSE), std::bind(&ActionWindow::LocationMoveClose, action_));

	boxBody->Pack(box_["Current"]);
	boxBody->Pack(box_["Next"]);
	boxBody->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(boxBody);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 225, WND_SIZE.y / 2 + 125, 400, 100));
	window->Show(false);

	return window;

}