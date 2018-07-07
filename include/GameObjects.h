/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// GameObjects.cpp
// Purpose: Contains the Item, Skill and Effect classes containers.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////


#pragma once
#include "Item.h"

class GameObjects
{
public:
	GameObjects()
	{
	}

	~GameObjects()
	{
	}

	///////////////////
	/// Adds new item to items container
	/// Checks if item key isn't in use
	///
	/// \param key - String type argument. Key of item in the map container
	/// \param item - Item type argument. New Item object.
	/// \return true if item has been successfully added
	///
	///////////////////
	bool AddItem(std::string key, Item item);

	///////////////////
	/// Changes existing item
	/// 
	/// \param key - String type argument. Key of item in the map container.
	/// \param item - Item type argument. New Item object.
	/// \return true if item has been successfully changed
	///
	///////////////////
	bool ChangeItem(std::string key, Item item);

	///////////////////
	/// Removes existing item from the map container
	///
	/// \param key - String type argument. Key of item in the map container.
	/// \return true if item has been successfully removed
	///
	///////////////////
	bool RemoveItem(std::string key);
	
	///////////////////
	/// Returns const reference of Item from container
	/// It's not copy but it can't be changed due to const attribute.
	///
	/// \param key - String type argument. Key of item in the map container.
	/// \return reference of selected Item object 
	///
	///////////////////
	Item& GetItem(std::string key);

	///////////////////
	/// Adds new skill to skills container
	/// Checks if skill key isn't in use
	///
	/// \param key - String type argument. Key of skill in the map container
	/// \param skill - Skill type argument. New skill object.
	/// \return true if skill has been successfully added
	///
	///////////////////
	bool AddSkill(std::string key, Skill skill);
	
	///////////////////
	/// Changes existing skill
	/// 
	/// \param key - String type argument. Key of skill in the map container.
	/// \param skill - Skill type argument. New Skill object.
	/// \return true if skill has been successfully changed
	///
	///////////////////
	bool ChangeSkill(std::string key, Skill skill);

	///////////////////
	/// Removes existing skill from the map container
	///
	/// \param key - String type argument. Key of skill in the map container.
	/// \return true if skill has been successfully removed
	///
	///////////////////
	bool RemoveSkill(std::string key);
	
	///////////////////
	/// Returns const reference of Skill from container
	/// It's not copy but it can't be changed due to const attribute.
	///
	/// \param key - String type argument. Key of skill in the map container.
	/// \return constant reference of selected Skill object 
	///
	///////////////////
	Skill& GetSkill(std::string key);
	
	///////////////////
	/// Adds new skill to effects container
	/// Checks if effect key isn't in use
	///
	/// \param key - String type argument. Key of effect in the map container
	/// \param effect - Effect type argument. New Effect object.
	/// \return true if effect has been successfully added
	///
	///////////////////
	bool AddEffect(std::string key, Effect effect);
	
	///////////////////
	/// Changes existing effect
	/// 
	/// \param key - String type argument. Key of effect in the map container.
	/// \param effect - Effect type argument. New Effect object.
	/// \return true if effect has been successfully changed
	///
	///////////////////
	bool ChangeEffect(std::string key, Effect effect);
	
	///////////////////
	/// Removes existing effect from the map container
	///
	/// \param key - String type argument. Key of effect in the map container.
	/// \return true if effect has been successfully removed
	///
	///////////////////
	bool RemoveEffect(std::string key);

	///////////////////
	/// Returns const reference of Effect from container
	/// It's not copy but it can't be changed due to const attribute.
	///
	/// \param key - String type argument. Key of effect in the map container.
	/// \return constant reference of selected Effect object 
	///
	///////////////////
	Effect& GetEffect(std::string key);

	std::vector<std::string>& GetItemsKeys();
	std::vector<std::string>& GetSkillsKeys();
	std::vector<std::string>& GetEffectsKeys();

	bool SetEffectID(std::string currentID, std::string newID);
	bool SetItemID(std::string currentID, std::string newID);
	bool SetSkillID(std::string currentID, std::string newID);

	void SaveEffects();
	void SaveItems();
	void SaveSkills();

	void LoadEffects();
	void LoadItems();
	void LoadSkills();

	bool DidItemExists(std::string key);
	bool DidEffectExists(std::string key);
	bool DidSkillExists(std::string key);

private:
	
	int LoadIntegerValue(std::string textLine, std::string searchedCommand);
	std::string LoadStringValue(std::string textLine, std::string searchedCommand);
	bool LoadBooleanValue(std::string textLine, std::string searchedCommand);

	std::string ConvertToString(bool booleanVariable);
	std::string ConvertToString(int integerVariable);


	std::vector<std::string> itemsKeys_;
	std::vector<std::string> skillsKeys_;
	std::vector<std::string> effectsKeys_;

	std::map<std::string, Item> items_;
	std::map<std::string, Skill> skills_;
	std::map<std::string, Effect> effects_;

	void RemoveEffectsKeys(std::string key);
};