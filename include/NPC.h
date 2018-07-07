/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// NPC.h
// Purpose: Contains NPC class derived from Character base class.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////
#pragma once

////////////////////
// HEADERS
////////////////////
#include "Character.h"

class NPC : public Character
{
public:

	enum Type
	{
		Human,
		Monster,
	};

	enum Role
	{
		NoRole,
		Mercenary,
		Trader,
		Trainer,
		//TODO: add more later
	};

	///////////////////////////
	/// Returns role of NPC
	///
	///////////////////////////
	Role GetRole();

	///////////////////////////
	/// Sets role of NPC
	///
	/// \param role - NPC::Role type enumeration of role
	///
	///////////////////////////
	void SetRole(Role role);

	///////////////////////////
	/// Sets role of NPC
	///
	/// \param role - int type enumeration of role
	///
	///////////////////////////
	void SetRole(int role);

	///////////////////////////
	/// Sets role of NPC
	///
	/// \param role - int type enumeration of role
	///
	///////////////////////////
	void SetRole(std::string role);

	///////////////////////////
	/// Sets type of NPC
	///
	/// \param type - Type of NPC
	///
	////////////////////////////
	void SetType(Type type);
	
	////////////////////////////
	/// Returns type of NPC
	///
	////////////////////////////
	Type& GetType();

	/////////////////////////////
	/// Returns true if NPC is selected
	///
	/////////////////////////////
	bool IsSelected();

	/////////////////////////////
	/// Sets isSelected boolean value
	///
	/// \param selected - new boolean value of isSelected_ variable
	/// \return previous value of isSelected_ variable
	///
	/////////////////////////////
	bool IsSelected(bool selected);

	/////////////////////////////
	/// Returns header of NPC
	/// (visible only in editor)
	///
	/////////////////////////////
	sf::Text& GetHeader();

	/////////////////////////////
	/// Returns id of loot item
	///
	/// \param numberOfLoot - id of loot slot (1-4)
	///
	/////////////////////////////
	std::string GetItemLoot(int numberOfLoot);

	////////////////////////////
	/// Sets id of item type to loot
	///
	/// \param lootItem - id of item type
	/// \param numberOfLoot - id of loot slot (1-4)
	///
	////////////////////////////
	void ItemLoot(std::string lootItem, int numberOfLoot);

	////////////////////////////
	/// Remove item from loot slot
	///
	/// \param numberOfLoot - id of loot slot (1-4)
	///
	////////////////////////////
	void ItemLootRemove(int numberOfLoot);

	////////////////////////////
	/// Set chance of loot droping
	///
	/// \param numberOfLoot - id of loot slot
	/// \param percentage - percent of chance to drop loot
	///
	////////////////////////////
	void SetChanceOfLoot(int numberOfLoot, int percentage);

	////////////////////////////
	/// Returns chance of loot droping
	///
	/// \param numberOfLoot - id of loot slot
	///
	////////////////////////////
	int GetChangeOfLoot(int numberOfLoot);

	///////////////////////////
	/// Adds new loot
	/// Checks if number of loots is less then 4
	/// Uses numberOfLoots_ variable to count number of loots in NPC inventory
	///
	/// \param lootItemID - ID of loot item
	///
	///////////////////////////
	void AddLoot(std::string lootItemID);

	///////////////////////////
	/// Adds chance to be dropped to just added loot
	/// Checks if number of loot chances is less then 4
	/// It uses numberOfLootChances_ variable to count number of loots chances already set.
	/// Chances are assigned to loots in same order as in AddLoot() method
	///
	/// \param lootDropChance - Chance of loot to be dropped by killed NPC
	///
	///////////////////////////
	void AddLootChance(int lootDropChance);
private:

	uint8_t numberOfLoots_;
	uint8_t numberOfLootChances_;

	Role role_;
	Type type_;

	bool isSelected_;

	sf::Text header_;

	std::string lootItem_[4];
	// Devides between all loot items.
	int chanceOfLoot_[4] = { 0,0,0,0 };
	bool dropAvaiable[4] = { false,false,false,false };
};

