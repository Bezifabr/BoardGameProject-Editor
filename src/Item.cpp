/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Skill.cpp
// Purpose: Contains Skill class methods definitions.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

#include "Item.h"
#include <iostream>
#include "Constants.h"

int Item::GetPrice()
{
	return price_;
}

void Item::SetPrice(int price)
{
	if (price < MAX_ITEM_PRICE && price >= 1)
		price_ = price;
	else
		std::cout << "Item::SetPrice(): Argument reached max price value" << std::endl;
}

int Item::GetAmounOfCharges()
{
	return amountOfCharges_;
}

void Item::SetAmountOfCharges(int amountOfCharges)
{
	if (amountOfCharges >= 1 && amountOfCharges < MAX_ITEM_CHARGES)
		amountOfCharges_ = amountOfCharges;
	else if (amountOfCharges == 0)
		amountOfCharges_ = 1;
	else
		std::cout << "Item::SetAmountOfCharges(): invalid argument" << std::endl;
}

bool Item::IsPermament()
{
	return isPermament_;
}

void Item::IsPermament(bool isPermament)
{
	isPermament_ = isPermament;
}



Item::Item()
{
}

Item::~Item()
{
}

