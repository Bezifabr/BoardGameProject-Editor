/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDNPCInventory.cpp
// Purpose: Contains definition of Create() method from WND_NPC_Inventory class.
// Adds or removes items or loot.
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

sfg::Window::Ptr WND_NPC_Inventory::Create()
{
	box_["Body"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);

	box_["Options"]->SetSpacing(5.f);
	box_["Body"]->SetSpacing(5.f);


	PackWidget("Body", "Title", sfg::Label::Create(WND_NPC_INV_TITLE), std::bind(&ActionWindow::Nothing, action_));
	AddWindowOption("Body", "Slot_1", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Slot_2", sf::Vector2f(200, 0));

	entry_["Slot_1"]->SetRequisition(sf::Vector2f(260 - 280 / 3, 0));
	entry_["Slot_2"]->SetRequisition(sf::Vector2f(260 - 280 / 3, 0));

	AddWindowOption("Body", "Loot 1", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Loot 2", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Loot 3", sf::Vector2f(200, 0));
	AddWindowOption("Body", "Loot 4", sf::Vector2f(200, 0));

	for (int i = 1; i <= 4; i++)
	{
		entry_["Chance_"+to_string(i)] = sfg::Entry::Create();
		box_["Loot "+to_string(i)+"_Box"]->Pack(entry_["Chance_"+to_string(i)]);
	}


	PackWidget("Options", "Ok", sfg::Button::Create(WND_OK), std::bind(&ActionWindow::NPCInventoryOK, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseNPCInventory, action_));

	box_["Body"]->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::Style::BACKGROUND);
	window->Add(box_["Body"]);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 110, WND_SIZE.y / 2 - 200, 300, 100));
	window->Show(false);

	return window;
}