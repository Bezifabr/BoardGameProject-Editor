/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDNPCProperties.cpp
// Purpose: Contains definition of Create() method from WND_NPC_Properties class.
// Changes main values of NPC (name, role, level, etc.)
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

sfg::Window::Ptr WND_NPC_Properties::Create()
{
	box_["Body"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Body"]->SetSpacing(5.f);

	AddWindowOption("Body", NPC_WINDOW_ID, sf::Vector2f(200, 0));
	AddWindowOption("Body", NPC_WINDOW_NAME, sf::Vector2f(200, 0));
	AddWindowOption("Body", NPC_WINDOW_LEVEL, sf::Vector2f(200, 0));
	AddWindowOption("Body", NPC_WINDOW_TEXTURE, sf::Vector2f(200, 0));
	AddWindowCombo("Body", NPC_WINDOW_CLASS, sf::Vector2f(200, 0));
	AddWindowCombo("Body", NPC_WINDOW_ROLE, sf::Vector2f(200, 0));

	combo_[NPC_WINDOW_ROLE]->AppendItem("No Role");
	combo_[NPC_WINDOW_ROLE]->AppendItem("Mercenary");
	combo_[NPC_WINDOW_ROLE]->AppendItem("Trader");
	combo_[NPC_WINDOW_ROLE]->AppendItem("Trainer");

	PackWidget("Body", "SetStats", sfg::Button::Create(NPC_WINDOW_SET_STATS), std::bind(&ActionWindow::OpenNPCStats, action_));
	PackWidget("Body", "SetSpells", sfg::Button::Create(NPC_WINDOW_SET_SPELLS), std::bind(&ActionWindow::OpenNPCSpells, action_));
	PackWidget("Body", "SetArmor", sfg::Button::Create(NPC_WINDOW_SET_ARMOR), std::bind(&ActionWindow::OpenNPCArmor, action_));
	PackWidget("Body", "SetInventory", sfg::Button::Create(NPC_WINDOW_SET_INVENTORY), std::bind(&ActionWindow::OpenNPCInventory, action_));
	PackWidget("Body", "SetPosition", sfg::Button::Create(NPC_WINDOW_SET_POSITION), std::bind(&ActionWindow::OpenNPCPosition, action_));

	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Options"]->SetSpacing(5.f);

	PackWidget("Options", "Create", sfg::Button::Create(WND_OK), std::bind(&ActionWindow::NPCPropertiesOK, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(NPC_WINDOW_CANCEL), std::bind(&ActionWindow::CloseNPCProperties, action_));

	box_["Body"]->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(box_["Body"]);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 110, WND_SIZE.y / 2 - 200, 300, 100));
	window->Show(false);

	return window;
}