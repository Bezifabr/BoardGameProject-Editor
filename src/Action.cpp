/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Action.cpp
// Purpose: Contains action methods used in graphic user interface.
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
#include "Action.h"
#include <string>
#include <algorithm>
#include <cctype>

bool IsStringAvailable(std::vector<std::string> stringVector, std::string stringValue)
{
	if (!stringVector.empty())
		for (size_t i = 0; i != stringVector.size(); i++)
			if (stringValue == stringVector[i])
				return false;
	return true;
}

void ActionWindow::UpdateLocationProperties()
{
	windowBuilders_["LocProp"]->GetLabel()["Title"]->SetText(mapMgr_->GetLocationsKeys()[mapMgr_->GetCurrentLocationKey()]);
	windowBuilders_["LocProp"]->GetLabel()["Number"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
	windowBuilders_["LocProp"]->GetEntry()["Name"]->SetText(mapMgr_->GetLocationsKeys()[mapMgr_->GetCurrentLocationKey()]);
	windowBuilders_["LocProp"]->GetEntry()["ID"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
	windowBuilders_["LocProp"]->GetEntry()["Background"]->SetText(mapMgr_->GetCurrentLocation()->GetBackgroundTextureSource());
	windowBuilders_["LocProp"]->GetEntry()["Camera x"]->SetText(to_string(mapMgr_->GetCurrentLocation()->GetCameraPosition().x));
	windowBuilders_["LocProp"]->GetEntry()["Camera y"]->SetText(to_string(mapMgr_->GetCurrentLocation()->GetCameraPosition().y));

	windowBuilders_["locationMove"]->GetEntry()["Current"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
}
void ActionMenu::NewLocation()
{
	if (mapMgr_)
	{
		mapMgr_->GetCurrentLocation()->GetFields().clear();
		mapMgr_->GetCurrentLocation()->SetCameraPosition(0, 0);
		mapMgr_->Clear();
		mapMgr_->NewLocation("New location");

		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		windowBuilders_["locations"]->GetLabel()["Name"]->SetText(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Number"]->SetText("Location: " + std::to_string(currentLocation));
	

		windowBuilders_["LocProp"]->GetLabel()["Title"]->SetText(mapMgr_->GetLocationsKeys()[mapMgr_->GetCurrentLocationKey()]);
		windowBuilders_["LocProp"]->GetLabel()["Number"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
		windowBuilders_["LocProp"]->GetEntry()["Name"]->SetText(mapMgr_->GetLocationsKeys()[mapMgr_->GetCurrentLocationKey()]);
		windowBuilders_["LocProp"]->GetEntry()["ID"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
		windowBuilders_["LocProp"]->GetEntry()["Background"]->SetText(mapMgr_->GetCurrentLocation()->GetBackgroundTextureSource());
		windowBuilders_["LocProp"]->GetEntry()["Camera x"]->SetText(to_string(mapMgr_->GetCurrentLocation()->GetCameraPosition().x));
		windowBuilders_["LocProp"]->GetEntry()["Camera y"]->SetText(to_string(mapMgr_->GetCurrentLocation()->GetCameraPosition().y));

		windowBuilders_["locationMove"]->GetEntry()["Current"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionMenu::OpenConsole()
{
	console_->TurnOn();
}

void ActionMenu::OpenFieldTemplate()
{
	windowBuilders_["FieldTempTool"]->GetWindow()->GetWindow()->Show(true);
	windowMgr_->SetWindowOpened(true);
}

void ActionMenu::OpenNPCTemplate()
{
	windowBuilders_["NPCTempTool"]->GetWindow()->GetWindow()->Show(true);
	windowMgr_->SetWindowOpened(true);
}

void ActionMenu::OpenReallyClose()
	{
		windowBuilders_["ReallyClose"]->GetWindow()->GetWindow()->Show(true);
		windowMgr_->SetWindowOpened(true);
	}

void ActionMenu::ResetCamera()
{
	if (mapMgr_)
	{
		mapMgr_->GetCurrentLocation()->SetCameraPosition(0, 0);
	}
	else throw exception("ResetCamera(): mapMgr_ returns null");
}

void ActionMenu::OpenSoundLoading()
{
	windowBuilders_["SoundLoading"]->GetWindow()->GetWindow()->Show(true);
	windowMgr_->SetWindowOpened(true);
}

void ActionMenu::OpenTextureLoading()
{
	windowBuilders_["TextureLoading"]->GetWindow()->GetWindow()->Show(true);
	windowMgr_->SetWindowOpened(true);
}

void ActionWindow::OpenReallyClose()
{
	OpenWindow("ReallyClose");
}

void ActionWindow::CloseReallyClose()
{
	CloseWindow("ReallyClose");
}

void ActionWindow::OpenSavingWindowReallyClose()
{
	OpenWindow("SaveMap");
	CloseReallyClose();
}

void ActionWindow::OpenNPCStats()
{
	windowBuilders_["NPCStats"]->GetEntry()["Health"]->SetText(std::to_string(tempNPC_->GetHealthPointsMax()));
	windowBuilders_["NPCStats"]->GetEntry()["\"Spell fuel\""]->SetText(std::to_string(tempNPC_->GetMaxSpellFuel()));
	windowBuilders_["NPCStats"]->GetEntry()["Strength"]->SetText(to_string(tempNPC_->GetStrength()));
	windowBuilders_["NPCStats"]->GetEntry()["Agility"]->SetText(to_string(tempNPC_->GetAgility()));
	windowBuilders_["NPCStats"]->GetEntry()["Endurance"]->SetText(to_string(tempNPC_->GetEndurance()));
	windowBuilders_["NPCStats"]->GetEntry()["Intelligence"]->SetText(to_string(tempNPC_->GetIntelligence()));
	windowBuilders_["NPCStats"]->GetEntry()["Speed"]->SetText(to_string(tempNPC_->GetSpeed()));
	windowBuilders_["NPCStats"]->GetEntry()["Will power"]->SetText(to_string(tempNPC_->GetWillPower()));

	CloseWindow("NPCProp");
	OpenWindow("NPCStats");
}

void ActionWindow::OpenNPCSpells()
{
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_1"]->SetText(tempNPC_->GetSpell(0));
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_2"]->SetText(tempNPC_->GetSpell(1));
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_3"]->SetText(tempNPC_->GetSpell(2));
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_4"]->SetText(tempNPC_->GetSpell(3));
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_5"]->SetText(tempNPC_->GetSpell(4));
	windowBuilders_["NPCSpells"]->GetEntry()["Spell_6"]->SetText(tempNPC_->GetSpell(5));

	CloseWindow("NPCProp");
	OpenWindow("NPCSpells");
}

void ActionWindow::OpenNPCArmor()
{
	windowBuilders_["NPCArmor"]->GetEntry()["Piercing"]->SetText(to_string(tempNPC_->GetArmor("Piercing")));
	windowBuilders_["NPCArmor"]->GetEntry()["Cut"]->SetText(to_string(tempNPC_->GetArmor("Cutting")));
	windowBuilders_["NPCArmor"]->GetEntry()["Crushing"]->SetText(to_string(tempNPC_->GetArmor("Crushing")));
	windowBuilders_["NPCArmor"]->GetEntry()["Magical"]->SetText(to_string(tempNPC_->GetArmor("Magical")));

	CloseWindow("NPCProp");
	OpenWindow("NPCArmor");

}

void ActionWindow::OpenNPCInventory()
{
	windowBuilders_["NPCInventory"]->GetEntry()["Slot_1"]->SetText(tempNPC_->GetItem(0));
	windowBuilders_["NPCInventory"]->GetEntry()["Slot_2"]->SetText(tempNPC_->GetItem(1));
	for (int i = 1; i <= 4; i++)
	{
		windowBuilders_["NPCInventory"]->GetEntry()["Loot "+to_string(i)]->SetText(tempNPC_->GetItemLoot(i));
		if(tempNPC_->GetChangeOfLoot(i) != 0)
		windowBuilders_["NPCInventory"]->GetEntry()["Chance_" + to_string(i)]->SetText(to_string(tempNPC_->GetChangeOfLoot(i)));
	}
	CloseWindow("NPCProp");
	OpenWindow("NPCInventory");
}

void ActionWindow::OpenNPCPosition()
{
	windowBuilders_["NPCPosition"]->GetEntry()["FieldID"]->SetText(to_string(tempNPC_->GetPosition()));
	windowBuilders_["NPCPosition"]->GetEntry()["Location"]->SetText(to_string(tempNPC_->GetLocation()));

	CloseWindow("NPCProp");
	OpenWindow("NPCPosition");
}

void ActionWindow::CloseNPCStats()
{
	CloseWindow("NPCStats");
	OpenWindow("NPCProp");
}

void ActionWindow::CloseNPCSpells()
{
	CloseWindow("NPCSpells");
	OpenWindow("NPCProp");
}

void ActionWindow::CloseNPCArmor()
{
	CloseWindow("NPCArmor");
	OpenWindow("NPCProp");
}

void ActionWindow::CloseNPCInventory()
{
	CloseWindow("NPCInventory");
	OpenWindow("NPCProp");
}

void ActionWindow::CloseNPCPosition()
{
	CloseWindow("NPCPosition");
	OpenWindow("NPCProp");
}

void ActionWindow::OpenNPCProperties(NPC * npc, size_t order, DataMgr * dataMgr)
{
	tempNPC_ = npc;
	dataMgr_ = dataMgr;

	windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_ID]->SetText(npc->GetID());
	windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_NAME]->SetText(npc->GetName());

	if(npc->GetLevel() != 0)
	windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_LEVEL]->SetText(to_string(npc->GetLevel()));

	windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_TEXTURE]->SetText(npc->GetTextureID());
	
	windowBuilders_["NPCProp"]->GetCombo()[NPC_WINDOW_ROLE]->SelectItem(tempNPC_->GetRole());


	OpenWindow("NPCProp");


}

void ActionWindow::CloseNPCProperties()
{
	CloseWindow("NPCProp");

	tempNPC_ = nullptr;
}

void ActionWindow::NPCPropertiesOK()
{

	if (!windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_ID]->GetText().isEmpty())
	tempNPC_->SetID(windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_ID]->GetText());
	if (!windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_NAME]->GetText().isEmpty())
	tempNPC_->SetName(windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_NAME]->GetText());
	if (!windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_LEVEL]->GetText().isEmpty())
	tempNPC_->SetLevel(atoi(windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_LEVEL]->GetText().toAnsiString().c_str()));
	if (!windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_TEXTURE]->GetText().isEmpty())
	{
		tempNPC_->SetTextureID(windowBuilders_["NPCProp"]->GetEntry()[NPC_WINDOW_TEXTURE]->GetText());
		tempNPC_->GetSprite().setTexture(dataMgr_->GetTexture(tempNPC_->GetTextureID()));
	}

	tempNPC_->SetRole(windowBuilders_["NPCProp"]->GetCombo()[NPC_WINDOW_ROLE]->GetSelectedItem());


	CloseNPCProperties();
}

void ActionWindow::NPCStatsOK()
{

	tempNPC_->SetHealthPointsMax(atoi(windowBuilders_["NPCStats"]->GetEntry()["Health"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetSpellFuel(atoi(windowBuilders_["NPCStats"]->GetEntry()["\"Spell fuel\""]->GetText().toAnsiString().c_str()));
	tempNPC_->SetStrength(atoi(windowBuilders_["NPCStats"]->GetEntry()["Strength"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetAgility(atoi(windowBuilders_["NPCStats"]->GetEntry()["Agility"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetEndurance(atoi(windowBuilders_["NPCStats"]->GetEntry()["Endurance"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetIntelligence(atoi(windowBuilders_["NPCStats"]->GetEntry()["Intelligence"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetSpeed(atoi(windowBuilders_["NPCStats"]->GetEntry()["Speed"]->GetText().toAnsiString().c_str()));
	tempNPC_->SetWillPower(atoi(windowBuilders_["NPCStats"]->GetEntry()["Will power"]->GetText().toAnsiString().c_str()));

	CloseNPCStats();
}

void ActionWindow::NPCSpellsOK()
{
	if(!windowBuilders_["NPCSpells"]->GetEntry()["Spell_1"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_1"]->GetText(), 0);
	if (!windowBuilders_["NPCSpells"]->GetEntry()["Spell_2"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_2"]->GetText(), 1);
	if (!windowBuilders_["NPCSpells"]->GetEntry()["Spell_3"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_3"]->GetText(), 2);
	if (!windowBuilders_["NPCSpells"]->GetEntry()["Spell_4"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_4"]->GetText(), 3);
	if (!windowBuilders_["NPCSpells"]->GetEntry()["Spell_5"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_5"]->GetText(), 4);
	if (!windowBuilders_["NPCSpells"]->GetEntry()["Spell_6"]->GetText().isEmpty())
	tempNPC_->SetSpell(windowBuilders_["NPCSpells"]->GetEntry()["Spell_6"]->GetText(), 5);

	CloseNPCSpells();
}

void ActionWindow::NPCArmorOK()
{

	if(!windowBuilders_["NPCArmor"]->GetEntry()["Piercing"]->GetText().isEmpty() && windowBuilders_["NPCArmor"]->GetEntry()["Piercing"]->GetText() != "0")
	tempNPC_->SetArmor(atoi(windowBuilders_["NPCArmor"]->GetEntry()["Piercing"]->GetText().toAnsiString().c_str()), "Piercing");
	if (!windowBuilders_["NPCArmor"]->GetEntry()["Cut"]->GetText().isEmpty() && windowBuilders_["NPCArmor"]->GetEntry()["Cut"]->GetText() != "0")
	tempNPC_->SetArmor(atoi(windowBuilders_["NPCArmor"]->GetEntry()["Cut"]->GetText().toAnsiString().c_str()), "Cutting");
	if (!windowBuilders_["NPCArmor"]->GetEntry()["Crushing"]->GetText().isEmpty() && windowBuilders_["NPCArmor"]->GetEntry()["Crushing"]->GetText() != "0")
	tempNPC_->SetArmor(atoi(windowBuilders_["NPCArmor"]->GetEntry()["Crushing"]->GetText().toAnsiString().c_str()), "Crushing");
	if (!windowBuilders_["NPCArmor"]->GetEntry()["Magical"]->GetText().isEmpty() && windowBuilders_["NPCArmor"]->GetEntry()["Magical"]->GetText() != "0")
	tempNPC_->SetArmor(atoi(windowBuilders_["NPCArmor"]->GetEntry()["Magical"]->GetText().toAnsiString().c_str()), "Magical");

	CloseNPCArmor();
}

void ActionWindow::NPCInventoryOK()
{
	if(!windowBuilders_["NPCInventory"]->GetEntry()["Slot_1"]->GetText().isEmpty())
	tempNPC_->ItemSlot(windowBuilders_["NPCInventory"]->GetEntry()["Slot_1"]->GetText(), 0);
	if (!windowBuilders_["NPCInventory"]->GetEntry()["Slot_2"]->GetText().isEmpty())
	tempNPC_->ItemSlot(windowBuilders_["NPCInventory"]->GetEntry()["Slot_2"]->GetText(), 1);


	for (int i = 1; i <= 4; i++)
	{
		if (!windowBuilders_["NPCInventory"]->GetEntry()["Loot "+to_string(i)]->GetText().isEmpty())
			tempNPC_->ItemLoot(windowBuilders_["NPCInventory"]->GetEntry()["Loot "+to_string(i)]->GetText(), i);
		else tempNPC_->ItemLootRemove(i);

		std::string tempKey = "Chance_" + std::to_string(i);
		if (!windowBuilders_["NPCInventory"]->GetEntry()[tempKey]->GetText().isEmpty())
			tempNPC_->SetChanceOfLoot(i, atoi(windowBuilders_["NPCInventory"]->GetEntry()[tempKey]->GetText().toAnsiString().c_str()));
	}

	CloseNPCInventory();
}

void ActionWindow::NPCPositionOK()
{
	if(!windowBuilders_["NPCPosition"]->GetEntry()["FieldID"]->GetText().isEmpty())
	tempNPC_->SetPosition(atoi(windowBuilders_["NPCPosition"]->GetEntry()["FieldID"]->GetText().toAnsiString().c_str())); 
	if (!windowBuilders_["NPCPosition"]->GetEntry()["Location"]->GetText().isEmpty())
	tempNPC_->SetLocation(atoi(windowBuilders_["NPCPosition"]->GetEntry()["Location"]->GetText().toAnsiString().c_str()));

	CloseNPCPosition();
}

void ActionWindow::LocationMoveOpen()
{
	OpenWindow("locationMove");
	windowBuilders_["locationMove"]->GetEntry()["Current"]->SetText(std::to_string(mapMgr_->GetCurrentLocationKey()));
}

void ActionWindow::LocationMove()
{
	// TODO: Other comparisons
	if (atoi(windowBuilders_["locationMove"]->GetEntry()["Next"]->GetText().toAnsiString().c_str()) < mapMgr_->GetLocationsKeys().size())
	{

		mapMgr_->MoveLocationTo(atoi(windowBuilders_["locationMove"]->GetEntry()["Current"]->GetText().toAnsiString().c_str()),
			atoi(windowBuilders_["locationMove"]->GetEntry()["Next"]->GetText().toAnsiString().c_str()));

		windowBuilders_["locationMove"]->GetEntry()["Current"]->SetText(mapMgr_->GetCurrentLocationKey());

		UpdateLocationProperties();
		Update();
	}
	else
	{
		// ERROR STATEMENT
		std::cout << "Error occurred when tried to move location" << std::endl;
	}
}

void ActionWindow::LocationReplace()
{
	if (atoi(windowBuilders_["locationMove"]->GetEntry()["Next"]->GetText().toAnsiString().c_str()) < mapMgr_->GetLocationsKeys().size())
	{

		mapMgr_->ReplaceLocationWith(atoi(windowBuilders_["locationMove"]->GetEntry()["Current"]->GetText().toAnsiString().c_str()),
			atoi(windowBuilders_["locationMove"]->GetEntry()["Next"]->GetText().toAnsiString().c_str()));

		windowBuilders_["locationMove"]->GetEntry()["Current"]->SetText(mapMgr_->GetCurrentLocationKey());

		mapMgr_->ReplaceNPCs(atoi(windowBuilders_["locationMove"]->GetEntry()["Current"]->GetText().toAnsiString().c_str()),
			atoi(windowBuilders_["locationMove"]->GetEntry()["Next"]->GetText().toAnsiString().c_str()));
		UpdateLocationProperties();
		Update();
	}
	else
	{
		// ERROR STATEMENT
		std::cout << "Error occurred when tried to replace location" << std::endl;
	}
}

void ActionWindow::LocationMoveClose()
{
	CloseWindow("locationMove");
}

void ActionWindow::LocPropLeft()
{
	if (mapMgr_)
	{
		mapMgr_->Previous();
		UpdateLocationProperties();
		Update();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::LocPropRight()
{
	if (mapMgr_)
	{
		mapMgr_->Next();
		UpdateLocationProperties();
		Update();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::LocPropCreate()
{
	if (mapMgr_)
	{
		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		currentLocation++;
		std::string name = "New location";
		int i = 1;

		if (!IsStringAvailable(mapMgr_->GetLocationsKeys(), name))
			while (!IsStringAvailable(mapMgr_->GetLocationsKeys(), name))
			{
				name = "New location " + std::to_string(i);
				i++;
			}

		mapMgr_->GetLocationsKeys().push_back(name);
		mapMgr_->NewLocation(name);

		if (currentLocation == mapMgr_->GetLocationsKeys().size() - 1)
			LocPropRight();
		else
		{
			UpdateLocationProperties();
			Update();
		}
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;

}

void ActionWindow::LocPropRemove()
{
	if (mapMgr_)
	{
		mapMgr_->RemoveLocation();
		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		mapMgr_->SetCurrentLocation(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Name"]->SetText(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Number"]->SetText("Location: " + std::to_string(currentLocation));
		UpdateLocationProperties();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::OpenLocationProperties()
{
	CloseWindow("locations");
	OpenWindow("LocProp");
	UpdateLocationProperties();

}

void ActionWindow::CloseLocationProperties()
{
	OpenWindow("locations");
	CloseWindow("LocProp");
	LocationMoveClose();
}

void ActionWindow::LocationPropertiesOk()
{
	LocationPropertiesApply();
	CloseLocationProperties();
}

void ActionWindow::LocationPropertiesApply()
{
	mapMgr_->ChangeCurrentName(windowBuilders_["LocProp"]->GetEntry()["Name"]->GetText());
	mapMgr_->GetCurrentLocation()->SetBackgroundTexture(windowBuilders_["LocProp"]->GetEntry()["Background"]->GetText());
	mapMgr_->GetCurrentLocation()->SetCameraPosition(atoi(windowBuilders_["LocProp"]->GetEntry()["Camera x"]->GetText().toAnsiString().c_str()),
		atoi(windowBuilders_["LocProp"]->GetEntry()["Camera y"]->GetText().toAnsiString().c_str()));

	mapMgr_->SetCurrentLocation(mapMgr_->GetLocationsKeys()[mapMgr_->GetCurrentLocationKey()]);
	UpdateLocationProperties();
	Update();
}

void ActionWindow::PreviousLocation()
{
	if(	windowMgr_->IsWindowOpened() == false)
	if (mapMgr_)
	{
		mapMgr_->Previous();
		Update();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::NextLocation()
{
	if (windowMgr_->IsWindowOpened() == false)
	if (mapMgr_)
	{
		mapMgr_->Next();
		Update();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::CreateLocation()
{
	if (windowMgr_->IsWindowOpened() == false)
	if (mapMgr_)
	{
		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		currentLocation++;
		std::string name = "New location";
		int i = 1;

		if (!IsStringAvailable(mapMgr_->GetLocationsKeys(), name))
			while (!IsStringAvailable(mapMgr_->GetLocationsKeys(), name))
			{
				name = "New location " + std::to_string(i);
				i++;
			}

		mapMgr_->NewLocation(name);

		if (currentLocation == mapMgr_->GetLocationsKeys().size() - 1)
			NextLocation();
		else
			Update();
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;

}

void ActionWindow::DeleteLocation()
{
	if (windowMgr_->IsWindowOpened() == false)
	if (mapMgr_)
	{
		mapMgr_->RemoveLocation();
		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		mapMgr_->SetCurrentLocation(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Name"]->SetText(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Number"]->SetText("Location: " + std::to_string(currentLocation));
	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void ActionWindow::OpenFieldProperties(Field * field, size_t order, DataMgr * dataMgr)
{
	OpenWindow("FieldProp");

	windowBuilders_["FieldProp"]->GetEntry()["Type"]->SetText(field->GetType());
	windowBuilders_["FieldProp"]->GetEntry()["Order"]->SetText(to_string(order));
	windowBuilders_["FieldProp"]->GetEntry()["Position x"]->SetText(to_string(field->GetSprite().getPosition().x));
	windowBuilders_["FieldProp"]->GetEntry()["Position y"]->SetText(to_string(field->GetSprite().getPosition().y));
	windowBuilders_["FieldProp"]->GetEntry()["Track"]->SetText(to_string(field->GetTrack()));
	windowBuilders_["FieldProp"]->GetEntry()["First Track"]->SetText(to_string(field->GetFirstTrack()));
	windowBuilders_["FieldProp"]->GetEntry()["Second Track"]->SetText(to_string(field->GetSecondTrack()));
	windowBuilders_["FieldProp"]->GetEntry()["Next Track"]->SetText(to_string(field->GetNextTrack()));
	windowBuilders_["FieldProp"]->GetEntry()["Next Location"]->SetText(to_string(field->GetNextLocation()));
	windowBuilders_["FieldProp"]->GetEntry()["Location Entrance"]->SetText(field->GetLocationEntrance());
	windowBuilders_["FieldProp"]->GetEntry()["Texture"]->SetText(field->GetTextureID());

	tempField_ = field;
	dataMgr_ = dataMgr;
}

void ActionWindow::CloseFieldProperties()
{
	CloseWindow("FieldProp");

	tempField_ = nullptr;
}

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

bool CheckEntryChanges(const std::string& entry, const std::string& current)
{
	if (entry != current)
		return true;
	else if (entry == current)
		return false;
	else if (is_number(entry))
		return false;
}

void ActionWindow::FieldPropertiesOk()
{
	tempField_->SetType(windowBuilders_["FieldProp"]->GetEntry()["Type"]->GetText());
	tempField_->GetSprite().setPosition(atof(windowBuilders_["FieldProp"]->GetEntry()["Position x"]->GetText().toAnsiString().c_str()),
		atof(windowBuilders_["FieldProp"]->GetEntry()["Position y"]->GetText().toAnsiString().c_str()));
	tempField_->SetTrack(atoi(windowBuilders_["FieldProp"]->GetEntry()["Track"]->GetText().toAnsiString().c_str()));

	tempField_->IsChangingTrack(CheckEntryChanges(windowBuilders_["FieldProp"]->GetEntry()["First Track"]->GetText(), std::to_string(tempField_->GetFirstTrack())));
	tempField_->IsChangingTrack(CheckEntryChanges(windowBuilders_["FieldProp"]->GetEntry()["Second Track"]->GetText(), std::to_string(tempField_->GetSecondTrack())));
	tempField_->SetFirstTrack(atoi(windowBuilders_["FieldProp"]->GetEntry()["First Track"]->GetText().toAnsiString().c_str()));
	tempField_->SetSecondTrack(atoi(windowBuilders_["FieldProp"]->GetEntry()["Second Track"]->GetText().toAnsiString().c_str()));
	
	tempField_->IsEndingTrack(CheckEntryChanges(windowBuilders_["FieldProp"]->GetEntry()["Next Track"]->GetText(), std::to_string(tempField_->GetNextTrack())));
	tempField_->SetNextTrack(atoi(windowBuilders_["FieldProp"]->GetEntry()["Next Track"]->GetText().toAnsiString().c_str()));

	tempField_->IsPassingNextLocation(CheckEntryChanges(windowBuilders_["FieldProp"]->GetEntry()["Next Location"]->GetText(), std::to_string(tempField_->GetNextLocation())));
	tempField_->IsPassingNextLocation(CheckEntryChanges(windowBuilders_["FieldProp"]->GetEntry()["Location Entrance"]->GetText(), tempField_->GetLocationEntrance()));

	tempField_->SetNextLocation(atoi(windowBuilders_["FieldProp"]->GetEntry()["Next Location"]->GetText().toAnsiString().c_str()));
	tempField_->SetLocationEntrance(windowBuilders_["FieldProp"]->GetEntry()["Location Entrance"]->GetText());

	tempField_->SetTextureID(windowBuilders_["FieldProp"]->GetEntry()["Texture"]->GetText());
	tempField_->GetSprite().setTexture(dataMgr_->GetTexture(tempField_->GetTextureID()));

	CloseFieldProperties();
}

void ActionWindow::CloseLoadMap()
{
	CloseWindow("LoadMap");
	windowBuilders_["LoadMap"]->GetEntry()["LoadMap"]->SetText("");
}

void ActionWindow::LoadMap()
{
	std::string source = "Maps/" + windowBuilders_["LoadMap"]->GetEntry()["LoadMap"]->GetText() + ".txt";
	
	if (FileExists(source))
	{
		mapLoader_.LoadMap(source.c_str());
		CloseLoadMap();

		mapMgr_->ResetCurrentKey();
		Update();
	}
	else std::cout << "LoadMap(): Wrong source or file doesn't actually exsist" << std::endl;
}

void ActionWindow::CloseSaveMap()
{
	CloseWindow("SaveMap");
	windowBuilders_["SaveMap"]->GetEntry()["SaveMap"]->SetText("");
}

void ActionWindow::SaveMap()
{
	std::string source = "Maps/" + windowBuilders_["SaveMap"]->GetEntry()["SaveMap"]->GetText() + ".txt";
	mapLoader_.SaveMap(source.c_str());
	CloseSaveMap();
}

void Action::NewLocation()
{
	if (mapMgr_)
	{
		mapMgr_->GetCurrentLocation()->GetFields().clear();
		mapMgr_->GetCurrentLocation()->SetCameraPosition(0, 0);
		mapMgr_->Clear();

	}
	else std::cout << "ERROR: No Map Manager loaded" << std::endl;
}

void Action::SetConsole(Console * console)
{
	console_ = console;
}

void Action::SetFieldMgr(FieldMgr * fieldMgr)
{
	fieldMgr_ = fieldMgr;
}

void Action::SetNPCMgr(NPCMgr * npcMgr)
{
	npcMgr_ = npcMgr;
}


void ActionWindow::OpenWindow(const std::string & windowID)
{
	if (!windowBuilders_.empty())
		if (windowBuilders_[windowID] != nullptr)
			if (windowBuilders_[windowID]->GetWindow()->GetWindow()->IsLocallyVisible() == false)
			{
				windowBuilders_[windowID]->GetWindow()->GetWindow()->Show(true);
				windowMgr_->SetWindowOpened(true);
			}
			else std::cout << "OpenWindow(): window is actually opened" << std::endl;
		else throw exception("OpenWindow(): windowBuilders keys is invalid");
	else throw exception("OpenWindow(): windowBuilders is empty");
}
void ActionWindow::CloseWindow(const std::string & windowID)
{
	if (!windowBuilders_.empty())
		if (windowBuilders_[windowID] != nullptr)
			if (windowBuilders_[windowID]->GetWindow()->GetWindow()->IsLocallyVisible() == true)
			{
				windowBuilders_[windowID]->GetWindow()->GetWindow()->Show(false);
				windowMgr_->SetWindowOpened(false);
			}
			else std::cout << "CloseWindow(): window is actually closed" << std::endl;
		else throw exception("CloseWindow(): windowBuilders keys is invalid");
	else throw exception("CloseWindow(): windowBuilders is empty");
}

void ActionWindow::NPCTemplateLeft()
{
	int id = atoi(windowBuilders_["NPCTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str());
	if (id > 1)
	{
		id--;
		windowBuilders_["NPCTempTool"]->GetLabel()["ID"]->SetText(to_string(id));
	}
}

void ActionWindow::NPCTemplateRight()
{
	int id = atoi(windowBuilders_["NPCTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str());
	if (id < npcMgr_->GetNPCBarSize())
	{
		id++;
		windowBuilders_["NPCTempTool"]->GetLabel()["ID"]->SetText(to_string(id));
	}
}

void ActionWindow::NPCTemplateCopy()
{
	CloseWindow("NPCTempTool");
	mapMgr_->IsWaitingForNPCSelection(true);
}

void ActionWindow::NPCTemplateClose()
{
	CloseWindow("NPCTempTool");
}

void ActionWindow::FieldTemplateLeft()
{
	int id = atoi(windowBuilders_["FieldTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str());
	if (id > 1)
	{
		id--;
		windowBuilders_["FieldTempTool"]->GetLabel()["ID"]->SetText(to_string(id));
	}
}

void ActionWindow::FieldTemplateRight()
{
	int id = atoi(windowBuilders_["FieldTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str());
	if (id < fieldMgr_->GetFieldBarSize())
	{
		id++;
		windowBuilders_["FieldTempTool"]->GetLabel()["ID"]->SetText(to_string(id));
	}
}

void ActionWindow::CloseFieldTemplate()
{
	CloseWindow("FieldTempTool");
}

void ActionWindow::LoadFieldTemplate()
{
	int it = atoi(windowBuilders_["FieldTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str()) - 1;

	fieldMgr_->GetFieldTemplate(it).SetType(windowBuilders_["FieldTempTool"]->GetEntry()["Type"]->GetText());
	fieldMgr_->GetFieldTemplate(it).SetTextureID(windowBuilders_["FieldTempTool"]->GetEntry()["Texture"]->GetText());
	fieldMgr_->GetFieldTemplate(it).GetSprite().setTexture(dataMgr_->GetTexture(fieldMgr_->GetFieldTemplate(it).GetTextureID()));

	CloseWindow("FieldTempTool");
}

void ActionWindow::CopyFieldTemplate()
{
	CloseWindow("FieldTempTool");
	mapMgr_->IsWaitingForFieldSelection(true);
		
}

void ActionWindow::LoadTexture()
{
	std::string id = windowBuilders_["TextureLoading"]->GetEntry()["Id"]->GetText();
	if (dataMgr_ && id != "NO_GRAPHIC")
	{
		dataMgr_->LoadTexture(id, windowBuilders_["TextureLoading"]->GetEntry()["Source"]->GetText());

		for (mapMgr_->GetNPCsIT() = mapMgr_->GetNPCs().begin(); mapMgr_->GetNPCsIT() != mapMgr_->GetNPCs().end(); mapMgr_->GetNPCsIT()++)
			if (mapMgr_->GetNPCsIT()->GetTextureID() == id)
			{
				mapMgr_->GetNPCsIT()->SetTextureID(id);
				mapMgr_->GetNPCsIT()->GetSprite().setTexture(dataMgr_->GetTexture(mapMgr_->GetNPCsIT()->GetTextureID()));
			}

		for (auto itLoc = mapMgr_->GetLocations().begin(); itLoc != mapMgr_->GetLocations().end(); itLoc++)
			for (auto it = itLoc->second.GetFields().begin(); it != itLoc->second.GetFields().end(); it++)
				if (it->GetTextureID() == id)
				{
					it->SetTextureID(id);
					it->GetSprite().setTexture(dataMgr_->GetTexture(it->GetTextureID()));
				}

	}
}

void ActionWindow::RemoveTexture()
{
	std::string id = windowBuilders_["TextureLoading"]->GetEntry()["Id"]->GetText();

	if (dataMgr_ && id != "NO_GRAPHIC")
	{
		for (mapMgr_->GetNPCsIT() = mapMgr_->GetNPCs().begin(); mapMgr_->GetNPCsIT() != mapMgr_->GetNPCs().end(); mapMgr_->GetNPCsIT()++)
			if (mapMgr_->GetNPCsIT()->GetTextureID() == id)
			{
				mapMgr_->GetNPCsIT()->GetSprite().setTexture(dataMgr_->GetTexture("NO_GRAPHIC"));
				mapMgr_->GetNPCsIT()->SetTextureID("NO_GRAPHIC");
			}

		for (auto itLoc = mapMgr_->GetLocations().begin(); itLoc != mapMgr_->GetLocations().end(); itLoc++)
			for (auto it = itLoc->second.GetFields().begin(); it != itLoc->second.GetFields().end(); it++)
				if (it->GetTextureID() == id)
				{
					it->SetTextureID("NO_GRAPHIC");
					it->GetSprite().setTexture(dataMgr_->GetTexture(it->GetTextureID()));
				}

		dataMgr_->RemoveTexture(id);
	}
}

void ActionWindow::CloseTextureLoading()
{
	CloseWindow("TextureLoading");

	windowBuilders_["TextureLoading"]->GetEntry()["Id"]->SetText("");
	windowBuilders_["TextureLoading"]->GetEntry()["Source"]->SetText("");
}




void ActionWindow::LoadSound()
{
	dataMgr_->LoadSound(windowBuilders_["SoundLoading"]->GetEntry()["Id"]->GetText(), windowBuilders_["SoundLoading"]->GetEntry()["Source"]->GetText());
}
void ActionWindow::RemoveSound()
{
	std::string id = windowBuilders_["SoundLoading"]->GetEntry()["Id"]->GetText();;

	dataMgr_->RemoveSound(id);
}
void ActionWindow::CloseSoundLoading()
{
	CloseWindow("SoundLoading");

	windowBuilders_["SoundLoading"]->GetEntry()["Id"]->SetText("");
	windowBuilders_["SoundLoading"]->GetEntry()["Source"]->SetText("");
}
