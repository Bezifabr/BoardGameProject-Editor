/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MenuBase.h
// Purpose: Contains Menu class used in menu building process from MenuMgr.h file.
// It is a part of builder pattern.
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


class gui::Menu
{
public:
	/////////////////////////
	/// CTOR
	///
	/////////////////////////
	Menu();

	/////////////////////////
	/// CTOR
	///
	/// \param label - std::string type, label of parrent button
	/// 
	/////////////////////////
	Menu(std::string label);

	/////////////////////////
	/// DTOR
	///
	/////////////////////////
	~Menu() {}

	/////////////////////////
	/// Adds child button to back of vector
	///
	/// \param button - pointer to sfg::Button
	///
	/////////////////////////
	void AddChild(sfg::Button::Ptr button);

	/////////////////////////
	/// Sets new parent button
	///
	/// \param button - pointer to sfg::Button
	///
	/////////////////////////
	void SetParent(sfg::Button::Ptr button) { menuButton_ = button; }

	/////////////////////////
	/// Deletes child button from back of vector
	///
	////////////////////////
	void PopChild() { buttons_.pop_back(); }

	////////////////////////
	/// Set up wraping and unwraping signals
	/// 
	/// Use it for every created menu
	/// 
	////////////////////////
	void SetHandledInput();

	////////////////////////
	/// Returns parent button
	/// 
	/// \return sfg::Button::Ptr
	///
	////////////////////////
	sfg::Button::Ptr GetParent() { return menuButton_; }

	////////////////////////
	/// Returns child button
	/// 
	/// \param buttonsIT - uint8_t type iterator to child's vector
	/// \return sfg::Button::Ptr
	///
	////////////////////////
	sfg::Button::Ptr GetChild(uint8_t buttonsIT) { return buttons_[buttonsIT]; }

	////////////////////////
	/// Returns child's buttons vector
	/// 
	/// \return sfg::Button::Ptr
	///
	////////////////////////
	std::vector<sfg::Button::Ptr> GetChildren() { return buttons_; }

	////////////////////////
	/// Sets label string
	///
	/// \param label - std::string type, new text of label
	///
	////////////////////////
	void SetLabel(std::string label) { menuButton_->SetLabel(label); }

	///////////////////////
	/// Sets position of menu
	///
	/// \param Position - sf::Vector2f type, new static position of menus
	///
	///////////////////////
	void SetPosition(sf::Vector2f Position) { position_ = Position + sf::Vector2f(-150, -150); }

	///////////////////////
	/// Sets position of menu
	///
	/// \param x - float type, new static x position of menus
	/// \param y - float type, new static y position of menus
	///
	///////////////////////
	void SetPosition(float x, float y) { position_ = sf::Vector2f(x - 150, y - 150); }

	///////////////////////
	/// Connects application window to menus
	///
	/// \param window - AppWindow* type, pointer to application window from main.cpp file
	///
	///////////////////////
	void SetAppWindow(AppWindow* window) { window_ = window; }

	///////////////////////
	/// Sets isMenuOpened boolean variable
	///
	/// \param isOpened - new value of boolean variable
	///
	///////////////////////
	void IsMenuOpened(bool isOpened) { isMenuOpened_ = isOpened; }

	///////////////////////
	/// Returns isMenuOpened boolean variable
	///
	///////////////////////
	bool IsMenuOpened() { return isMenuOpened_; }
private:
	typedef std::vector<sfg::Button::Ptr> ButtonVector;
	ButtonVector buttons_;

	sfg::Button::Ptr menuButton_;

	static sf::Vector2f position_;
	AppWindow* window_;

	void UnWrap();
	void Wrap();
	void WrapInstantly();

	bool isMenuOpened_;
};