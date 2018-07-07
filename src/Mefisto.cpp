/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Mefisto.cpp
// Purpose: Contains defitions of methods from Mefisto class derived from Player base class.
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


void Mefisto::Default()
{
	SetStrength(3);
	SetAgility(7);
	SetEndurance(5);
	SetIntelligence(3);
	SetSpeed(7);
}

void Mefisto::Initiate()
{
	levelCap_ = DEFAULT_LEVEL_CAP;
	SetLevel(1);
	SetRequiredExp(500);
	Default();
}
