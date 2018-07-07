/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// GameObjects.cpp
// Purpose: Contains the definitions of Item, Skill and Effect classes containers.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include "GameObjects.h"
#include <iostream>
#include <exception>

bool GameObjects::AddItem(std::string key, Item item)
{
	if (items_.count(key) == 0)
	{
		items_[key] = item;
		itemsKeys_.push_back(key);
		return true;
	}
	
	std::cout << "GameObjects::AddItem(): key is occupied" << std::endl;
	return false;

}

bool GameObjects::ChangeItem(std::string key, Item item)
{
	if (items_.count(key) == 1)
	{
		items_[key] = item;
		return true;
	}
	std::cout << "GameObjects::ChangeItem(): item doesn't exist" << std::endl;
	return false;
}

bool GameObjects::RemoveItem(std::string key)
{
	if (items_.count(key) == 1)
	{
		items_.erase(key);

		if (!itemsKeys_.empty())
		{
			for (auto i = itemsKeys_.begin(); i != itemsKeys_.end(); i++)
				if (itemsKeys_[std::distance(itemsKeys_.begin(), i)] == key)
				{
					itemsKeys_.erase(i);
					break;
				}
		}


		return true;
	}
	std::cout << "GameObjects::RemoveItem(): item doesn't exist" << std::endl;
	return false; 
}

Item & GameObjects::GetItem(std::string key)
{
	if (items_.count(key) == 0)
	throw "GameObjects::GetItem(): Item doesn't exist";

	return items_[key];
}

bool GameObjects::AddSkill(std::string key, Skill skill)
{
	if (skills_.count(key) == 0)
	{
		skills_[key] = skill;
		skillsKeys_.push_back(key);
		return true;
	}

	std::cout << "GameObjects::AddSkill(): key is occupied" << std::endl;
	return false;

}

bool GameObjects::ChangeSkill(std::string key, Skill skill)
{

	if (skills_.count(key) == 1)
	{
		skills_[key] = skill;
		return true;
	}
	std::cout << "GameObjects::ChangeSkill(): skill doesn't exist" << std::endl;
	return false;
}

bool GameObjects::RemoveSkill(std::string key)
{
	if (skills_.count(key) == 1)
	{
		skills_.erase(key);	
		
		if (!skillsKeys_.empty())
		{
			for (auto i = skillsKeys_.begin(); i != skillsKeys_.end(); i++)
				if (skillsKeys_[std::distance(skillsKeys_.begin(), i)] == key)
				{
					skillsKeys_.erase(i);
					break;
				}
		}
		return true;
	}
	std::cout << "GameObjects::RemoveSkill(): skill doesn't exist" << std::endl;
	return false;

}

Skill & GameObjects::GetSkill(std::string key)
{
	if (skills_.count(key) == 0)
		throw "GameObjects::GetSkill(): Skill doesn't exist";

		return skills_[key];

}

bool GameObjects::AddEffect(std::string key, Effect effect)
{
	if (effects_.count(key) == 0)
	{
		effect.SetID(key);
		effects_[key] = effect;
		effectsKeys_.push_back(key);
		return true;
	}

	std::cout << "GameObjects::AddEffect(): key is occupied" << std::endl;
	return false;

}

bool GameObjects::ChangeEffect(std::string key, Effect effect)
{
	if (effects_.count(key) == 1)
	{
		effects_[key] = effect;
		effects_[key].SetID(key);

		return true;
	}
	std::cout << "GameObjects::ChangeEffect(): Effect doesn't exist" << std::endl;
	return false;
}

bool GameObjects::RemoveEffect(std::string key)
{
	if (effects_.count(key) == 1)
	{
		effects_.erase(key);
		RemoveEffectsKeys(key);
		return true;
	}
	std::cout << "GameObjects::RemoveEffect(): Effect doesn't exist" << std::endl;
	return false;
}



Effect& GameObjects::GetEffect(std::string key)
{
	if (effects_.count(key) == 0)
		throw "Effect doesn't exists";
	return effects_[key];
}

std::vector<std::string>& GameObjects::GetItemsKeys()
{
	if(itemsKeys_.empty())
	std::cout << "GameObjects::GetItemsKeys(): vector is empty" << std::endl;

	return itemsKeys_;
}

std::vector<std::string>& GameObjects::GetSkillsKeys()
{
	if (skillsKeys_.empty())
		std::cout << "GameObjects::GetSkillsKeys(): vector is empty" << std::endl;

	return skillsKeys_;
}

std::vector<std::string>& GameObjects::GetEffectsKeys()
{
	if (effectsKeys_.empty())
		std::cout << "GameObjects::GetEffectsKeys(): vector is empty" << std::endl;

	return effectsKeys_;
}

bool GameObjects::SetEffectID(std::string currentID, std::string newID)
{
	if (effects_.count(currentID) == 1)
	{
		effects_[currentID].SetID(newID);

		for (auto i = effectsKeys_.begin(); i != effectsKeys_.end(); i++)
			if (effectsKeys_[std::distance(effectsKeys_.begin(), i)] == currentID)
			{
				effectsKeys_[std::distance(effectsKeys_.begin(), i)] = newID;
				break;
			}

		return true;
	}
	return false;
}



bool GameObjects::SetSkillID(std::string currentID, std::string newID)
{
	if (skills_.count(currentID) == 1)
	{
		skills_[currentID].SetName(newID);

		for (auto i = skillsKeys_.begin(); i != skillsKeys_.end(); i++)
			if (skillsKeys_[std::distance(skillsKeys_.begin(), i)] == currentID)
			{
				skillsKeys_[std::distance(skillsKeys_.begin(), i)] = newID;
				break;
			}

		return true;
	}
	return false;
}

void GameObjects::SaveEffects()
{
	std::ofstream file;

	if (remove("Effects.txt") != 0)
		perror("Creating new file to save data");
	else
		puts("File found and prepared to save data");

	file.open("Effects.txt", std::ofstream::out | std::ofstream::trunc);

	for (auto itr = effects_.begin(), end = effects_.end(); itr != end; itr++)
	{
		file << "Effect{" << std::endl;
		
		file << "ID = " << itr->second.GetID() << std::endl;
		for (int i = 0; i <= itr->second.GetOrdersNumber() + 1; i++)
		{
			file << "Order = " << itr->second.GetFrontOrder() << std::endl;
			itr->second.PopOrder();
		}


		file << "}" << std::endl;
	}

	file.close();
}

void GameObjects::SaveItems()
{
	std::ofstream file;

	if (remove("Items.txt") != 0)
		perror("Creating new file to save data");
	else
		puts("File found and prepared to save data");

	file.open("Items.txt", std::ofstream::out | std::ofstream::trunc);

	for (auto itr = items_.begin(), end = items_.end(); itr != end; itr++)
	{
		file << "Item{" << std::endl;

		file << "ID = " << itr->second.GetID() << std::endl;
		file << "Name = " << itr->second.GetName() << std::endl;
		file << "Description = " << itr->second.GetDescription() << std::endl;
		file << "Icon = " << itr->second.GetIconTextureID() << std::endl;
		file << "Cooldown = " << itr->second.GetTimeOfCooldown() << std::endl;
		file << "Charges = " << itr->second.GetAmounOfCharges() << std::endl;
		file << "Price = " << itr->second.GetPrice() << std::endl;

		file << "IsTargetingAlly = " << ConvertToString(itr->second.IsTargetingAlly()) << std::endl;
		file << "IsTargetingEnemy = " << ConvertToString(itr->second.IsTargetingEnemy()) << std::endl;
		file << "IsTargetingSelf = " << ConvertToString(itr->second.IsTargetingSelf()) << std::endl;
		file << "IsUsingOnTarget = " << ConvertToString(itr->second.IsUsingOnTarget()) << std::endl;
		file << "IsUsingImmediately = " << ConvertToString(itr->second.IsUsingImmediately()) << std::endl;
		file << "IsUsable = " << ConvertToString(itr->second.IsUsable()) << std::endl;

		file << "}" << std::endl;
	}
}

void GameObjects::SaveSkills()
{
	std::ofstream file;

	if (remove("Skills.txt") != 0)
		perror("Creating new file to save data");
	else
		puts("File found and prepared to save data");

	file.open("Skills.txt", std::ofstream::out | std::ofstream::trunc);

	for (auto itr = skills_.begin(), end = skills_.end(); itr != end; itr++)
	{
		file << "Skill{" << std::endl;

		file << "ID = " << itr->second.GetID() << std::endl
			<< "Name = " << itr->second.GetName() << std::endl
			<< "Description = " << itr->second.GetDescription() << std::endl
			<< "Icon = " << itr->second.GetIconTextureID() << std::endl
			<< "Cooldown = " << std::to_string(itr->second.GetTimeOfCooldown()) << std::endl;
	
		file << "IsTargetingSelf = " << ConvertToString(itr->second.IsTargetingSelf()) << std::endl;
		file << "IsTargetingEnemy = " << ConvertToString(itr->second.IsTargetingEnemy()) << std::endl;
		file << "IsTargetingAlly = " << ConvertToString(itr->second.IsTargetingAlly()) << std::endl;
		file << "IsUseImmediately = " << ConvertToString(itr->second.IsUsingImmediately()) << std::endl;
		file << "IsUseOnTarget = " << ConvertToString(itr->second.IsUsingOnTarget()) << std::endl;
		file << "IsUsable = " << ConvertToString(itr->second.IsUsable()) << std::endl;
		
		file << "}" << std::endl;
	}
}

void GameObjects::LoadEffects()
{
	std::ifstream openFile("Effects.txt");
	if (openFile.is_open())
	{
		effects_.clear();
		effectsKeys_.clear();

		bool effectFound;
		Effect tempEffect;

		while (!openFile.eof())
		{
			std::string line;

			std::getline(openFile, line); //< Load line

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("Effect{") != std::string::npos)
				effectFound = true;


			if(effectFound == true)
				if (line.find("ID=") != std::string::npos || line.find("id=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);					
					tempEffect.SetID(line);
					std::cout << "ID(" << line << ")" << std::endl 
						<< "Orders: " << std::endl;
				}
				else if (line.find("Order=") != std::string::npos || line.find("order=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempEffect.PushOrder(line);
					std::cout << "- " << line << std::endl;
				}


			if (line.find("}") != std::string::npos)
			{
				AddEffect(tempEffect.GetID(), tempEffect);
				effectFound = false;
			}

		}
	}

}

void GameObjects::LoadItems()
{
	std::ifstream openFile("Items.txt");
	if (openFile.is_open())
	{
		items_.clear();
		itemsKeys_.clear();

		Item tempItem;
		bool itemFound;

		while (!openFile.eof())
		{
			std::string line;

			std::getline(openFile, line);

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());
			else if (line.find("Item{") != std::string::npos)
				itemFound = true;

			if (itemFound == true)
			{
				if(line.find("ID=") != std::string::npos)
					tempItem.SetID(LoadStringValue(line, "ID="));

				if(line.find("Name=") != std::string::npos)
					tempItem.SetName(LoadStringValue(line, "Name="));

				if(line.find("Description=") != std::string::npos)
					tempItem.SetDescription(LoadStringValue(line, "Description="));

				if (line.find("Icon=") != std::string::npos)
					tempItem.SetIconTextureID(LoadStringValue(line, "Icon="));

				if (line.find("Cooldown=") != std::string::npos)
					tempItem.SetTimeOfCooldown(LoadIntegerValue(line, "Cooldown="));

				if (line.find("Charges=") != std::string::npos)
					tempItem.SetAmountOfCharges(LoadIntegerValue(line, "Charges="));

				if (line.find("Price=") != std::string::npos)
					tempItem.SetPrice(LoadIntegerValue(line, "Price="));

				if (line.find("IsTargetingAlly=") != std::string::npos)
					tempItem.IsTargetingAlly(LoadBooleanValue(line, "IsTargetingAlly="));

				if (line.find("IsTargetingEnemy=") != std::string::npos)
					tempItem.IsTargetingEnemy(LoadBooleanValue(line, "IsTargetingEnemy="));

				if (line.find("IsTargetingSelf=") != std::string::npos)
					tempItem.IsTargetingSelf(LoadBooleanValue(line, "IsTargetingSelf="));

				if (line.find("IsUsingImmediately=") != std::string::npos)
					tempItem.IsUsingImmediately(LoadBooleanValue(line, "IsUsingImmediately="));

				if (line.find("IsUsingOnTarget=") != std::string::npos)
					tempItem.IsUsingOnTarget(LoadBooleanValue(line, "IsUsingOnTarget="));

				if (line.find("IsUsable=") != std::string::npos)
					tempItem.IsUsable(LoadBooleanValue(line, "IsUsable="));
			}

			if (line.find("}") != std::string::npos)
			{
				AddItem(tempItem.GetID(), tempItem);
				itemFound = false;
			}
		}
	}
}

void GameObjects::LoadSkills()
{
	std::ifstream openFile("Skills.txt");

	if (openFile.is_open())
	{

		items_.clear();
		itemsKeys_.clear();

		Skill tempSkill;
		bool skillFound;

		while (!openFile.eof())
		{
			std::string line;

			std::getline(openFile, line);

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());
			else if (line.find("Skill{") != std::string::npos)
				skillFound = true;
		
			if (skillFound == true)
			{
				if (line.find("ID=") != std::string::npos)
					tempSkill.SetID(LoadStringValue(line, "ID="));

				if(line.find("Name=") != std::string::npos)
				tempSkill.SetName(LoadStringValue(line, "Name="));

				if (line.find("Descr-tion=") != std::string::npos)
					tempSkill.SetDescription(LoadStringValue(line, "Description="));

				if(line.find("Icon=") !=std::string::npos)
				tempSkill.SetIconTextureID(LoadStringValue(line,"Icon="));

				if(line.find("Cooldown=") != std::string::npos)
				tempSkill.SetTimeOfCooldown(LoadIntegerValue(line, "Cooldown="));

				if(line.find("IsTargetingSelf=") != std::string::npos)
				tempSkill.IsTargetingSelf(LoadBooleanValue(line, "IsTargetingSelf="));

				if(line.find("IsTargetingEnemy=") != std::string::npos)
				tempSkill.IsTargetingEnemy(LoadBooleanValue(line, "IsTargetingEnemy="));

				if(line.find("IsTargetingAlly=") != std::string::npos)
				tempSkill.IsTargetingAlly(LoadBooleanValue(line, "IsTargetingAlly="));

				if(line.find("IsUseImmediately=") != std::string::npos)
				tempSkill.IsUsingImmediately(LoadBooleanValue(line, "IsUseImmediately="));

				if(line.find("IsUseOnTarget=")!=std::string::npos)
				tempSkill.IsUsingOnTarget(LoadBooleanValue(line, "IsUseOnTarget="));

				if(line.find("IsUsable=") != std::string::npos)
				tempSkill.IsUsable(LoadBooleanValue(line,"IsUsable="));
			
				if(line.find("}") != std::string::npos)
				{
					skillFound=false;
					AddSkill(tempSkill.GetID(), tempSkill);
				}
			}
		}
	}
}

bool GameObjects::DidItemExists(std::string key)
{
	if (items_.count(key) == 1)
		return true;
	std::cout << "GameObjects::DidItemExists(): Item doesn't exists" << std::endl;
	return false;
}

bool GameObjects::DidEffectExists(std::string key)
{
	if (effects_.count(key) == 1)
		return true;
	std::cout << "GameObjects::DidEffectExists(): Effect doesn't exists" << std::endl;
	return false;
}

bool GameObjects::DidSkillExists(std::string key)
{
	if (skills_.count(key) == 1)
		return true;
	std::cout << "GameObjects::DidSkillsExists(): Skill doesn't exists" << std::endl;
	return false;
}

int GameObjects::LoadIntegerValue(std::string textLine, std::string searchedCommand)
{
		textLine.erase(0, textLine.find('=') + 1);
		std::cout << searchedCommand << textLine << std::endl;
		return atoi(textLine.c_str());
}

std::string GameObjects::LoadStringValue(std::string textLine, std::string searchedCommand)
{
		textLine.erase(0, textLine.find('=') + 1);
		std::cout << searchedCommand << textLine << std::endl;
		return textLine;

}

bool GameObjects::LoadBooleanValue(std::string textLine, std::string searchedCommand)
{
		textLine.erase(0, textLine.find('=') + 1);
		std::cout << searchedCommand << textLine << std::endl;

		if(textLine == "True"||textLine == "true" || textLine == "1")
		return true;
	return false;
}

std::string GameObjects::ConvertToString(bool booleanVariable)
{
	if (booleanVariable == true)
		return "true";
	return "false";
}

std::string GameObjects::ConvertToString(int integerVariable)
{
	return std::to_string(integerVariable);
}

void GameObjects::RemoveEffectsKeys(std::string key)
{
	if (!effectsKeys_.empty())
	{
		for (auto i = effectsKeys_.begin(); i != effectsKeys_.end(); i++)
			if (effectsKeys_[std::distance(effectsKeys_.begin(), i)] == key)
			{
				effectsKeys_.erase(i);
				break;
			}
	}
	else std::cout << "GameObjects::RemoveEffectsKeys(): keys vector is empty" << std::endl;
}





bool GameObjects::SetItemID(std::string currentID, std::string newID)
{
	if (items_.count(currentID) == 1)
	{
		items_[currentID].SetName(newID);

		for (auto i = itemsKeys_.begin(); i != itemsKeys_.end(); i++)
			if (itemsKeys_[std::distance(itemsKeys_.begin(), i)] == currentID)
			{
				itemsKeys_[std::distance(itemsKeys_.begin(), i)] = newID;
				break;
			}

		return true;
	}
	return false;
}

