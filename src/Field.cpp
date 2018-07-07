/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Field.h
// Purpose: Contains Field class methods accesssing private variables
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
#include "Field.h"

Field::Field()
{
}

Field::~Field()
{
}

sf::Vector2f Field::GetPosition()
{
	return position_;
}

std::string Field::GetType()
{
	return type_;
}

std::string Field::GetTextureID()
{
	return textureID_;
}

sf::Sprite & Field::GetSprite()
{
	return sprite_;
}

void Field::SetPosition(sf::Vector2f value)
{
	position_ = value;
}

void Field::SetType(std::string value)
{
	type_ = value;
}

void Field::SetTextureID(std::string value)
{
	textureID_ = value;
}

uint8_t Field::GetTrack()
{
	return track_;
}

uint8_t Field::GetSecondTrack()
{
	return secondTrack_;
}

uint8_t Field::GetFirstTrack()
{
	return firstTrack_;
}

uint8_t Field::GetNextTrack()
{
	return nextTrack_;
}

uint8_t Field::GetNextLocation()
{
	return nextLocations_;
}

std::string Field::GetLocationEntrance()
{
	return locationEntrance_;
}

void Field::SetTrack(uint8_t value)
{
	track_ = value;
}

void Field::SetSecondTrack(uint8_t value)
{
	secondTrack_ = value;
}

void Field::SetFirstTrack(uint8_t value)
{
	firstTrack_ = value;
}

void Field::SetNextTrack(uint8_t track)
{
	nextTrack_ = track;
}

void Field::SetNextLocation(uint8_t location)
{
	nextLocations_ = location;
}

void Field::SetLocationEntrance(std::string id)
{
	locationEntrance_ = id;
}

std::string Field::GetId()
{
	return id_;
}

void Field::SetId(std::string id)
{
	id_ = id;
}

bool Field::IsSelected()
{
	return isSelected_;
}

bool Field::IsSelected(bool isSelected)
{
	bool bufor = isSelected_;
	isSelected_ = isSelected;
	return bufor;
}

bool Field::IsClickable()
{
	return isClickable_;
}

bool Field::IsClickable(bool clickable)
{
	bool bufor = isClickable_;
	isClickable_ = clickable;
	return bufor;
}

bool Field::IsPassingNextLocation()
{
	return passNextLocation_;
}

bool Field::IsPassingNextLocation(bool isPassing)
{
	if (isPassing != passNextLocation_)
	{
		bool bufor = passNextLocation_;
		passNextLocation_ = isPassing;
		return bufor;
	}
}

bool Field::IsChangingTrack()
{
	return changesTrack_;
}

bool Field::IsChangingTrack(bool isChanging)
{
	if (isChanging != changesTrack_)
	{
		bool bufor = changesTrack_;
		changesTrack_ = isChanging;
		return bufor;
	}
}

bool Field::IsEndingTrack()
{
	return endsTrack_;
}

bool Field::IsEndingTrack(bool isEnding)
{
	if (isEnding != endsTrack_)
	{
		bool bufor = endsTrack_;
		endsTrack_ = isEnding;
		return bufor;
	}
}

sf::Text & Field::GetHeader()
{
	return header_;
}

void Field::PrepareToLoad()
{
	IsPassingNextLocation(false);
	IsChangingTrack(false);
	IsEndingTrack(false);

	SetTrack(0);
	SetFirstTrack(GetTrack());
	SetSecondTrack(GetTrack());
	SetNextLocation(0);
	SetNextTrack(0);
	SetLocationEntrance("");
}
