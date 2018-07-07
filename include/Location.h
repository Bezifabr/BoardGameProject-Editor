/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Location.h
// Purpose: Contains fields, background and other settings in Location class.
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
#include <string>
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "NPC.h"
#include "AppWindow.h"
#include "DataMgr.h"
#include "InputMgr.h"
#include "CharactersMgr.h"


class Location
{

public:
	Location();
	~Location();

	bool IsBackgroundLoaded();

	void SetBackgroundTexture(std::string source);
	void SetBackgroundTexture(sf::Texture& backgroundTexture);

	void DrawBackground(sf::RenderWindow& window);

	std::vector<Field>& GetFields();
	std::vector<Field>::iterator& GetFieldsIT();
	std::vector<Field>::iterator& GetSecondFieldsIT();
	void SetFields(std::vector<Field>& fields);

	void SetCameraPosition(sf::Vector2f position) { cameraPosition_ = position; }
	void SetCameraPosition(float x, float y) { cameraPosition_.x = x; cameraPosition_.y = y; }
	sf::Vector2f GetCameraPosition() { return cameraPosition_; }
	void CameraMove(sf::Vector2f moving) { cameraPosition_.x += moving.x; cameraPosition_.y += moving.y; }
	void CameraMove(float x, float y) { cameraPosition_.x += x; cameraPosition_.y += y; }

	void Clear() { fields_.clear(); }

	const std::string& GetBackgroundTextureSource() { return backgroundSource_; }
	
	enum class Settings : char
	{
		Standard = 0,
		User = 1,
		Custom = 2
	};

	void SetSettings(Settings settings) { mapSettings_ = settings; }
private:
	std::string backgroundSource_;
	sf::Sprite backgroundSprite_;
	sf::Texture backgroundTexture_;
	bool isBackgroundLoaded_;

	Settings mapSettings_;
	
	typedef std::vector<Field> FieldContainer;
	typedef FieldContainer::iterator FIterator;
	FieldContainer fields_;
	FIterator fieldIT_;
	FIterator secondFieldIT_;

	sf::Vector2f cameraPosition_;

};

