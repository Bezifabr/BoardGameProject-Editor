/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MapLoader.h
// Purpose: Handles map loading methods. It works on pointer to mapMgr class.
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
#include "MapMgr.h"


class MapLoader
{
public:
	/////////////////
	/// Initialize pointers
	///
	/// \param mapMgr - pointer to MapMgr object
	/// \param data - pointer to DataMgr object
	///
	/////////////////
	void Init(MapMgr* mapMgr, DataMgr* data);

	/////////////////
	/// Returns IsLoaded boolean value
	///
	/////////////////
	bool IsLoaded() { return isLoaded_; }

	/////////////////
	/// Sets IsLoaded boolean variable
	///
	/// \param isLoaded - boolean variable
	///
	/////////////////
	void IsLoaded(bool isLoaded) { isLoaded_ = isLoaded; }

	/////////////////
	/// Loads map
	///
	/////////////////
	void LoadMap(const char* source);
	
	/////////////////
	/// Saves map
	///
	/////////////////
	void SaveMap(const char* source);

	/////////////////
	/// Save map
	///
	/////////////////
	void SaveMap(const char* source, bool saveSource);

	/////////////////
	/// Save map
	///
	/////////////////
	void SaveMap(const char* source, std::map<std::string, Location>* map);


private:

	bool saveSource_;
	bool isLoaded_;

	MapMgr* mapMgr_;
	DataMgr* data_;

};