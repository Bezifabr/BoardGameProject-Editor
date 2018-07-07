/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WindowMgr.h
// Purpose: Contains WindowMgr class which handles operations of creating and initializing windows.
// It also contains classes derived from Window base class.
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
#include "WindowBuilder.h"


// TODO : Make better menu constructing system
class WNDLoadMap : public gui::WindowBuilder
{
public:
	virtual ~WNDLoadMap() {};
	virtual sfg::Window::Ptr Create();
};
class WNDSaveMap : public gui::WindowBuilder
{
public:
	
	virtual ~WNDSaveMap() {};
	virtual sfg::Window::Ptr Create();
};
class WNDFieldProperties : public gui::WindowBuilder
{
public:
	virtual ~WNDFieldProperties() {};
	virtual sfg::Window::Ptr Create();
}; 

class WNDLocationsProperties : public gui::WindowBuilder
{
public:
	virtual ~WNDLocationsProperties() {};
	virtual sfg::Window::Ptr Create();
};
class WNDLocations : public gui::WindowBuilder
{
public:
	virtual ~WNDLocations() {};
	virtual sfg::Window::Ptr Create();
};
class WNDLocationMove : public gui::WindowBuilder
{
public:
	virtual ~WNDLocationMove() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Properties : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Properties() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Stats : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Stats() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Spells : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Spells() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Armor : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Armor() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Inventory : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Inventory() {};
	virtual sfg::Window::Ptr Create();
};
class WND_NPC_Position : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Position() {};
	virtual sfg::Window::Ptr Create();
};/*
class WND_NPC_Graphics : public gui::WindowBuilder
{
public:
	virtual ~WND_NPC_Graphics() {};
	virtual sfg::Window::Ptr Create();
};*/
class WND_REALLY_CLOSE : public gui::WindowBuilder
{
public:
	virtual ~WND_REALLY_CLOSE() {};
	virtual sfg::Window::Ptr Create();
};
class WNDTextureLoading : public gui::WindowBuilder
{
public:
	virtual ~WNDTextureLoading() {};
	virtual sfg::Window::Ptr Create();
};
class WNDSoundLoading : public gui::WindowBuilder
{
public:
	virtual ~WNDSoundLoading() {};
	virtual sfg::Window::Ptr Create();
};
class WNDFieldTempTool : public gui::WindowBuilder
{
public:
	virtual ~WNDFieldTempTool() {};
	virtual sfg::Window::Ptr Create();
};
class WNDNPCTempTool : public gui::WindowBuilder
{
public:
	virtual ~WNDNPCTempTool() {};
	virtual sfg::Window::Ptr Create();
};


class WindowMgr
{
public:
	
	/*
	It is the main function of this manager
	Creates instance of derived class from the Window class
	*/
	void CreateWindow(gui::WindowBuilder* wb)
	{
		windowBuilder_ = wb;
		windowBuilder_->CreateNewWindow();
		windowBuilder_->GetWindow()->SetWindow(windowBuilder_->Create());

	}

	/*
	Returns isWindowOpened boolean variable
	*/
	bool IsWindowOpened() { return isWindowOpened_; }

	/*
	Sets isWindowOpened boolean variable
	*/
	void SetWindowOpened(bool isWindowOpened) { isWindowOpened_ = isWindowOpened; }
private:
	bool isWindowOpened_;
	gui::WindowBuilder* windowBuilder_;
};