/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuBuilder.h
// Purpose: Contains MenuBuilder class that creates unique object of Menu class from MenuBase.h file.
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
#include "MenuBase.h"


class gui::MenuBuilder
{
public:
	virtual ~MenuBuilder() {};

	///////////////////////
	/// Returns pointer to Menu object
	///
	///////////////////////
	Menu* GetMenu()
	{
		return menu_.get();
	}

	///////////////////////
	/// Creates new menu
	///
	///////////////////////
	void CreateNewMenu()
	{
		menu_ = std::make_unique<Menu>();
	}

	///////////////////////
	/// Sets pointer to ActionMenu object
	///
	/// \param actionMenu - pointer to ActionMenu object
	///
	///////////////////////
	void SetAction(ActionMenu* actionMenus)
	{
		action_ = actionMenus;
	}

	//////////////////////
	/// Sets pointer to AppWindow object
	///
	/// \param window - pointer to AppWindow object
	///
	//////////////////////
	void SetAppWindow(AppWindow* window) 
	{ 
		GetMenu()->SetAppWindow(window); 
	}

	virtual void Create() = 0;
protected:
	std::unique_ptr<Menu> menu_;

	ActionMenu* action_;

	void AddMenuOption(std::string buttonLabel, std::function<void()> delegate)
	{
		auto button = sfg::Button::Create(buttonLabel);
		button->GetSignal(sfg::Widget::OnLeftClick).Connect(delegate);
		GetMenu()->AddChild(button);
	}
};

