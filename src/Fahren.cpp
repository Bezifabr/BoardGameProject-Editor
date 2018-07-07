/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Fahren.cpp
// Purpose: Contains defitions of methods from Fahren class derived from Player base class.
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


void Fahren::Default()
{
	SetStrength(7);
	SetAgility(3);
	SetEndurance(7);
	SetIntelligence(3);
	SetSpeed(5);
}

void Fahren::Initiate()
{
	levelCap_ = DEFAULT_LEVEL_CAP;
	SetLevel(1);
	SetRequiredExp(500);
	Default();
}
