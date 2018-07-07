/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WindowBase.h
// Purpose: Contains Window class used in window building process from WindowMgr.h file.
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
#include "GUI.h"


class gui::Window
{
public:
	///////////////////////
	/// Sets window
	///
	/// \param window - sfgui window pointer
	///
	///////////////////////
	void SetWindow(sfg::Window::Ptr& window)
	{
		window_ = window;
	}

	///////////////////////
	/// Returns sfgui window pointer
	///
	///////////////////////
	sfg::Window::Ptr GetWindow()
	{
		return window_;
	}
private:
	sfg::Window::Ptr window_;
};