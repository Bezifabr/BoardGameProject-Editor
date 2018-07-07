/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MapLoader.cpp
// Purpose: Handles map loading methods. It works on pointer to mapMgr class.
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
#include "MapLoader.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

void MapLoader::Init(MapMgr * mapMgr, DataMgr* data)
{
	if (mapMgr && data)
	{
		data_ = data;
		mapMgr_ = mapMgr;
	}
}

void MapLoader::LoadMap(const char * source)
{
	data_->LoadDataFromFile(source);
	

	std::ifstream openfile(source);
	if (openfile.is_open())
	{
		mapMgr_->Clear();
		IsLoaded(true);
		mapMgr_->SetSource(source);

		Location tempMap;
		Field tempField;
		std::string tempType;
		std::string currentlocation;
		tempField.PrepareToLoad();
		sf::Vector2f tempCameraPosition;

		NPC tempNPC;


		while (!openfile.eof())
		{
			std::string line;

			std::getline(openfile, line); //< Load line

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("Place{") != std::string::npos)
				tempType = "Place";

			else if (line.find("NPC{") != std::string::npos)
				tempType = "NPC";

			else if (line.find("Settings{") != std::string::npos)
				tempType = "Settings";



			else if (line.find("Points{") != std::string::npos)
				tempType = "Points";

			else if (line.find("Locations=") != std::string::npos)
				tempType = "Locations";
			else if (line.find("Location[") != std::string::npos)
				tempType = "Location";


			if (tempType == "Place")
				if (line.find("Pos_x=") != std::string::npos || line.find("pos_x=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.GetSprite().setPosition(std::stoi(line), tempField.GetSprite().getPosition().y);
					std::cout << "Pos_x(" << tempField.GetSprite().getPosition().x << ")" << std::endl;
				}
				else if (line.find("Pos_y=") != std::string::npos || line.find("pos_y=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.GetSprite().setPosition(tempField.GetSprite().getPosition().x, std::stoi(line));
					std::cout << "Pos_y(" << tempField.GetSprite().getPosition().y << ")" << std::endl;
				}
				else if (line.find("Type=") != std::string::npos || line.find("type=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetType(line);
					std::cout << "Type(" << tempField.GetType() << ")" << std::endl;
				}
				else if (line.find("Texture=") != std::string::npos || line.find("texture=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.GetSprite().setTexture(data_->GetTexture(line));
					tempField.SetTextureID(line);
					std::cout << "Text(" << line << ")" << std::endl;
				}
				else if (line.find("FirstTrack=") != std::string::npos || line.find("firsttrack=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetFirstTrack(std::stoi(line));
					tempField.IsChangingTrack(true);
					std::cout << "FirstTrack(" << line << ")" << std::endl;
				}
				else if (line.find("SecondTrack=") != std::string::npos || line.find("secondtrack=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetSecondTrack(std::stoi(line));
					tempField.IsChangingTrack(true);
					std::cout << "SecondTrack(" << line << ")" << std::endl;
				}
				else if (line.find("Track=") != std::string::npos || line.find("track=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetTrack(std::stoi(line));
					std::cout << "Track(" << line << ")" << std::endl;
				}
				else if (line.find("NextLocation=") != std::string::npos || line.find("nextLocation=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetNextLocation(std::stoi(line));
					tempField.IsPassingNextLocation(true);
					std::cout << "NextLocation(" << line << ")" << std::endl;
				}
				else if (line.find("LocationEntrance=") != std::string::npos || line.find("locationEntrance=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetLocationEntrance(line);
					tempField.IsPassingNextLocation(true);
					std::cout << "LocationEntrance(" << line << ")" << std::endl;
				}
				else if (line.find("NextTrack=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempField.SetNextTrack(std::stoi(line));
					tempField.IsEndingTrack(true);
					std::cout << "NextTrack(" << line << ")" << std::endl;
				}



			if (tempType == "NPC")
				if (line.find("Name=") != std::string::npos || line.find("name=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetName(line);
					std::cout << "Name(" << line << ")" << std::endl;
				}
				else if (line.find("ID=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetID(line);
					std::cout << "ID(" << line << ")" << std::endl;
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
				else if (line.find("Role=") != std::string::npos || line.find("role=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetRole(line);
					std::cout << "Role(" << line << ")" << std::endl;
				}
				else if (line.find("Statistic=Strength=") != std::string::npos || line.find("strength=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetStrength(atoi(line.c_str()));
					std::cout << "Strength(" << line << ")" << std::endl;
				}
				else if (line.find("Statistic=Agility=") != std::string::npos || line.find("agility=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetAgility(atoi(line.c_str()));
					std::cout << "Agility(" << line << ")" << std::endl;
				}
				else if (line.find("Statistic=WillPower=") != std::string::npos || line.find("willpower=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetWillPower(atoi(line.c_str()));
					std::cout << "WillPower(" << line << ")" << std::endl;
				}
				else if (line.find("Statistic=Intelligence=") != std::string::npos || line.find("intelligence=") != std::string::npos)
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
				else if (line.find("Statistic=Endurance=") != std::string::npos || line.find("endurance=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetEndurance(atoi(line.c_str()));
					std::cout << "Endurance(" << line << ")" << std::endl;
				}
				else if (line.find("Statistic=Speed=") != std::string::npos || line.find("speed=") != std::string::npos)
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
				else if (line.find("Armor=PiercingArmor=") != std::string::npos || line.find("piercingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Piercing");
					std::cout << "PiercingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("Armor=CuttingArmor=") != std::string::npos || line.find("cuttingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Cutting");
					std::cout << "CuttingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("Armor=CrushingArmor=") != std::string::npos || line.find("crushingarmor=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetArmor(atoi(line.c_str()), "Crushing");
					std::cout << "CrushingArmor(" << line << ")" << std::endl;
				}
				else if (line.find("Armor=MagicalArmor=") != std::string::npos || line.find("magicalarmor=") != std::string::npos)
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
					std::cout << "Loot(" << line << ")" << std::endl;
				}
				else if (line.find("LootChance=") != std::string::npos || line.find("lootchance=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.AddLootChance(atoi(line.c_str()));
					std::cout << "ChanceOfLoot(" << line << ")" << std::endl;
				}
				else if (line.find("PositionWaypoint=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetPosition(atoi(line.c_str()));
					std::cout << "Position(" << line << ")" << std::endl;
				}
				else if (line.find("PositionLocation=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempNPC.SetLocation(atoi(line.c_str()));
					std::cout << "Location(" << line << ")" << std::endl;
				}

			if (tempType == "Settings")
				if (line.find("Camera_x=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempCameraPosition.x = std::atof(line.c_str());
					std::cout << "Camera_x(" << tempCameraPosition.x << ")" << std::endl;
				}
				else if (line.find("Camera_y=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempCameraPosition.y = std::atof(line.c_str());
					std::cout << "Camera_y(" << tempCameraPosition.y << ")" << std::endl;
				}
				else if (line.find("Background=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempMap.SetBackgroundTexture(line);
					std::cout << "Background(" << line << ")" << std::endl;
				}


			if (tempType == "Locations")
			{
				line.erase(0, line.find('=') + 1);

				std::stringstream str(line);

				while (str)
				{
					std::getline(str, line, ',');
					if (line != "")
					{
						mapMgr_->GetLocationsKeys().push_back(line);
						line.erase(std::remove(line.begin(), line.end(), ',' + 1), line.end());
					}
				}
			}

			if (tempType == "Location")
			{
				line.erase(0, line.find('[') + 1);
				currentlocation = line;
			}


			if (line.find('}') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
				std::cout << " Type(" << tempType << ")" << std::endl;


				tempField.GetHeader().setPosition(tempField.GetSprite().getPosition());

				if (tempType == "Place")
				{
					tempMap.GetFields().push_back(tempField);
					tempField.PrepareToLoad();
				}
				
				if (tempType == "NPC")
				{
					mapMgr_->GetNPCs().push_back(tempNPC);
				}
			}

			if (line.find(']') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), ']' + 1), line.end());
				std::cout << " Location[" << currentlocation << "]" << std::endl;

				tempMap.SetCameraPosition(tempCameraPosition);

				mapMgr_->AddLocation(currentlocation, tempMap);
				mapMgr_->GetLocations()[currentlocation].SetBackgroundTexture(mapMgr_->GetLocations()[currentlocation].GetBackgroundTextureSource());
				tempMap.Clear();
			}
		}
	}
}
void MapLoader::SaveMap(const char * source)
{
	sf::Clock mapSavingTime;
	ofstream Outfile;
	mapSavingTime.restart();

	if (saveSource_ == true)
	{
		IsLoaded(true);
		mapMgr_->SetSource(source);

		if (remove(source) != 0)
			perror("Creating new file to save data");
		else
			puts("File found and prepared to save data");
	}

	cout << "//////////////////////////////////////" << endl;
	cout << "              MAP SAVING             " << endl;
	cout << "//////////////////////////////////////" << endl;

	cout << "Clearing old data..." << endl;
	Outfile.open(source, std::ofstream::out | std::ofstream::trunc);
	Outfile.clear();

	Outfile.close();
	cout << "Finished!" << endl;
	cout << "Saving resources..." << endl;
	data_->SaveDataToFile(source);
	cout << "Finished!" << endl;
	Outfile.open(source, std::ofstream::out | std::ofstream::app);
	Outfile.clear();

	if(Outfile.good())
	cout << "File successfully opened!" << endl;

	cout << "Saving non player characters..." << endl;
	for (auto it = mapMgr_->GetNPCs().begin(); it != mapMgr_->GetNPCs().end(); ++it)
	{
		Outfile << "NPC{" << std::endl;
		std::cout << "NPC{" << std::endl;
		Outfile << "ID = " << it->GetID() << endl;
		cout << "ID = " << it->GetID() << endl;
		Outfile << "Name = " << it->GetName() << std::endl;
		cout << "Name = " << it->GetName() << endl;
		Outfile << "Level = " << it->GetLevel() << endl;
		cout << "Level = " << it->GetLevel() << endl;
		Outfile << "Texture = " << it->GetTextureID() << endl;
		cout << "Texture = " << it->GetTextureID() << endl;
		Outfile << "Role = " << it->GetRole() << endl;
		cout << "Role = " << it->GetRole() << endl;
		Outfile << "PositionWaypoint = " << it->GetPosition() << endl;
		cout << "PositionWaypoint = " << it->GetPosition() << endl;
		Outfile << "PositionLocation = " << it->GetLocation() <<endl;
		cout << "PositionLocation = " << it->GetLocation() << endl;
		Outfile << "Health = " << it->GetHealthPointsMax() << endl;
		cout << "Health = " << it->GetHealthPointsMax() << endl;
		Outfile << "SpellFuel = " << it->GetMaxSpellFuel() << endl;
		cout << "SpellFuel = " << it->GetMaxSpellFuel() << endl;
		Outfile << "SpellFuelType = " << it->GetSpellFuelType() << endl;
		Outfile << "Statistic = Strength = " << it->GetStrength() << endl;
		cout << "Statistic = Strength = " << it->GetStrength() << endl;
		Outfile << "Statistic = Agility = " << it->GetAgility() << endl;
		cout << "Statistic = Agility = " << it->GetAgility() << endl;
		Outfile << "Statistic = Endurance = " << it->GetEndurance() << endl;
		cout << "Statistic = Endurance = " << it->GetEndurance() << endl;
		Outfile << "Statistic = Intelligence = " << it->GetIntelligence() << endl;
		cout << "Statistic = Intelligence = " << it->GetIntelligence() << endl;
		Outfile << "Statistic = Speed = " << it->GetSpeed() << endl;
		cout << "Statistic = Speed = " << it->GetSpeed() << endl;
		Outfile << "Statistic = Will Power = " << it->GetWillPower() << endl;
		cout << "Statistic = Will Power = " << it->GetWillPower() << endl;
		for (int i = 1; i <= 6; i++) 
		{
		Outfile << "Spell = " << it->GetSpell(i) << endl;
		cout << "Spell = " << it->GetSpell(i) << endl;
		}
		Outfile << "Armor = PiercingArmor = " << to_string(it->GetArmor("piercing")) << endl;
		cout << "Armor = PiercingArmor = " << to_string(it->GetArmor("piercing")) << endl;
		Outfile << "Armor = CuttingArmor = " << to_string(it->GetArmor("cutting")) << endl;
		cout << "Armor = CuttingArmor = " << to_string(it->GetArmor("cutting")) << endl;
		Outfile << "Armor = CrushingArmor = " << to_string(it->GetArmor("crushing")) << endl;
		cout << "Armor = CrushingArmor = " << to_string(it->GetArmor("crushing")) << endl;
		Outfile << "Armor = MagicalArmor = " << to_string(it->GetArmor("magical")) << endl;
		cout << "Armor = MagicalArmor = " << to_string(it->GetArmor("magical")) << endl;
		Outfile << "Item = " << it->GetItem(1) << endl;
		cout << "Item = " << it->GetItem(1) << endl;
		Outfile << "Item = " << it->GetItem(2) << endl;
		cout << "Item = " << it->GetItem(2) << endl;
		for (int i = 1; i <= 4; i++)
		{
			Outfile << "Loot = " << it->GetItemLoot(i) << endl;
			cout << "Loot = " << it->GetItemLoot(i) << endl;
			Outfile << "Loot Chance = " << to_string(it->GetChangeOfLoot(i)) << endl;
			cout << "Loot Chance = " << to_string(it->GetChangeOfLoot(i)) << endl;
		}
		Outfile << "}" << endl;
		cout << "}" << endl;

	}

	cout << "Finished!" << endl;
	cout << "Saving locations..." << endl;
	Outfile << "Locations= ";

	for (size_t i = 0; i != mapMgr_->GetLocationsKeys().size(); i++)
		Outfile << mapMgr_->GetLocationsKeys()[i] << ",";


	cout << "Finished!" << endl;
	cout << "Saving fields and settings..." << endl;

	for (size_t i = 0; i != mapMgr_->GetLocationsKeys().size(); i++) 
	{

		cout << "\nLocation[" << mapMgr_->GetLocationsKeys()[i] << endl;
		Outfile << "\n\nLocation[ " << mapMgr_->GetLocationsKeys()[i] << endl;


		for (mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT() = mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFields().begin();
			mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT() != mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFields().end();
			mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()++)
		{
			Outfile << "Place{" << endl;
			cout << "Place{" << endl;
			Outfile << "Pos_x = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSprite().getPosition().x << endl;
			cout << "Pos_x = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSprite().getPosition().x << endl;
			Outfile << "Pos_y = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSprite().getPosition().y << endl;
			cout << "Pos_y = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSprite().getPosition().y << endl;
			Outfile << "Type = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetType() << endl;
			cout << "Type = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetType() << endl;
			Outfile << "Texture = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetTextureID() << endl;
			cout << "Texture = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetTextureID() << endl;
			Outfile << "Track = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetTrack()) << endl;
			cout << "Track = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetTrack()) << endl;

			if (mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->IsChangingTrack())
			{
				Outfile << "FirstTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetFirstTrack()) << endl;
				cout << "FirstTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetFirstTrack()) << endl;
				Outfile << "SecondTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSecondTrack()) << endl;
				cout << "SecondTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetSecondTrack()) << endl;
			}

			if (mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->IsEndingTrack())
			{
				Outfile << "NextTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetNextTrack()) << endl;
				cout << "NextTrack = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetNextTrack()) << endl;
			}

			if (mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->IsPassingNextLocation())
			{
				Outfile << "NextLocation = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetNextLocation()) << endl;
				cout << "NextLocation = " << to_string(mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetNextLocation()) << endl;
				Outfile << "LocationEntrance = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetLocationEntrance() << endl;
				cout << "LocationEntrance = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetFieldsIT()->GetLocationEntrance() << endl;
			}

			Outfile << "}" << endl;
			cout << "}" << endl;
		}

		Outfile << "Settings{" << std::endl;
		Outfile << "Camera_x = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetCameraPosition().x << std::endl;
		Outfile << "Camera_y = " << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetCameraPosition().y << std::endl;
		if (mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].IsBackgroundLoaded())
			Outfile << "Background=" << mapMgr_->GetLocations()[mapMgr_->GetLocationsKeys()[i]].GetBackgroundTextureSource() << std::endl;
		Outfile << "}" << std::endl;
		Outfile << "]" << endl;
	}
	cout << "Finished!" << endl;
	Outfile.close();
	cout << "Done! " << mapSavingTime.getElapsedTime().asSeconds() << endl;
}

void MapLoader::SaveMap(const char * source, bool saveSource)
{
	saveSource_ = saveSource;
	SaveMap(source);
}

void MapLoader::SaveMap(const char * source, std::map<std::string, Location>* map)
{
}
