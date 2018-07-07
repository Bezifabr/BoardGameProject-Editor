/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Character.cpp
// Purpose: Contains definitions of methods from Character class inherited by NPCs and Players
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
#include "Character.h"
#include "Constants.h"
#include <iostream>


void Character::SetSpellFuelType(std::string type)
{
	if (type == "Mana")
		spellFuelType_ = SpellsFuelType::Mana;
	else if (type == "Rage")
		spellFuelType_ = SpellsFuelType::Rage;
	else if (type == "Focus")
		spellFuelType_ = SpellsFuelType::Focus;
}

int Character::GetArmor(std::string armorType)
{
	if (!armorType.empty())
	{
		if (armorType == "Cutting" || armorType == "cutting")
			return cuttingArmor_;
		else if (armorType == "Crushing" || armorType == "crushing")
			return crushingArmor_;
		else if (armorType == "Piercing" || armorType == "piercing")
			return piercingArmor_;
		else if (armorType == "Magical" || armorType == "magical")
			return magicalArmor_;
	}
	std::cout << "Character::GetArmor: argument is invalid" << std::endl;
}

std::string Character::GetSpell(int spellNumber)
{
	if (spellNumber <= 6 && spellNumber > 0)
		return spell_[spellNumber];
	else
		std::cout << "Character::GetSpell(): argument is invalid" << std::endl;
}

std::string Character::GetItem(int slotNumber)
{
	if (slotNumber == 1 || slotNumber == 2)
		if (!itemSlot_[slotNumber].empty() && !itemSlot_->empty())
			return itemSlot_[slotNumber];
		else
		{
			std::cout << "Character::GetItem(): Slot is empty" << std::endl;
			return "";
		}
	 else 
		 std::cout << "Character::GetItem(): argument is invalid" << std::endl; 
}

void Character::SetName(const std::string & name)
{
	if (!name.empty())
	{
		name_ = name;
	}
	else
		std::cout << "Character::SetName(): argument is invalid" << std::endl;
}

void Character::SetLevel(int level)
{
	if (level <= MAX_LEVEL && level > 0)
	{
		level_ = level;
	}
	else
		std::cout << "Character::SetLevel(): argument is invalid" << std::endl;
}

void Character::SetStrength(int strength)
{
	if (strength <= MAX_STRENGTH && strength > 0)
	{
		strength_ = strength;
	}
	else
		std::cout << "Character::SetStrength(): argument is invalid" << std::endl;
}

void Character::SetAgility(int agility)
{
	if (agility <= MAX_AGILITY && agility > 0)
	{
		agility_ = agility;
	}
	else
		std::cout << "Character::SetAgility(): argument is invalid" << std::endl;
}

void Character::SetEndurance(int endurance)
{
	if (endurance <= MAX_ENDURANCE && endurance > 0)
	{
		endurance_ = endurance;
	}
	else
		std::cout << "Character::SetEndurance(): argument is invalid" << std::endl;
}

void Character::SetSpeed(int speed)
{
	if (speed <= MAX_SPEED && speed > 0)
	{
		speed_ = speed;
	}
	else
		std::cout << "Character::SetSpeed(): argument is invalid" << std::endl;
}

void Character::SetIntelligence(int intelligence)
{
	if (intelligence <= MAX_INTELLIGENCE && intelligence > 0)
	{
		intelligence_ = intelligence;
	}
	else
		std::cout << "Character::SetIntelligence(): argument is too invalid" << std::endl;
}

void Character::SetDamage(int damage)
{
	if (damage <= MAX_DAMAGE && damage > 0)
	{
		damage_ = damage;
	}
	else
		std::cout << "Character::SetDamage(): argument is invalid" << std::endl;
}

void Character::SetSpellFuel(int spellFuel)
{
	if (spellFuel <= MAX_SPELL_FUEL && spellFuel > 0)
	{
		spellFuel_ = spellFuel;
	}
	else
		std::cout << "Character::SetSpellFuel(): argument is invalid" << std::endl;
}

void Character::SetMaxSpellFuel(int spellFuel)
{
	if (spellFuel <= MAX_SPELL_FUEL && spellFuel > 0)
	{
		maxSpellFuel_ = spellFuel;
	}
	else
		std::cout << "Character::SetMaxSpellFuel(): argument is invalid" << std::endl;
}

void Character::SetHealthPointsMax(int maxHealthPoints)
{
	if (maxHealthPoints <= MAX_HEALTH && maxHealthPoints > 0)
	{
		maxHealthPoints_ = maxHealthPoints;
	}
	else
		std::cout << "Character::SetHealthPointsMax(): argument is invalid" << std::endl;
}

void Character::SetHealthPoints(int healthPoints)
{
	if (healthPoints <= MAX_HEALTH)
	{
		healthPoints_ = healthPoints;
		if (healthPoints_ < 0)
			Die();
	}
	else
		std::cout << "Character::SetHealthPoints(): argument is invalid" << std::endl;
}

void Character::SetWillPower(int willPower)
{
	if (willPower <= MAX_WILLPOWER && willPower > 0)
	{
		willPower_ = willPower;
	}
	else
		std::cout << "Character::SetWillPower(): argument is invalid" << std::endl;
}

void Character::AddSpell(std::string spellID)
{
	if (numberOfSpells_ < 4)
	{
		numberOfSpells_++;
		SetSpell(spellID, numberOfSpells_);
	}
}

void Character::SetSpell(std::string spellID, int spellNumber)
{
	if (!spellID.empty() && spellNumber >= 0 && spellNumber < 6)
	{
		// TODO: Check if spell exists
		spell_[spellNumber] = spellID;
	}
	else std::cout << "Character::SetSpell(): argument is invalid" << std::endl;
}

void Character::SetArmor(int armorValue, std::string armorType)
{
	if (armorValue <= MAX_ARMOR && armorValue > 0 && !armorType.empty())
	{
		if (armorType == "Cutting")
			cuttingArmor_ = armorValue;
		else if (armorType == "Crushing")
			crushingArmor_ = armorValue;
		else if (armorType == "Piercing")
			piercingArmor_ = armorValue;
		else if (armorType == "Magical")
			magicalArmor_ = armorValue;
	}
	else std::cout << "Character::SetArmor(): argument is invalid" << std::endl;
}

void Character::ItemSlot(std::string itemID, int slotNumber)
{
	if (slotNumber == 0 || slotNumber == 1)
		if (!itemID.empty())
		{
			itemSlot_[slotNumber] = itemID;
		}
		else std::cout << "Character::ItemSlot(): argument is empty" << std::endl;
	else std::cout << "Character::ItemSlot(): wrong slot number" << std::endl;
}

void Character::AddItem(std::string itemID)
{
	if (numberOfItems_ < 2)
	{
		numberOfItems_++;
		ItemSlot(itemID, numberOfItems_);
	}
}

void Character::Die()
{
	std::cout << name_ << "died" << std::endl;
}
