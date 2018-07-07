/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MapMgr.h
// Purpose: Containes loaded map data. Handles operations on locations.
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
#include "Location.h"
#include "Console.h"
#include <iostream>

class FieldMgr;

class MapMgr
{
public:
	/////////////////////////////
	/// Constructor
	///
	/////////////////////////////
	MapMgr() {}

	/////////////////////////////
	/// Destructor
	///
	/////////////////////////////
	~MapMgr() {}

	////////////////////////////
	/// Adds new location to the map of locations
	///
	/// \param key - key of location in the map container
	///
	/// Checks if the key isn't already in use
	///
	////////////////////////////
	void NewLocation(std::string key);
	
	////////////////////////////
	/// Adds a previously created location to the map of locations
	///
	/// \param key - key of the location in the map container
	/// \param location - reference to the location
	/// 
	/// Checks if the key isn't already in use
	/// 
	////////////////////////////
	void AddLocation(std::string key, Location& location);

	///////////////////////////
	/// Removes current location
	///
	/// if amount of the locations is higher than 1 or current location is not 0
	/// To change current location call Next() or Previous() method
	/// 
	///////////////////////////
	void RemoveLocation();

	///////////////////////////
	/// Increments current location
	///
	/// if the current location is not the last it will work
	/// The location can be also changed by call Previous() method
	///
	///////////////////////////
	void Next();

	///////////////////////////
	/// Decrements current location
	///
	/// if the current location is not the first it will work
	/// The location can be also changed by call Next() method
	///
	///////////////////////////
	void Previous();

	///////////////////////////
	/// Sets current location's key and the location to 0
	///
	///
	///////////////////////////
	void ResetCurrentKey();

	///////////////////////////
	/// Returns vector of the keys locations
	///
	///////////////////////////
	std::vector<std::string> GetLocationsKeys();

	///////////////////////////
	/// Sets current location key
	///
	/// \param key - key of new current location
	/// 
	///////////////////////////
	void SetCurrentLocation(std::string key);

	///////////////////////////
	/// Returns current location pointer
	///
	///////////////////////////
	Location* GetCurrentLocation();

	///////////////////////////
	/// Returns map of locations
	///
	///////////////////////////
	std::map<std::string, Location>& GetLocations();

	///////////////////////////
	/// Clears location manager:
	/// - npcs
	/// - locations
	/// - locations keys
	///
	///////////////////////////
	void Clear();

	////////////////////////////
	/// Returns current location key
	///
	////////////////////////////
	size_t GetCurrentLocationKey();

	////////////////////////////
	/// Sets source of map file
	///
	/// \param source - source of map file
	///
	////////////////////////////
	void SetSource(const char* source);

	////////////////////////////
	/// Returns source of map file
	///
	////////////////////////////
	std::string GetSource();

	////////////////////////////
	/// Sets pointer to DataMgr object
	///
	/// \param data - DataMgr* type object
	///
	////////////////////////////
	void SetData(DataMgr* data);

	////////////////////////////
	/// Sets pointer to InputMgr object
	///
	/// \param input - InputMgr* type object
	///
	////////////////////////////
	void SetInput(InputMgr* input);

	////////////////////////////
	/// Replaces the current location with the next
	///
	/// \param current - number of the current location
	/// \param next - number of the next location
	///
	////////////////////////////
	void ReplaceLocationWith(int current, int next);

	////////////////////////////
	/// Moves the current location to the next
	///
	/// \param current - number of the current location
	/// \param next - number of the next location
	///
	////////////////////////////
	void MoveLocationTo(int current, int next);

	////////////////////////////
	/// Sets pointer to AppWindow object
	///
	/// \param appWindow - AppWindow* type object
	///
	///////////////////////////
	void DrawCurrentLocation(AppWindow* appWindow);

	///////////////////////////
	/// Returns vector of NPC classes objects
	///
	//////////////////////////
	std::vector<NPC>& GetNPCs();

	//////////////////////////
	/// Returns iterator of NPC classes vector
	///
	/// This is the first one used in every 
	/// 
	//////////////////////////
	std::vector<NPC>::iterator& GetNPCsIT();

	//////////////////////////
	/// Clears vector of NPC objects and copies npcs from other vector
	///
	/// \param npcs - reference to second vector of NPC objects
	///
	/////////////////////////
	void SetNPCs(std::vector<NPC>& npcs);

	/////////////////////////
	/// Changes name of the current location
	///
	/// \param name - new name of the current location
	///
	/////////////////////////
	void ChangeCurrentName(std::string name);
	
	/////////////////////////
	/// Changes location of NPCs
	/// Copies all NPC from current location to the next
	///
	/// \param currentLoc - number of current location NPC object's vector
	/// \param nextLoc - number of next location of NPC object's vector
	///
	/// Used in locations replacing 
	///
	/////////////////////////
	void ReplaceNPCs(size_t currentLoc, size_t nextLoc);

	/////////////////////////
	/// Sets waitingForFieldSelect_ boolean value
	///
	/// \param isWaiting - new boolean value of waitingForFieldSelect_ variable
	///
	/////////////////////////
	void IsWaitingForFieldSelection(bool isWaiting);

	/////////////////////////
	/// Returns waitingForFieldSelect_ boolean value
	///
	/// \return boolean value of waitingForFieldSelect_ variable
	///
	/// When user selects field this variable will change to false
	/// Field templates window will be opened
	/// And values of the Field object will be entered
	///
	/////////////////////////
	bool IsWaitingForFieldSelection();

	/////////////////////////
	/// Sets waitingForNPCSelect_ boolean value
	///
	/// \param isWaiting - new boolean value of waitingForNPCSelect_ variable
	///
	/////////////////////////
	void IsWaitingForNPCSelection(bool isWaiting);

	/////////////////////////
	/// Returns waitingForNPCSelect_ boolean value
	///
	/// \return boolean value of waitingForNPCSelect_ variable
	///
	/// When user selects NPC object this variable will change to false
	/// NPC templates window will be opened
	/// And values of the NPC object will be entered
	///
	/////////////////////////
	bool IsWaitingForNPCSelection();

	/////////////////////////
	/// Returns reference to GameObjects class object
	/// It handles items, skills and effects
	///
	/// \return GameObjects& class object
	///
	/////////////////////////
	GameObjects& GetGameObjects();
private:
	std::vector<std::string> locationsKeys_;
	std::vector<std::string>::iterator locationsKeysIT_;
	size_t currentLocationKeyNumber_;
	std::string currentLocationKey_;

	std::vector<std::string>::iterator& GetIteratorToCurrentKey();
	std::map<std::string, Location> locations_;

	std::string source_;

	bool waitingForFieldSelect_ = false;
	bool waitingForNPCSelect_ = false;

	DataMgr* data_;
	InputMgr* input_;
	GameObjects gameObjects_;

	typedef std::vector<NPC> NPCContainer;
	typedef NPCContainer::iterator NPCIterator;
	NPCContainer npcs_;
	NPCIterator npcIT_;

	bool IsStringAvailable(std::vector<std::string> stringVector, std::string stringValue);
};