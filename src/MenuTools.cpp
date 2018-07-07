/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuTools.cpp
// Purpose: Contains definition of Create() method from MenuTools class.
// This menu contains nothing by the moment
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
#include "GUIMgr.h"

void MenuTools::Create()
{
	GetMenu()->SetLabel(M_TOOLS);
	AddMenuOption("Texture Loader", std::bind(&ActionMenu::OpenTextureLoading, action_));
//	AddMenuOption("Sound Loader", std::bind(&ActionMenu::OpenSoundLoading, action_));
	AddMenuOption("Field Templates", std::bind(&ActionMenu::OpenFieldTemplate, action_));
	AddMenuOption("NPC Templates", std::bind(&ActionMenu::OpenNPCTemplate, action_));
	AddMenuOption("Console", std::bind(&ActionMenu::OpenConsole, action_));
}
