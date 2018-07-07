/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// GraphicObj.h
// Purpose: Contains Graphic class inherited by Animated class
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
#include <SFML/Graphics.hpp>
#include <iostream>

class Graphic
{
public:
	////////////////
	/// returns sprite of graphic object
	///
	////////////////
	sf::Sprite& GetSprite() { return sprite_; }

	////////////////
	/// Returns location of graphic object
	///
	////////////////
	int GetLocation() { return intLocation_; }

	////////////////
	/// Returns string location name variable
	///
	////////////////
	const std::string& GetStringLocation() { return stringLocation_; }

	////////////////
	/// Sets location id
	///
	////////////////
	void SetLocation(int location) { intLocation_ = location; }

	////////////////
	/// Sets location name
	///
	////////////////
	void SetLocation(std::string location) { stringLocation_ = location; }

	////////////////
	/// Returns graphic object's id
	///
	////////////////
	const std::string& GetID() { return id_; }

	////////////////
	/// Sets id of graphics object
	///
	////////////////
	void SetID(const std::string & id)
	{
		if (!id.empty())
		{
			id_ = id;
		}
		else std::cout << "Graphic::SetID(): argument is invalid" << std::endl;
	}

	////////////////
	/// Gets id of object's texture
	///
	////////////////
	std::string& GetTextureID()
	{
		return textureID_;
	}

	////////////////
	/// Sets id of objects texture
	///
	/// \param id	key of texture in std::map
	///
	////////////////
	void SetTextureID(const std::string& id)
	{
		textureID_ = id;
	}
private:

	std::string id_;
	sf::Sprite sprite_;
	std::string textureID_;
	int intLocation_;
	std::string stringLocation_;

};