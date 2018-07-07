/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Player.cpp
// Purpose: Contains definitions of methods from Player class derived from Character base class.
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
#include "Player.h"
#include <iostream>
#include "Constants.h"



void Player::AddExp(int exp)
{
	if (exp > 0 && exp < MAX_EXP)
		experience_ += exp;
	else
		std::cout << "Player::AddExp(): Argument is invalid" << std::endl;

	if (experience_ > requiredExp_)
	{
		int startingExp = experience_ - requiredExp_;
		LevelUp(startingExp);
	}
}

void Player::DeleteExp(int exp)
{
	if (exp > 0 && exp < MAX_EXP)
		experience_ -= exp;
	else
		std::cout << "Player::DeleteExp(): Argument is invalid" << std::endl;

	if (experience_ < 0)
	{
		int decreasedExp = -experience_;
		LevelDown(decreasedExp);
	}
}



void Player::LevelUp(int startingExp)
{
	LevelUp();

	if (startingExp > 0 && startingExp < requiredExp_)
	{
		experience_ = startingExp;
	}
	else
		std::cout << "Player::LevelUp: Argument is invalid" << std::endl;
}

void Player::LevelUp()
{
	if (GetLevel() < MAX_LEVEL)
	{
		int level = GetLevel() + 1;
		SetLevel(level);
	}
	else
		std::cout << "Player::LevelUp(): Player reached max level" << std::endl;
	
	if (experience_ == requiredExp_)
		experience_ = 0;
	else if (experience_ > requiredExp_)
		experience_ = requiredExp_ - experience_;

	IncreaseRequiredExp();
}

void Player::LevelDown(int decreasedExp)
{
	if (GetLevel() > 0)
	{
		int level = GetLevel() - 1;
		SetLevel(level);
	}
	else
		std::cout << "Player::LevelDown(): level is too low" << std::endl;
}

void Player::Level(int level, int startingExp)
{
	if (level < MAX_LEVEL)
	{
		SetLevel(level);
		Default();
		if (startingExp < MAX_EXP)
			experience_ = startingExp;
		else
			std::cout << "Player::SetLevel(): Invalid startingExp argument" << std::endl;
	}
	else
		std::cout << "Player::SetLevel(): Invalid level argument" << std::endl;
}

void Player::Level(int level)
{
	if (GetLevel() < MAX_LEVEL)
	{
		SetLevel(level);
		Default();
		
		requiredExp_ = 0;

		for (int i = 1; i <= level; i++)
			requiredExp_ += SCALE_OF_LEVELING * 100 * i;
	}
	else
		std::cout << "Player::SetLevel(): Invalid level argument" << std::endl;
}

void Player::IncreaseRequiredExp()
{
	if (GetLevel() < MAX_LEVEL)
		requiredExp_ += SCALE_OF_LEVELING * 100 * GetLevel();
	else
		std::cout << "Player::IncreaseRequiredExp(): Player reached max level" << std::endl;
}

void Player::IncreaseRequiredExp(int exp)
{
	if (exp > 0 && exp < MAX_EXP)
	{
			requiredExp_ += exp;
	}
	else 
		std::cout << "Player::IncreaseRequiredExp(): Argument is invalid" << std::endl;
}

void Player::DecreaseRequiredExp()
{
	if (GetLevel() > 0)
		requiredExp_ -= SCALE_OF_LEVELING * 100 * GetLevel();
	else
		std::cout << "Player::DecreaseRequiredExp(): Player's level is to low" << std::endl;
}

void Player::DecreaseRequiredExp(int exp)
{
	if (exp > 0 && exp < MAX_EXP && exp < requiredExp_)
	{
		requiredExp_ -= exp;
	}
	else
		std::cout << "Player::DecreaseRequiredExp(): argument is invalid" << std::endl;
}

void Player::SetRequiredExp(int exp)
{
	if (exp > 0 && exp < MAX_EXP)
		requiredExp_ = exp;
	else
		std::cout << "Player::SetRequiredExp(): Argument is invalid" << std::endl;
}
