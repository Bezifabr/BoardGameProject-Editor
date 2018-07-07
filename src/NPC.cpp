/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// NPC.cpp
// Purpose: Contains NPC class methods accessing private variables.
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
#include "NPC.h"

NPC::Role NPC::GetRole()
{
	return role_;
}

void NPC::SetRole(Role role)
{
	role_ = role;
}

void NPC::SetRole(int role)
{
	role_ = static_cast<Role>(role);
}

void NPC::SetRole(std::string role)
{
	if (role == "Mercenary")
		role_ = NPC::Role::Mercenary;
	else if (role == "Trader")
		role_ = NPC::Role::Trader;
	else if (role == "Trainer")
		role_ = NPC::Role::Trainer;
	else
		role_ = NPC::Role::NoRole;
}

void NPC::SetType(Type type)
{
	type_ = type;
}

NPC::Type & NPC::GetType()
{
	return type_;
}

bool NPC::IsSelected()
{
	return isSelected_;
}

bool NPC::IsSelected(bool selected)
{
	bool bufor = isSelected_;
	isSelected_ = selected;
	return bufor;
}

sf::Text & NPC::GetHeader()
{
	return header_;
}

std::string NPC::GetItemLoot(int numberOfLoot)
{
	if (numberOfLoot > 0 && numberOfLoot <= 4)
		return lootItem_[numberOfLoot - 1];
	else
		std::cout << "NPC::GetItemLoot(): argument is invalid" << std::endl;
}

void NPC::ItemLoot(std::string lootItem, int numberOfLoot)
{
	if (!lootItem.empty() && numberOfLoot > 0 && numberOfLoot <= 4)
	{
		lootItem_[numberOfLoot - 1] = lootItem;
		dropAvaiable[numberOfLoot - 1] = true;
	}
	else
		std::cout << "NPC::ItemLoot(): argument is invalid" << std::endl;
}

void NPC::ItemLootRemove(int numberOfLoot)
{
	if (numberOfLoot > 0 && numberOfLoot <= 4)
	{
		lootItem_[numberOfLoot - 1].clear();
		dropAvaiable[numberOfLoot - 1] = false;
	}
	else
		std::cout << "NPC::ItemLootRemove(): argument is invalid" << std::endl;
}

void NPC::SetChanceOfLoot(int numberOfLoot, int percentage)
{
	if (percentage <= 100 && percentage > 0 && numberOfLoot >= 1 && numberOfLoot <= 4)
	{
		chanceOfLoot_[numberOfLoot - 1] = percentage;
	}
	else std::cout << "NPC::SetChanceOfLoot(): argument is invalid" << std::endl;
}

int NPC::GetChangeOfLoot(int numberOfLoot)
{
	if (numberOfLoot >= 1 && numberOfLoot <= 4) 
		return chanceOfLoot_[numberOfLoot - 1]; 
	else 
		std::cout << "NPC::GetChanceOfLoot(): argument is invalid" << std::endl;
}

void NPC::AddLoot(std::string lootItemID)
{
	if (numberOfLoots_ < 4)
	{
		numberOfLoots_++;
		ItemLoot(lootItemID, numberOfLoots_);
	}
}

void NPC::AddLootChance(int lootDropChance)
{
	if (numberOfLootChances_ < 4)
	{
		numberOfLootChances_++;
		SetChanceOfLoot(numberOfLootChances_, lootDropChance);
	}
}
