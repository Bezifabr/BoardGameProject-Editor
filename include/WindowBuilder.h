/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WindowBuilder.h
// Purpose: Contains WindowBuilder class that creates unique object of Window class from WindowBase.h file.
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
#include "WindowBase.h"


class gui::WindowBuilder
{
public:
	virtual ~WindowBuilder() {};

	/////////////////////
	/// Return window
	///
	/// \return sfgui window pointer
	///
	/////////////////////
	gui::Window* GetWindow() { return window_.get(); }

	///////////////////////
	/// Sets pointer to ActionWindow object
	///
	/// \param actionMenu - pointer to ActionMenu object
	///
	///////////////////////
	void SetAction(ActionWindow* action) { action_ = action; }

	/////////////////////
	/// Creates new window
	///
	/////////////////////
	void CreateNewWindow() { window_ = std::make_unique<gui::Window>();	}

	virtual sfg::Window::Ptr Create() = 0;

	/////////////////////
	/// Returns all entries
	///
	/// \return map of sfgui entry pointers
	///
	/////////////////////
	std::map<std::string, sfg::Entry::Ptr>& GetEntry() { return entry_; }

	/////////////////////
	/// Returns all labels
	///
	/// \return map of sfgui label pointers
	///
	/////////////////////
	std::map<std::string, sfg::Label::Ptr>& GetLabel() { return label_; }

	/////////////////////
	/// Returns all combos
	///
	/// \return map of sfgui combos pointers
	///
	/////////////////////
	std::map<std::string, sfg::ComboBox::Ptr>& GetCombo() { return combo_; }

protected:
	std::unique_ptr<gui::Window> window_;
	std::vector<sfg::Button::Ptr> button_;

	ActionWindow* action_;

	std::map<std::string, sfg::Widget::Ptr> widget_;
	std::map<std::string, sfg::Box::Ptr> box_;
	std::map<std::string, sfg::Entry::Ptr> entry_;
	std::map<std::string, sfg::Label::Ptr> label_;
	std::map < std::string, sfg::ComboBox::Ptr> combo_;

	void PackWidget(std::string boxKey, std::string widgetKey, sfg::Widget::Ptr widgetPtr, std::function<void()> delegate);
	void AddWindowOption(std::string boxKey, std::string optionName, sf::Vector2f requisition);
	void AddWindowCombo(std::string boxKey, std::string comboName, sf::Vector2f requisition);
};