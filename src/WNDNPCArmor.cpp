/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDNPCArmor.cpp
// Purpose: Contains definition of Create() method from WND_NPC_Armor class.
// Changes value of NPC's armor.
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

sfg::Window::Ptr WND_NPC_Armor::Create()
{
	box_["Body"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Options"]->SetSpacing(5.f);
	box_["Body"]->SetSpacing(5.f);

	PackWidget("Body", "Title", sfg::Label::Create(WND_NPC_ARMOR_TITLE), std::bind(&ActionWindow::Nothing, action_));
	AddWindowOption("Body", "Piercing", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Cut", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Crushing", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Magical", sf::Vector2f(200, 0));

	PackWidget("Options", "Ok", sfg::Button::Create(WND_OK), std::bind(&ActionWindow::NPCArmorOK, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseNPCArmor, action_));

	box_["Body"]->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(box_["Body"]);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 110, WND_SIZE.y / 2 - 200, 300, 100));
	window->Show(false);

	return window;
}