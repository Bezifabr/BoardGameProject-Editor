/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Player.h
// Purpose: Contains Player class derived from Character base class.
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
#include <memory>
#include "Character.h"

class Player : public Character
{
public:
	
	/*
	* virtual destructor
	*/
	virtual ~Player() {};

	/*
	* add exp to player
	* If player's exp is greater than required then LevelUp() method is called
	*
	* \param exp - Value of additional experience
	*/
	void AddExp(int exp);

	/*
	* removes player's exp
	* If it falls under 0 level then LevelDown() method is called
	*
	* \param exp - Value of decreased experience
	*/
	void DeleteExp(int exp);

	/*
	* increase player's level by 1
	* \param startingExp - Sets player's starting exp
	*/
	void LevelUp(int startingExp);

	/*
	* increase player's level by 1
	*/
	void LevelUp();

	/*
	* decrease player's level by 1
	* \param decresedExp - Amount of exp to delete from requiredExp (That will be player's exp)
	*/
	void LevelDown(int decreasedExp);

	/*
	* Sets level with default statistics
	* \param level - Sets player's level
	* \param startingExp - Sets player's starting exp
	*/
	void Level(int level, int startingExp);

	/*
	* Sets level with default statistics
	* \param level - Sets player's level
	*/
	void Level(int level);

	/*
	* Increase required experience value
	* It scale by multiplying 100 by the level of the player
	*/
	void IncreaseRequiredExp();

	/*
	* Increase required experience value
	* \param exp - Increasing value of experience
	*/
	void IncreaseRequiredExp(int exp);

	/*
	* Decrease required experience value
	* It scale by multiplying 100 by the level of the player
	*/
	void DecreaseRequiredExp();

	/*
	* Decrease required experience value
	* \param exp - The reduction value of experience
	*/
	void DecreaseRequiredExp(int exp);
	
protected:

	float levelCap_;   // Default 1.0f

	void SetRequiredExp(int exp);

	virtual void Default() {};
	virtual void Initiate() {};

private:
	int experience_;
	int requiredExp_;
};




class Oslas : public Player
{
public:
	Oslas() {};
	~Oslas() {};

	void Initiate();
private:
	void Default();
};


class Fahren : public Player
{
public:
	Fahren() {};
	~Fahren() {};

	void Initiate();
private:
	void Default();
};


class Mefisto : public Player
{
public:
	Mefisto() {};
	~Mefisto() {};

	void Initiate();
private:
	void Default();
};


class Seph : public Player
{
public:
	Seph() {};
	~Seph() {};

	void Initiate();
private:
	void Default();
};