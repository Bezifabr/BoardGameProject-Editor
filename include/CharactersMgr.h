/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// CharactersMgr.h
// Purpose: Contains players and NPCs
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
#include "Player.h"
//TODO: Add NPCs to this class and remove from MapMgr
class Characters
{
	typedef std::map<std::string, Player> PlayerMap;
	typedef PlayerMap::iterator PlayerMapIT;
public:
	Characters();
	~Characters();

	Player& GetPlayer(std::string key) { return players_[key]; }

	PlayerMap& GetPlayers() { return players_; }
private:


	PlayerMap players_;
};
