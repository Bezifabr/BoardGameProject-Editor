/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuEdit.cpp
// Purpose: Contains definition of Create() method from MenuEdit class.
// This menu contains: copy, paste, reset camera
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

void MenuEdit::Create()
{
	GetMenu()->SetLabel(M_EDIT);
	AddMenuOption(M_EDIT_COPY, std::bind(&ActionMenu::Nothing, action_));
	AddMenuOption(M_EDIT_PASTE, std::bind(&ActionMenu::Nothing, action_));
	AddMenuOption(M_EDIT_RESET_CAM, std::bind(&ActionMenu::ResetCamera, action_));

}
