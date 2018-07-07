/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// GUI.h
// Purpose: Connects all gui classes with all action classes
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////
#pragma once

#include <SFGUI\Widgets.hpp>
#include "Constants.h"
#include <memory>

namespace gui
{
	class Window;
	class Menu;
	class MenuBuilder;
	class WindowBuilder;
}
class Action;
class ActionMenu;
class ActionWindow;

#include "AppWindow.h"