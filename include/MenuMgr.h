/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuMgr.h
// Purpose: Contains MenuMgr class which handles operations of creating and initializing menus.
// It also contains classes derived from Menu base class.
// It is a part of building pattern.
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
#include "MenuBuilder.h"


class MenuFile : public gui::MenuBuilder
{
public:
	virtual ~MenuFile() {};

	virtual void Create();
};
class MenuEdit : public gui::MenuBuilder
{
public:
	virtual ~MenuEdit() {};

	virtual void Create();
};
class MenuTools : public gui::MenuBuilder
{
public:
	virtual ~MenuTools() {};

	virtual void Create();
};
class MenuHelp : public gui::MenuBuilder
{
public:
	virtual ~MenuHelp() {};

	virtual void Create();
};

class MenuMgr
{
public:

	/*
	This function connects AppWindow type pointer to the menu class instance
	*/
	void AddAppWindow(AppWindow* window)
	{
		menuBuilder_->GetMenu()->SetAppWindow(window);
	}
	/*
	This function connects ActionMenus type pointer to the menu class instance
	*/
	void AddAction(ActionMenu* am)
	{
		menuBuilder_->SetAction(am);
	}
	/*
	It is the main function of this manager
	Creates instance of derived class from the Menu class

	Call this function before other
	*/
	void CreateMenu(gui::MenuBuilder* mb)
	{
		menuBuilder_ = mb;
		menuBuilder_->CreateNewMenu();
		menuBuilder_->Create();
	}

private:
	gui::MenuBuilder* menuBuilder_;
};