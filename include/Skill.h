/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Skill.h
// Purpose: Contains the Skill class.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////


#include "Effect.h"
#include <SFML/Graphics.hpp>
#include <string>

#pragma once

class Skill
{
public:
	Skill();
	~Skill();

	void SetID(std::string id);

	const std::string& GetID();
	////////////////
	/// Loads texture to icon
	/// It has to be 64x64
	///
	/// \param textureOfIcon - New texture of icon
	///
	////////////////
	void LoadIcon(sf::Texture& textureOfIcon);

	////////////////
	/// Returns icon of object
	///
	/// \return sf::Sprite& icon_ variable
	///
	////////////////
	sf::Sprite& GetIcon();

	////////////////
	/// Changes object's name
	/// Checks if new name string is not empty
	///
	/// \param name - String type argument. New name.
	///
	////////////////
	void SetName(std::string name);

	////////////////
	/// Returns object's name
	///
	/// \return std::string& name_ variable
	///
	////////////////
	std::string& GetName();

	////////////////
	/// Changes object's description
	/// Checks if new description string is not empty
	///
	/// \param description - String type argument. New description.
	///
	////////////////
	void SetDescription(std::string description);

	////////////////
	/// Returns object's description
	///
	/// \return std::string& description_ variable
	///
	////////////////
	std::string& GetDescription();

	////////////////
	/// Returns time of object's cooldown
	/// 1 = one turn, 2 = two turns, etc...
	/// 0 = no cooldown
	///
	/// /return Integer type argument. New time of cooldown
	///
	////////////////
	int GetTimeOfCooldown();

	////////////////
	/// Changes time of cooldown
	/// 1 = one turn, 2 = two turns, etc...
	/// 0 = no cooldown
	///
	/// \param cooldown - Integer type variable. New cooldown time.
	///
	////////////////
	void SetTimeOfCooldown(int cooldown);

	////////////////
	/// Returns true if owner of object can target self with it
	///
	/// /return targetingSelf_ boolean variable value
	///
	////////////////
	bool IsTargetingSelf();
	
	////////////////
	/// Returns true if owner of object can target enemy with it
	///
	/// \return targetingEnemy_ boolean variable value
	///
	////////////////
	bool IsTargetingEnemy();

	////////////////
	/// Returns true if owner of object can target ally with it
	///
	/// \return targetingAlly_ boolean variable value
	///
	////////////////
	bool IsTargetingAlly();

	////////////////
	/// Changes boolean value of targeting self
	///
	/// \param isTargeting - Boolean type argument. Sets targeting self to true or false.
	///
	////////////////
	void IsTargetingSelf(bool isTargeting);

	////////////////
	/// Changes boolean value of targeting enemy
	///
	/// \param isTargeting - Boolean type argument. Sets targeting enemy to true or false.
	///
	////////////////
	void IsTargetingEnemy(bool isTargeting);

	////////////////
	/// Changes boolean value of targeting ally
	///
	/// \param isTargeting - Boolean type argument. Sets targeting ally to true or false.
	///
	////////////////
	void IsTargetingAlly(bool isTargeting);

	////////////////
	/// Returns true if it is used immediately
	///
	/// \return value of the useImmediately_ boolean variable
	///
	////////////////
	bool IsUsingImmediately();

	////////////////
	/// Returns true if it is used on target
	///
	/// \return value of the useOnTarget_ boolean variable
	///
	////////////////
	bool IsUsingOnTarget();

	////////////////
	/// Changes boolean value of immediately type of using 
	/// when set it to true useOnTarget_ variable will change to false
	/// Sets isUsable_ variable to true
	///
	/// \param useImmediately - Boolean type argument. Changes useImmediately_ variable's value
	/// 
	////////////////
	void IsUsingImmediately(bool useImmediately);

	////////////////
	/// Changes boolean value of on target type of using
	/// when set it to true useImmediately_ variable will change to false
	/// Sets isUsable_ variable to true 
	///
	/// \param useOnTarget - Boolean type argument. Changes useOnTarget_ variable's value
	///
	////////////////
	void IsUsingOnTarget(bool useOnTarget);

	////////////////
	/// Changes boolean value of is useable variable
	/// It checks if character can use this object
	///
	/// \param isUsable - Boolean type argument. Changes isUsable_ variable's value
	///
	////////////////
	void IsUsable(bool isUsable);

	////////////////
	/// Returns true is object is useable
	/// It checks if character can use this object
	///
	/// \return value of the isUsable_ boolean variable
	///
	////////////////
	bool IsUsable();

	void SetIconTextureID(std::string iconTextureID);

	std::string GetIconTextureID();

private:
	// Basic info
	std::string id_;
	std::string name_;
	std::string description_;
	sf::Sprite icon_;
	std::string iconTextureID_;
	int timeOfCooldown_;

	// Possible targets
	bool targetingSelf_;
	bool targetingEnemy_;
	bool targetingAlly_;

	// How skill is used
	bool useImmediately_;
	bool useOnTarget_;
	
	bool isUsable_;
};