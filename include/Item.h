/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Item.h
// Purpose: Contains the Item class derived from the Skill class.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

#include "Skill.h"

#pragma once

class Item : public Skill
{
public:
	Item();
	~Item();

	////////////////
	/// Returns item's shop price
	/// Price is how much item costs in shop
	///
	/// \return integer price_ variable
	///
	////////////////
	int GetPrice();

	////////////////
	/// Changes item's price
	/// Checks if new price is less or equal to MAX_ITEM_PRICE constant variable
	/// Price is how much item costs in shop
	///
	/// \param price - Integer type argument. New item's price.
	///
	////////////////
	void SetPrice(int price);

	////////////////
	/// Returns amount of charges of item
	/// 
	/// \return integer numberOfCharges_ variable
	///
	////////////////
	int GetAmounOfCharges();

	////////////////
	/// Changes amount of charges of item
	/// It's amount of possible uses of the item.
	/// Minimum amount of charges is 1 (if argument equals 0 value will be changed to 1)
	///
	/// \param amountOfChanges - Integer type argument. New amount of item's charges
	///
	////////////////
	void SetAmountOfCharges(int amountOfChanges);

	////////////////
	/// Returns true if item is permament
	///
	/// \return value of isPermament_ boolean variable
	///
	////////////////
	bool IsPermament();

	////////////////
	/// Set item usability (can be used or not)
	///
	/// \param isPermament_ - Boolean type argument. If true item can't be worn up, if false it do.
	///
	////////////////
	void IsPermament(bool isUsable);

private:

	bool isPermament_;
	int amountOfCharges_;

	int price_;


};
