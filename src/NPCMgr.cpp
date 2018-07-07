/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// NPCMgr.cpp
// Purpose: Handles operations on the NPCs
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
#include "NPCMgr.h"

void NPCMgr::Update()
{
	if (canClick_ == true)
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clickTimer_.getElapsedTime().asMilliseconds() > 150)
		{
			clickTimer_.restart();
			canClick_ = false;
			PlaceNPC();
			SelectNPC();
		}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		canClick_ = true;

		if (isNPCGrabbed_ == true)
			isNPCGrabbed_ = false;
	}

	if (input_->RMBReleased())
	{
		UnselectNPC();
	}

	DeleteNPC();
	MoveNPC();
	ChangeTool();
	GUIUpdate();
}

void NPCMgr::AddNPCType(std::string type)
{
	if (npcsBar_.size() <= 10)
	{
		currentNPC_.SetName(type);
		data_->LoadTexture("NPC_" + type, "Graphics/NPC/" + type + ".png");
		currentNPC_.GetSprite().setTexture(data_->GetTexture("NPC_" + type));
		currentNPC_.SetTextureID("NPC_" + type);
		npcsBar_.push_back(currentNPC_);
	}
	else std::cout << "NPCMgr::AddNPCType(): NPC types limit reached" << std::endl;
}

bool NPCMgr::IsPositionOccupied(int position, std::vector<NPC>& npcs)
{
	for (auto itr = npcs.begin(), end = npcs.end(); itr != end; ++itr)
		if (itr->GetPosition() == position && itr->GetLocation() == mapMgr_->GetCurrentLocationKey())
			return true;
	return false;
}

void NPCMgr::ChangePosition()
{
	if(!mapMgr_->GetNPCs().empty())
	for (mapMgr_->GetNPCsIT() = mapMgr_->GetNPCs().begin();
		mapMgr_->GetNPCsIT() != mapMgr_->GetNPCs().end();
		++mapMgr_->GetNPCsIT())
		if (mapMgr_->GetNPCsIT()->GetLocation() == mapMgr_->GetCurrentLocationKey())
	{
		mapMgr_->GetNPCsIT()->GetSprite().setPosition(mapMgr_->GetCurrentLocation()->GetFields()[mapMgr_->GetNPCsIT()
			->GetPosition()].GetSprite().getPosition());
	}
}

void NPCMgr::LoadNPCFromFile(const char * source)
{

	std::ifstream openfile(source);
	if (openfile.is_open())
	{
		std::string tempType;
		NPC tempNPC;
		while (!openfile.eof())
		{

			std::string line;

			std::getline(openfile, line); //< Load line

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("NPC{") != std::string::npos)
				tempType = "NPC";


			if (tempType == "NPC")
				if (line.find("Name=") != std::string::npos || line.find("name=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetName(line);
					std::cout << "Name(" << line << ")" << std::endl;
				}
				else if (line.find("Texture=") != std::string::npos || line.find("texture=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetTextureID(line);
					tempNPC.GetSprite().setTexture(data_->GetTexture(tempNPC.GetTextureID()));
					std::cout << "Texture(" << line << ")" << std::endl;
				}
				else if (line.find("Level=") != std::string::npos || line.find("level=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetLevel(atoi(line.c_str()));
					std::cout << "Level(" << line << ")" << std::endl;
				}
				else if(line.find("Role=") != std::string::npos || line.find("role=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetRole(line);
					std::cout << "Role(" << line << ")" << std::endl;
				}
				else if (line.find("Strength=") != std::string::npos || line.find("strength=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetStrength(atoi(line.c_str()));
					std::cout << "Strength(" << line << ")" << std::endl;
				}
				else if (line.find("Agility=") != std::string::npos || line.find("agility=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetAgility(atoi(line.c_str()));
					std::cout << "Agility(" << line << ")" << std::endl;
				}
				else if (line.find("WillPower=") != std::string::npos || line.find("willpower=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetWillPower(atoi(line.c_str()));
					std::cout << "WillPower(" << line << ")" << std::endl;
				}
				else if (line.find("Intelligence=") != std::string::npos || line.find("intelligence=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetIntelligence(atoi(line.c_str()));
					std::cout << "Intelligence(" << line << ")" << std::endl;
				}
				else if (line.find("Health=") != std::string::npos || line.find("health=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetHealthPointsMax(atoi(line.c_str()));
					std::cout << "Health(" << line << ")" << std::endl;
				}
				else if (line.find("SpellFuel=") != std::string::npos || line.find("spellfuel=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetMaxSpellFuel(atoi(line.c_str()));
					std::cout << "SpellFuel(" << line << ")" << std::endl;
				}
				else if (line.find("SpellFuelType=") != std::string::npos || line.find("spellfueltype=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetSpellFuelType(line);
					std::cout << "SpellFuelType(" << line << ")" << std::endl;
				}
				else if (line.find("Endurance=") != std::string::npos || line.find("endurance=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetEndurance(atoi(line.c_str()));
					std::cout << "Endurance(" << line << ")" << std::endl;
				}
				else if (line.find("Speed=") != std::string::npos || line.find("speed=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetSpeed(atoi(line.c_str()));
					std::cout << "Speed(" << line << ")" << std::endl;
				}
				else if (line.find("Spell=") != std::string::npos || line.find("spell=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.AddSpell(line);
					std::cout << "Spell(" << line << ")" << std::endl;
				}
				else if (line.find("PiercingArmor=") != std::string::npos || line.find("piercingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Piercing");
					std::cout << "PiercingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("CuttingArmor=") != std::string::npos || line.find("cuttingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Cutting");
					std::cout << "CuttingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("CrushingArmor=") != std::string::npos || line.find("crushingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Crushing");
					std::cout << "CrushingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("MagicalArmor=") != std::string::npos || line.find("magicalarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Magical");
					std::cout << "MagicalArmor(" << line << ")" << std::endl;
				}
				else if (line.find("Item=") != std::string::npos || line.find("item=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.AddItem(line);
					std::cout << "Item(" << line << ")" << std::endl;
				}
				else if (line.find("Loot=") != std::string::npos || line.find("loot=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.AddLoot(line);
					std::cout << "Item(" << line << ")" << std::endl;
				}
				else if (line.find("LootChance=") != std::string::npos || line.find("lootchance=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.AddLootChance(atoi(line.c_str()));
					std::cout << "Item(" << line << ")" << std::endl;
				}

			if (line.find('}') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
				std::cout << " Type(" << tempType << ")" << std::endl;

				if (tempType == "NPC")
				{
					if (npcsBar_.size() <= 10)
						npcsBar_.push_back(tempNPC);
					else std::cout << "FieldMgr::AddFieldType(): Fields limit reached" << std::endl;
				}

				tempType = "";
			}

		}
	}
}

void NPCMgr::GUIUpdate()
{
	if (isNPCToolSelected_ == true)
	{
		npcsBar_[selectedNPC_].GetSprite().setColor(sf::Color(255, 255, 255, 128));
		npcsBar_[selectedNPC_].GetSprite().setPosition(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get())) - sf::Vector2f(30, 30));
	}
}

void NPCMgr::DrawTool()
{
	if (appWindow_ && !npcsBar_.empty())
	{
		if (isNPCToolSelected_ == true)
			appWindow_->Get().draw(npcsBar_[selectedNPC_].GetSprite());
	}
	else
		std::cout << "Can't render npc tool due appWindow is not loaded" << std::endl;
}

void NPCMgr::Init(DataMgr * data, MapMgr * mapMgr, InputMgr * input, AppWindow * appWindow)
{
	data_ = data;
	mapMgr_ = mapMgr;
	input_ = input;
	appWindow_ = appWindow;

	currentNPC_.GetSprite().setColor(sf::Color(128, 255, 255, 128));


	selectedTool_ = 1;
	isNPCToolSelected_ = true;
	canClick_ = true;
	clickTimer_.restart();

}

size_t NPCMgr::GetNPCBarSize()
{
	return npcsBar_.size();
}

NPC & NPCMgr::GetNPCTemplate(int ID)
{
	return npcsBar_[ID];
}

bool NPCMgr::IsNPCBarEmpty()
{
	return npcsBar_.empty();
}

bool NPCMgr::IsNPCSelected()
{
	return isNPCSelected_;
}

void NPCMgr::ChangeTool()
{
	if (!npcsBar_.empty())
	for (int i = 0; i < npcsBar_.size(); i++)
		if (input_->KeyPressing(sf::Keyboard::Num1 + i) && (selectedNPC_ != i || isNPCToolSelected_ == false))
		{
			selectedNPC_ = i;
			isNPCToolSelected_ = true;
		}
}

void NPCMgr::DeleteNPC()
{
	if (!mapMgr_->GetNPCs().empty())
	if (isNPCSelected_ == true && input_->KeyReleased(sf::Keyboard::Delete))
		for (mapMgr_->GetNPCsIT() = mapMgr_->GetNPCs().begin();
			mapMgr_->GetNPCsIT() != mapMgr_->GetNPCs().end();
			++mapMgr_->GetNPCsIT())
			if (mapMgr_->GetNPCsIT()->IsSelected() == true)
			{
				mapMgr_->GetNPCs().erase(mapMgr_->GetNPCsIT());
				isNPCToolSelected_ = false;
				isNPCSelected_ = false;
				break;
			}
}

void NPCMgr::PlaceNPC()
{
	if (isNPCToolSelected_ == true && !npcsBar_.empty())
		for (size_t i = 0; i != mapMgr_->GetCurrentLocation()->GetFields().size(); i++)
			if (mapMgr_->GetCurrentLocation()->GetFields()[i].GetSprite().getGlobalBounds().contains
			(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()))))
		if (!IsPositionOccupied(i, mapMgr_->GetNPCs()))
	{
		mapMgr_->GetNPCs().push_back(npcsBar_[selectedNPC_]);
		mapMgr_->GetNPCs()[mapMgr_->GetNPCs().size() - 1].GetSprite().setColor(sf::Color(255, 255, 255, 255));
		mapMgr_->GetNPCs()[mapMgr_->GetNPCs().size() - 1].GetHeader().
			setPosition(mapMgr_->GetNPCs()[mapMgr_->GetNPCs().size() - 1].GetSprite().getPosition());
		mapMgr_->GetNPCs()[mapMgr_->GetNPCs().size() - 1].SetLocation(mapMgr_->GetCurrentLocationKey());
		mapMgr_->GetNPCs()[mapMgr_->GetNPCs().size() - 1].SetPosition(i);
	}
}

void NPCMgr::MoveNPC()
{
	if (isNPCGrabbed_ == true)
	{

		for(size_t i =0; i < mapMgr_->GetCurrentLocation()->GetFields().size(); i++)
			if (mapMgr_->GetCurrentLocation()->GetFields()[i].GetSprite().getGlobalBounds().contains
			(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()))))
				if(!IsPositionOccupied(i, mapMgr_->GetNPCs()))
			{
				mapMgr_->GetNPCs()[selectedNPC_].SetPosition(i);
				mapMgr_->GetNPCs()[selectedNPC_].GetHeader().setPosition(mapMgr_->GetNPCs()[selectedNPC_].GetSprite().getPosition());
			}
	}
}

void NPCMgr::SelectNPC()
{
	if (!mapMgr_->GetNPCs().empty())
	if (isNPCToolSelected_ == false && isNPCGrabbed_ == false)
	{
		for (mapMgr_->GetNPCsIT() = mapMgr_->GetNPCs().begin();
			mapMgr_->GetNPCsIT() != mapMgr_->GetNPCs().end();
			++mapMgr_->GetNPCsIT())
		{
			int index = std::distance(mapMgr_->GetNPCs().begin(), mapMgr_->GetNPCsIT());

			if (mapMgr_->GetNPCsIT()->GetSprite().getGlobalBounds().contains(appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()))))
			{
				UnselectNPC();
				isNPCGrabbed_ = true;
				isNPCSelected_ = true;
				selectedNPC_ = index;
				mapMgr_->GetNPCsIT()->IsSelected(true);
				mapMgr_->GetNPCsIT()->GetSprite().setColor(sf::Color(255, 255, 255, 128));
				mouse_prev_location_ = appWindow_->Get().mapPixelToCoords(sf::Mouse::getPosition(appWindow_->Get()));
				npc_prev_location_ = sf::Vector2i(mapMgr_->GetNPCsIT()->GetSprite().getPosition().x, mapMgr_->GetNPCsIT()->GetSprite().getPosition().y);
			}
		}
	}
}

void NPCMgr::UnselectNPC()
{
	if(!mapMgr_->GetNPCs().empty() && !npcsBar_.empty())
	if (isNPCSelected_ == true || isNPCToolSelected_ == true)
	{
		isNPCToolSelected_ = false;
		isNPCSelected_ = false;
		for (auto mapIterator = mapMgr_->GetNPCs().begin();	mapIterator != mapMgr_->GetNPCs().end(); ++mapIterator)
			if (mapIterator->IsSelected() == true)
			{
				mapIterator->GetSprite().setColor(sf::Color(255, 255, 255, 255));
				mapIterator->IsSelected(false);
			}
	}
}
