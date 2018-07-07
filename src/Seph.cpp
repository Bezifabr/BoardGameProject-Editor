/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Seph.cpp
// Purpose: Contains defitions of methods from Seph class derived from Player base class.
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
#include "Player.h"
#include "Constants.h"


void Seph::Default()
{
	SetStrength(3);
	SetAgility(3);
	SetEndurance(5);
	SetIntelligence(7);
	SetSpeed(7);
}

void Seph::Initiate()
{
	levelCap_ = DEFAULT_LEVEL_CAP;
	SetLevel(1);
	SetRequiredExp(500);
	Default();
}
