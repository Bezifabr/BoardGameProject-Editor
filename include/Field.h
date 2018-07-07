/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Field.h
// Purpose: Contains Field class on which the characters move
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

class Field
{
public:
	Field();
	~Field();

	///////////////////////////
	/// 
	///
	///////////////////////////
	sf::Vector2f GetPosition();
	std::string GetType();
	std::string GetTextureID();
	sf::Sprite & GetSprite();

	void SetPosition(sf::Vector2f position);
	void SetType(std::string type);
	void SetTextureID(std::string textureID);

	uint8_t GetTrack();
	uint8_t GetSecondTrack();
	uint8_t GetFirstTrack();
	uint8_t GetNextTrack();
	uint8_t GetNextLocation();
	std::string GetLocationEntrance();
	void SetTrack(uint8_t track);
	void SetSecondTrack(uint8_t track);
	void SetFirstTrack(uint8_t track);
	void SetNextTrack(uint8_t track);
	void SetNextLocation(uint8_t location);
	void SetLocationEntrance(std::string id);

	std::string GetId();
	void SetId(std::string id);

	bool IsSelected();
	bool IsSelected(bool isSelected);
	bool IsClickable();
	bool IsClickable(bool clickable);
	bool IsPassingNextLocation();
	bool IsPassingNextLocation(bool isPassing);
	bool IsChangingTrack();
	bool IsChangingTrack(bool isChanging);
	bool IsEndingTrack();
	bool IsEndingTrack(bool isEnding);

	sf::Text& GetHeader();

	void PrepareToLoad();
private:
	sf::Vector2f position_;
	std::string type_;
	std::string textureID_;
	sf::Sprite sprite_;

	sf::Text header_;

	bool passNextLocation_ = false;
	bool changesTrack_ = false;
	bool endsTrack_ = false;

	bool isSelected_;
	bool isClickable_;

	std::string id_;

	uint8_t track_;
	uint8_t secondTrack_;
	uint8_t firstTrack_;
	uint8_t nextLocations_;
	uint8_t nextTrack_;
	std::string locationEntrance_;
};
