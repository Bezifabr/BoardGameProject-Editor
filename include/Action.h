/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Action.h
// Purpose: Contains action methods used in graphic user interface.
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
#include "MenuMgr.h"
#include "WindowMgr.h"
#include "FieldMgr.h"
#include "NPCMgr.h"


class Action
{
public:
	Action() {};
	void SetLocationMgr(MapMgr* mapMgr) { mapMgr_ = mapMgr;}
	void Init(MapMgr* mapMgr, DataMgr* data) { dataMgr_ = data; mapMgr_ = mapMgr; mapMgr_->SetData(data); mapLoader_.Init(mapMgr, data); }
	void SetWindowBuilders(std::map<std::string, gui::WindowBuilder*> wb) { windowBuilders_ = wb; }
	void SetWindowsMgr(WindowMgr* windowMgr) { windowMgr_ = windowMgr; }

	void Nothing() {}
	virtual void NewLocation();

	void CloseAppWindow()
	{
		window_->close();
	}
	void SetAppWindow(sf::RenderWindow* window) { window_ = window; }

	void SetConsole(Console* console);
	void SetFieldMgr(FieldMgr* fieldMgr);
	void SetNPCMgr(NPCMgr* npcMgr);
protected:
	WindowMgr* windowMgr_;
	std::map<std::string, gui::WindowBuilder*> windowBuilders_;
	MapMgr* mapMgr_;
	MapLoader mapLoader_;
	DataMgr* dataMgr_ = nullptr;
	sf::RenderWindow* window_;
	FieldMgr* fieldMgr_;
	NPCMgr* npcMgr_;
	Console* console_;
};


class ActionMenu : public Action
{
public:
	ActionMenu() {}
	~ActionMenu() {}

	void NewLocation() override;

	void OpenLoadMap()
	{
		windowBuilders_["LoadMap"]->GetWindow()->GetWindow()->Show(true);
		windowBuilders_["LoadMap"]->GetEntry()["LoadMap"]->GrabFocus();
		windowMgr_->SetWindowOpened(true);
	}

	void OpenSaveMap()
	{
		if (mapLoader_.IsLoaded() == true)
			mapLoader_.SaveMap(mapMgr_->GetSource().c_str());
		else
		{
			windowBuilders_["SaveMap"]->GetWindow()->GetWindow()->Show(true);
			windowBuilders_["SaveMap"]->GetEntry()["SaveMap"]->GrabFocus();
			windowMgr_->SetWindowOpened(true);
		}
	}

	void OpenSaveAsMap()
	{
		windowBuilders_["SaveMap"]->GetWindow()->GetWindow()->Show(true);
		windowBuilders_["SaveMap"]->GetEntry()["SaveMap"]->GrabFocus();
		windowMgr_->SetWindowOpened(true);

	}

	void OpenConsole();

	void OpenFieldTemplate();
	void OpenNPCTemplate();

	void OpenReallyClose();
	void ResetCamera();
	void OpenSoundLoading();
	void OpenTextureLoading();
};


class ActionWindow : public Action
{
public:
	ActionWindow() {}
	~ActionWindow() {}

	void NPCTemplateLeft();
	void NPCTemplateRight();
	void NPCTemplateCopy();
	void NPCTemplateClose();

	void FieldTemplateLeft();
	void FieldTemplateRight();
	void CloseFieldTemplate();
	void LoadFieldTemplate();
	void CopyFieldTemplate();


	void LoadTexture();
	void RemoveTexture();
	void CloseTextureLoading();

	void LoadSound();
	void RemoveSound();
	void CloseSoundLoading();

	void OpenReallyClose();
	void CloseReallyClose();
	void OpenSavingWindowReallyClose();

	void OpenNPCStats();
	void OpenNPCSpells();
	void OpenNPCArmor();
	void OpenNPCInventory();
	void OpenNPCPosition();

	void CloseNPCStats();
	void CloseNPCSpells();
	void CloseNPCArmor();
	void CloseNPCInventory();
	void CloseNPCPosition();

	void OpenNPCProperties(NPC * npc, size_t order, DataMgr * dataMgr);
	void CloseNPCProperties();

	void NPCPropertiesOK();
	void NPCStatsOK();
	void NPCSpellsOK();
	void NPCArmorOK();
	void NPCInventoryOK();
	void NPCPositionOK();

	void LocationMoveOpen();
	void LocationMove();
	void LocationReplace();
	void LocationMoveClose();

	void LocPropLeft();
	void LocPropRight();
	void LocPropCreate();
	void LocPropRemove();
	void OpenLocationProperties();
	void CloseLocationProperties();
	void LocationPropertiesOk();
	void LocationPropertiesApply();

	void PreviousLocation();
	void NextLocation();
	void CreateLocation();
	void DeleteLocation();

	void OpenFieldProperties(Field* field, size_t order, DataMgr* dataMgr);
	void CloseFieldProperties();
	void FieldPropertiesOk();

	void CloseLoadMap();
	void LoadMap();

	void CloseSaveMap();
	void SaveMap();

	void InitAction() { Update(); }

private:
	void Update()
	{
		uint8_t currentLocation = mapMgr_->GetCurrentLocationKey();
		windowBuilders_["locations"]->GetLabel()["Name"]->SetText(mapMgr_->GetLocationsKeys()[currentLocation]);
		windowBuilders_["locations"]->GetLabel()["Number"]->SetText("Location: " + std::to_string(currentLocation));
	}

	void UpdateLocationProperties();

	void OpenWindow(const std::string& windowID);
	void CloseWindow(const std::string& windowID);

	Field* tempField_ = nullptr;
	NPC* tempNPC_ = nullptr;


	inline bool FileExists(const std::string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}
};

