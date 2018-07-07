/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuFile.cpp
// Purpose: Contains definition of Create() method from MenuFile class.
// This menu contains: new map, open map, save map, save map as, quit
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

void MenuFile::Create()
{
	GetMenu()->SetLabel(M_FILE);
	AddMenuOption(M_FILE_NEW, std::bind(&ActionMenu::NewLocation, action_));
	AddMenuOption(M_FILE_OPEN, std::bind(&ActionMenu::OpenLoadMap, action_));
	AddMenuOption(M_FILE_SAVE, std::bind(&ActionMenu::OpenSaveMap, action_));
	AddMenuOption(M_FILE_SAVEAS, std::bind(&ActionMenu::OpenSaveAsMap, action_));
	AddMenuOption(M_FILE_QUIT, std::bind(&ActionMenu::OpenReallyClose, action_));
}