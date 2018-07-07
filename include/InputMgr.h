/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// InputMgr.h
// Purpose: Handles input - keyboard and mouse events.
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
#include <vector>
#include <SFML/Graphics.hpp>


////////////////////////////////////////////
/// \Brief input handling class
///
///////////////////////////////////////////
class InputMgr
{
public:


	/////////////////////////////////
	/// \brief default constructor
	///
	/////////////////////////////////
	InputMgr();

	/////////////////////////////////
	/// \brief default destructor
	///
	/////////////////////////////////
	~InputMgr();

	/////////////////////////////////
	/// \brief gets window and event references
	///
	///
	/// \param window	Reference to game window
	/// \param event	Reference to game event
	///
	/////////////////////////////////
	void Update(sf::Event& Event);

	/////////////////////////////////
	/// \brief returns true if key is pressed
	///
	/// /param key		int or sf::Keyboard key type
	///
	/////////////////////////////////
	bool KeyPressed(int key);

	/////////////////////////////////
	/// \brief returns true if some keys are pressed
	///
	/// \param keys		vector of int or vector of sf::Keyboard key types
	///
	/////////////////////////////////
	bool KeyPressed(std::vector<int>keys);

	/////////////////////////////////
	///	\brief returns true if key is released
	///
	/// \param key		int or sf::Keyboard key type
	///
	/////////////////////////////////
	bool KeyReleased(int key);

	/////////////////////////////////
	/// \brief returns true if some keys are released
	///
	/// \param keys		vector of int or vector of sf::Keyboard key types
	///
	/////////////////////////////////
	bool KeyReleased(std::vector<int>keys);

	/////////////////////////////////
	/// \brief returns true if key is pressing
	///
	/// \param key		int or sf::Keyboard key type
	///
	/////////////////////////////////
	bool KeyPressing(int key);

	/////////////////////////////////
	/// \brief returns true if some keys are pressing
	///
	/// \param keys		vector of int or vector of sf::Keyboard key types
	///
	/////////////////////////////////
	bool KeyPressing(std::vector<int>keys);

	/////////////////////////////////
	/// \brief returns true if left mouse button is pressed
	///
	///
	////////////////////////////////
	bool LMBPressed();

	/////////////////////////////////
	/// \brief returns true if right mouse button is pressed
	///
	///
	////////////////////////////////
	bool RMBPressed();

	/////////////////////////////////
	/// \brief returns true if left mouse button is released
	///
	///
	////////////////////////////////
	bool LMBReleased();

	/////////////////////////////////
	/// \brief returns true if right mouse button is released
	///
	///
	////////////////////////////////
	bool RMBReleased();

	////////////////////////////////
	/// \brief returns bool CanClick value
	///
	/// When is true player can click button
	/// or when is false player can't click button
	///
	///////////////////////////////
	bool GetCanClick();

	///////////////////////////////
	/// \brief get boolean value
	///
	/// \param value - if true then object can be clicked - if false can't.
	///
	////////////////////////////////
	void SetCanClick(bool canClick);


private:
	bool canClick_;
	sf::Event event_;

};
