/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// NPCMgr.h
// Purpose: Handles operations on the NPCs
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
#include "MapLoader.h"
#include <iostream>

//////////////////////////
/// NPC Manager class
/// Contains NPCs utilities
//////////////////////////
class NPCMgr
{
	typedef std::vector<NPC> NPCContainer;
	typedef NPCContainer::iterator NPCIterator;
	
public:
	NPCMgr() {};
	~NPCMgr() {};

	//////////////////
	/// Initialize NPC Manager
	///
	/// Sets NPC placing tool templates
	/// Defines variables
	///
	/// \param data - Pointer to DataMgr object
	/// \param mapMgr - Pointer to MapMgr* object
	/// \param input - Pointer to InputMgr object
	/// \param appWindow - Pointer to AppWindow object
	///
	//////////////////
	void Init(DataMgr* data, MapMgr* mapMgr, InputMgr* input, AppWindow* appWindow);

	//////////////////
	/// Returns number of NPC templates
	///
	/// \return size of NPCBar vector
	///
	//////////////////
	size_t GetNPCBarSize();
	
	//////////////////
	/// Returns template NPC 
	///
	/// \param ID - Number of NPC in vector 
	/// \return 	reference to NPC class object
	///
	//////////////////
	NPC& GetNPCTemplate(int ID);

	//////////////////
	/// Checks if NPC templates vector is empty
	///
	/// \return NPCBar empty() method returned value
	///
	//////////////////
	bool IsNPCBarEmpty();

	//////////////////
	/// Checks if one of NPCs is selected
	///
	/// \return value of isNPCSelected_ boolean variable
	///
	//////////////////
	bool IsNPCSelected();

	//////////////////
	/// Draws NPC placing tool
	///
	/// is tool is selected
	///
	//////////////////
	void DrawTool();

	//////////////////
	/// Main NPC Manager update method
	///
	/// Handles mouse input
	/// Calls utility methods
	///
	//////////////////
	void Update();

	//////////////////
	/// Sets NPC's sprite position
	///
	//////////////////
	void ChangePosition();

	/////////////////////
	/// Loads template NPC
	/// They are used in NPC placing tool
	///
	/// \param source - source of text file with NPCs scripts
	///
	/////////////////////
	void LoadNPCFromFile(const char* source);
private:

	NPCContainer npcsBar_;
	NPC currentNPC_;
	DataMgr* data_;
	MapMgr* mapMgr_;
	InputMgr* input_;
	AppWindow* appWindow_;

	int selectedNPC_;
	int selectedTool_;
	bool isNPCGrabbed_ = false;
	bool isNPCToolSelected_ = false;
	bool isNPCSelected_ = false;
	sf::Vector2f mouse_prev_location_;
	sf::Vector2i npc_prev_location_;

	bool canClick_;

	sf::Clock clickTimer_;

	bool engineSet_;

	void AddNPCType(std::string type);

	bool IsPositionOccupied(int position, std::vector<NPC>& npcs);

	void DeleteNPC();
	void PlaceNPC();
	void MoveNPC();
	void SelectNPC();
	void UnselectNPC();
	void GUIUpdate();
	void ChangeTool();
};

//////////////////////////////////////////////////////////
/// \NPC Manager class
/// Contains NPCs utilities
///
/// \Main tasks of the class:
/// This class works only on pointers to containers
///
/// \Class initializing
/// To start using this class call Init() method
/// 
/// \Adding NPC manager methods to main loop
/// Call Update() method to handle events and call inner methods
/// 
/// 
//////////////////////////////////////////////////////////