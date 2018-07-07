/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// GUIMgr.h
// Purpose: Handles the editor graphic interface. Initiates starting settings and handles input.
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
#include "Action.h"



class GUIMgr
{
public:
	//////////////////
	/// CTOR
	///
	//////////////////
	GUIMgr() {}

	//////////////////
	/// DTOR
	///
	//////////////////
	~GUIMgr() { windowBuilders_.clear(); }

	//////////////////
	/// Initialize all GUI settings
	///
	/// \param desktop - Pointer to sfg::Desktop object
	/// \param window - Pointer to AppWindow object
	/// \param mapMgr - Pointer to MapMgr object
	/// \param data - Pointer to DataMgr object
	///
	//////////////////
	void Init(sfg::Desktop* desktop, AppWindow* window, MapMgr* mapMgr, DataMgr* data, FieldMgr* fieldMgr, NPCMgr* npcMgr);

	////////////////////////////
	/// Sets pointer to Console object
	///
	/// \param console - Console* type object
	///
	////////////////////////////
	void SetConsole(Console* console);

	//////////////////
	/// Handles GUI events
	///
	/// \param event - Referrence to sf::Event object
	///
	/// Called in StateMgr::Update() method
	///
	//////////////////
	void HandleEvents(sf::Event& event);

	//////////////////
	/// Returns referrence to ActionWindow object
	///
	/// \return ActionWindow referrence
	///
	//////////////////
	ActionWindow& GetActionWindow();

	//////////////////
	/// Returns true if window is opened
	///
	/// \return isWindowOpened_ variable boolean value
	///
	//////////////////
	bool IsWindowOpened();

	//////////////////
	/// Returns true if one of menus is opened
	///
	/// \return isOpened boolean value
	///
	//////////////////
	bool IsMenuOpened();
private:
	typedef std::map<std::string, gui::WindowBuilder*> WBMap;
	typedef std::map<std::string, gui::MenuBuilder*> MBMap;


	void InitiateGUI();
	void AddToDesktop();
	void InitiateGUIElements();
	void CopyingFieldTemp(sf::Event& event);
	void CopyingNPCTemp(sf::Event& event);

	WindowMgr windowMgr_;		//<< Manager of windows (Creates them, adds Action and AppWindow clases)
	WNDLoadMap windowLoadMap_;
	WNDSaveMap windowSaveMap_;
	WNDLocations windowLocations_;
	WNDFieldProperties windowFieldProperties_;
	WNDLocationsProperties windowLocationProperties_;
	WNDLocationMove windowLocationMove_;
	WND_NPC_Properties windowNPCCreating_;
	WND_NPC_Stats windowNPCStats_;
	WND_NPC_Spells windowNPCSpells_;
	WND_NPC_Armor windowNPCArmor_;
	WND_NPC_Inventory windowNPCInventory_;
	WND_NPC_Position windowNPCPosition_;
	WND_REALLY_CLOSE windowReallyClose_;
	WNDTextureLoading windowTextureLoading_;
	WNDSoundLoading windowSoundLoading_;
	WNDFieldTempTool windowFieldTempTool_;
	WNDNPCTempTool windowNPCTempTool_;

	MenuMgr menuMgr_;			//<< Manager of menus (Creates them, adds Action and AppWindow clases)
	MenuFile menuFile_;
	MenuEdit menuEdit_;
	MenuTools menuTools_;
	MenuHelp menuHelp_;

	ActionMenu actionMenu_;		 //<< Actions for menus
	ActionWindow actionWindow_;  //<< Actions for windows

	// Containers
	WBMap windowBuilders_; //<< Windows container
	MBMap menuBuilders_;   //<< Menus container

	sfg::Desktop* desktop_; //<< Pointer to Desktop object (rendering engine)
	AppWindow* window_;     //<< Pointer to AppWindow object (application window)
	MapMgr* mapMgr_;		//<< Pointer to MapMgr object (map manager)
	DataMgr* data_;			//<< Pointer to DataMgr object (data manager)
	FieldMgr* fieldMgr_;	//<< Pointer to FieldMgr object (fields manager)
	NPCMgr* npcMgr_;		//<< Pointer to NPCMgr object (NPCs manager)

};