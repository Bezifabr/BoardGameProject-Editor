/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Character.h
// Purpose: Contains Character class inherited by NPCs and Players
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
#include "AnimatedObj.h"
#include <string>

class Character : public Animated
{
public:
	virtual ~Character() {};
		
	enum SpellsFuelType
	{
		Mana,
		Rage,
		Focus,
	};
	
	SpellsFuelType GetSpellFuelType() { return spellFuelType_; }
	void SetSpellFuelType(SpellsFuelType type) { spellFuelType_ = type; }
	void SetSpellFuelType(std::string type);

	const std::string& GetName() { return name_; }

	/////////////////////
	/// Returns level of character
	///
	/// \return level_ integer value
	///
	/////////////////////
	int GetLevel() { return level_; }

	/////////////////////
	/// Returns position of character
	/// This position is not coordinates of world but number of field on which character stand
	///
	/// \return position_ integer value
	///
	/////////////////////
	int GetPosition() { return position_; }

	/////////////////////
	/// Returns strength of character
	///
	/// \return strength_ integer value
	///
	/////////////////////
	int GetStrength() { return strength_; }

	/////////////////////
	/// Returns agility of character
	///
	/// \return agility_ integer value
	///
	/////////////////////
	int GetAgility() { return agility_; }
	
	/////////////////////
	/// Returns endurance of character
	///
	/// \return endurance_ integer value
	///
	/////////////////////
	int GetEndurance() { return endurance_; }

	/////////////////////
	/// Returns speed of character
	///
	/// \return speed_ integer value
	///
	/////////////////////
	int GetSpeed() { return speed_; }
	
	/////////////////////
	/// Returns intelligence of character
	///
	/// \return intelligence_ integer value
	///
	/////////////////////
	int GetIntelligence() { return intelligence_; }
	
	/////////////////////
	/// Returns will power of character
	/// 
	/// \return willPower_ integer value
	///
	/////////////////////
	int GetWillPower() { return willPower_; }
	
	/////////////////////
	/// Returns damage of character
	/// Damage - enemy's armor = lost of his health
	///
	/// \return damage_ integer value
	///
	/////////////////////
	int GetDamage() { return damage_; }

	/////////////////////
	/// Returns spell fuel of character
	/// Spell fuel is what character need to cast spells
	///
	/// \return spellFuel_ integer value
	///
	/////////////////////
	int GetSpellFuel() { return spellFuel_; }

	/////////////////////
	/// Returns max value of health
	/// It's maximum value of character's health so he can be healed only to this value
	/// Current health can't be higher than maximum health
	///
	/// \return maxHealthPoints_ integer value
	///
	/////////////////////
	int GetHealthPointsMax() { return maxHealthPoints_; }

	/////////////////////
	/// Returns health of character
	/// When health value falls under 0 character dies
	///
	/// \return  healthPoints_ integer value
	///
	/////////////////////
	int GetHealthPoints() { return healthPoints_; }

	/////////////////////
	/// Returns max value of spell fuel
	/// Spell fuel is what character needs to cast spells
	/// Current spell fuel can't be higher than maximum spell fuel
	///
	/// \return maxSpellFuel_ integer value
	///
	/////////////////////
	int GetMaxSpellFuel() { return maxSpellFuel_; }

	/////////////////////
	/// Returns character's armor of choosen type
	/// Armor absorbs enemy's damage
	/// It has lots of types (cutting, crushing, piercing, magical)
	/// Every type of armor absords other damage types
	/// For Example. piercing damage will ignore magical armor
	///
	/// \param armorType - type of armor of which value is what looking for
	/// \return armor integer value
	///
	/////////////////////
	int GetArmor(std::string armorType);

	/////////////////////
	/// Returns character's spell selected by its id
	/// 
	/// \param spellNumber - id of spell (1-6)
	/// \return spell from spell_ array
	///
	/////////////////////
	std::string GetSpell(int spellNumber);
	
	/////////////////////
	/// Returns character's item selected by its id
	///
	/// \param slotNumber - id of item (1-2)
	/// \return item from itemSlot_ array
	///
	/////////////////////
	std::string GetItem(int slotNumber);
	
	/////////////////////
	/// Changes character's position
	/// This position is not coordinates of world but number of field on which character stand
	///
	/// \param position - integer value of new character's position
	///
	/////////////////////
	void SetPosition(int position) { position_ = position; }

	/////////////////////
	/// Changes character's name
	/// Name is shown in game
	///
	/// \param name - reference to string value of new character's name
	/// parameter is const so original value can't be changed here
	///
	/////////////////////
	void SetName(const std::string& name);

	/////////////////////
	/// Changes character's level
	///
	/// \param level - integer value of new character's level
	///
	/////////////////////
	void SetLevel(int level);

	/////////////////////
	/// Changes character's strength
	///
	/// \param strength - integer value of new character's strength
	///
	/////////////////////
	void SetStrength(int strength);

	/////////////////////
	/// Changes character's agility
	///
	/// \param agility - integer value of new character's agility
	///
	/////////////////////
	void SetAgility(int agility);

	////////////////////
	/// Changes character's endurance
	///
	/// \param endurance - integer value of new character's endurance
	///
	////////////////////
	void SetEndurance(int endurance);

	////////////////////
	/// Changes character's speed
	///
	/// \param speed - integer value of new character's speed
	///
	////////////////////
	void SetSpeed(int speed);

	////////////////////
	/// Changes character's intelligence
	///
	/// \param intelligence - integer value of new character's intelligence
	///
	////////////////////
	void SetIntelligence(int intelligence);

	////////////////////
	/// Changes character's damage
	/// This position is not coordinates of world but number of field on which character stand
	///
	/// \param damage - integer value of new character's damage
	///
	////////////////////
	void SetDamage(int damage);
	
	////////////////////
	/// Changes character's spell fuel
	/// Spell fuel is what character needs to cast spells
	/// Current spell fuel can't be higher than maximum spell fuel
	///
	/// \param spellFuel - integer value of new character's spell fuel
	///
	////////////////////
	void SetSpellFuel(int spellFuel);

	////////////////////
	/// Changes character's maximum spell fuel
	/// Spell fuel is what character needs to cast spells
	/// Current spell fuel can't be higher than maximum spell fuel
	///
	/// \param spellFuel - integer value of new character's spell fuel
	///
	////////////////////
	void SetMaxSpellFuel(int spellFuel);
	
	////////////////////
	/// Changes character's maximum health
	/// It's maximum value of character's health so he can be healed only to this value
	/// Current health can't be higher than maximum health
	///
	/// \param healthPoints - integer value of new character's maximum health points value
	///
	////////////////////
	void SetHealthPointsMax(int maxHealthPoints);

	////////////////////
	/// Changes character's health
	/// When health value falls under 0 character dies
	///
	/// \param healthPointer - integer value of new character's health points value
	///
	////////////////////
	void SetHealthPoints(int healthPoints);

	////////////////////
	/// Changes character's will power
	///
	/// \param willPower - integer value of new chracter's will power
	///
	////////////////////
	void SetWillPower(int willPower);
	
	////////////////////
	/// Adds new spell to character 
	/// Checks if number of spells is less than 4
	/// Uses numberOfSpells_ variable to count amount of character's spells
	/// Calls SetSpell() method
	///
	/// \param spellID - ID of spell
	///
	////////////////////
	void AddSpell(std::string spellID);

	////////////////////
	/// Adds new spell to character's spell slot
	///
	/// \pararm spellID - ID of spell
	/// \param spellNumber - number of spell slot	
	///
	////////////////////
	void SetSpell(std::string spellID, int spellNumber);

	////////////////////
	/// Sets value of armor
	/// Armor absorbs enemy's damage
	/// It has lots of types (cutting, crushing, piercing, magical)
	/// Every type of armor absords other damage types
	/// For Example. piercing damage will ignore magical armor
	///
	/// \param armorValue - integer type value of armor
	/// \param armorType - string type type of armor
	///
	/// \Types of armor:
	/// - Cutting
	/// - Crushing
	/// - Piercing
	/// - Magical
	///
	////////////////////
	void SetArmor(int armorValue, std::string armorType);
	
	////////////////////
	/// Adds item to character's item slot
	///
	/// \param itemID - ID of new item
	/// \param slotNumber - number of item slot
	///
	////////////////////
	void ItemSlot(std::string itemID, int slotNumber);
	
	////////////////////
	/// Adds item to character's item slot
	/// Checks if numberOfItems_ variable value is less than 2 (counting from 0)
	/// Calls ItemSlot() method
	///
	/// \param itemID - ID of new item
	///
	////////////////////
	void AddItem(std::string itemID);
	void Die();
private:
	std::string spell_[6];
	std::string itemSlot_[2];

	uint8_t numberOfSpells_;
	uint8_t numberOfItems_;

	SpellsFuelType spellFuelType_;

	std::string name_;

	int damage_;

	int level_;
	int healthPoints_;
	int spellFuel_;
	
	int maxHealthPoints_;
	int maxSpellFuel_;


	int willPower_;
	int strength_;
	int agility_;
	int endurance_;
	int speed_;		
	int intelligence_;

	int cuttingArmor_;
	int crushingArmor_;
	int piercingArmor_;
	int magicalArmor_;


	int position_; // Fields order
};