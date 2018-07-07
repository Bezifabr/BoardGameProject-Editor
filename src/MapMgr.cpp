/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// MapMgr.cpp
// Purpose: Containes loaded map data. Handles operations on locations.
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
#include "MapMgr.h"


bool MapMgr::IsStringAvailable(std::vector<std::string> stringVector, std::string stringValue)
{
	if (!stringVector.empty())
		for (size_t i = 0; i != stringVector.size(); i++)
			if (stringValue == stringVector[i])
				return false;
	return true;
}


void MapMgr::MoveLocationTo(int current, int next)
{


	locationsKeysIT_ = locationsKeys_.begin();
	int j =0;
	for (size_t i = 0; i < current; i++)
	{
		j++;
		locationsKeysIT_++;
	}
	std::string tempLoc = locationsKeys_[j];
	locationsKeys_.erase(locationsKeysIT_);
	


	locationsKeysIT_ = locationsKeys_.begin();
	int tempMapKey = 0;
	for (size_t i = 0; i < next; i++)
	{
		locationsKeysIT_++;
		tempMapKey++;
	}
	locationsKeys_.insert(locationsKeysIT_, tempLoc);
	currentLocationKeyNumber_ = tempMapKey;

	
	
		/////////////////////////
		/// How it works (for example.):
		// Iterator - 0 (begin) Current - 1 Next - 3

		// 1. for loop /Next/ times; increment iterator
		// 2. insert current location into iterator place
		// 3. for loop /Current/ times; increment iterator
		// 4. erase current location from vector
}

void MapMgr::DrawCurrentLocation(AppWindow * appWindow)
{
	GetCurrentLocation()->DrawBackground(appWindow->Get());

	for (GetCurrentLocation()->GetFieldsIT() = GetCurrentLocation()->GetFields().begin();
		GetCurrentLocation()->GetFieldsIT() != GetCurrentLocation()->GetFields().end();
		GetCurrentLocation()->GetFieldsIT()++)
		appWindow->Get().draw(GetCurrentLocation()->GetFieldsIT()->GetSprite());

	for (GetNPCsIT() = GetNPCs().begin(); GetNPCsIT() != GetNPCs().end(); GetNPCsIT()++)
		if (GetNPCsIT()->GetLocation() == currentLocationKeyNumber_)
			appWindow->Get().draw(GetNPCsIT()->GetSprite());
}

std::vector<NPC>& MapMgr::GetNPCs()
{
	return npcs_;
}

std::vector<NPC>::iterator & MapMgr::GetNPCsIT()
{
	return npcIT_;
}

void MapMgr::SetNPCs(std::vector<NPC>& npcs)
{
	npcs_.clear();
	for (size_t i = 0; i < npcs.size(); i++)
		npcs_.push_back(npcs[i]);
}

void MapMgr::ChangeCurrentName(std::string name)
{
	if (locationsKeys_[currentLocationKeyNumber_] != name)
	{
		locations_[name] = locations_[locationsKeys_[currentLocationKeyNumber_]];
		locations_.erase(locationsKeys_[currentLocationKeyNumber_]);
		locationsKeys_[currentLocationKeyNumber_] = name;
	}
}

void MapMgr::ReplaceNPCs(size_t currentLoc, size_t nextLoc)
{
	std::vector<size_t> npcsBufor;
	for (size_t i = 0; i != npcs_.size(); i++)
	{
		if (npcs_[i].GetLocation() == currentLoc)
			npcsBufor.push_back(i);
		if (npcs_[i].GetLocation() == nextLoc)
			npcs_[i].SetLocation(currentLoc);
		for (size_t j = 0; j != npcsBufor.size(); j++)
			npcs_[npcsBufor[j]].SetLocation(nextLoc);
	}
}

void MapMgr::NewLocation(std::string key)
{
	if (IsStringAvailable(locationsKeys_, key))
	{
		Location tempMap;
		locations_[key] = tempMap;
		locationsKeys_.push_back(key);
	}
	else
		std::cout << "LocationMgr::NewLocation(): key is unavaiable" << std::endl;
}

void MapMgr::AddLocation(std::string key, Location & location)
{
	if (IsStringAvailable(locationsKeys_, key))
	{
		locations_[key] = location;
		locationsKeys_.push_back(key);
	}
	else
		std::cout << "LocationMgr::AddLocation(): key is unavaiable" << std::endl;
}

void MapMgr::RemoveLocation()
{

	if (locationsKeys_.size() > 1 && currentLocationKeyNumber_ != 0)
	{
		size_t tempMapKeyNumber_ = currentLocationKeyNumber_;
		locations_.erase(locationsKeys_[currentLocationKeyNumber_]);
		locationsKeys_.erase(GetIteratorToCurrentKey());

		if (!npcs_.empty())
			for (std::vector<NPC>::iterator it = npcs_.begin(); it != npcs_.end();)
			{
				if (it->GetLocation() == tempMapKeyNumber_)
					it = npcs_.erase(it);
				else
					++it;
			}
	}
}

void MapMgr::Next()
{
	if (currentLocationKeyNumber_ < locationsKeys_.size() - 1)
	{
		currentLocationKeyNumber_++;
		SetCurrentLocation(locationsKeys_[currentLocationKeyNumber_]);
	}
}
void MapMgr::Previous()
{
	if (currentLocationKeyNumber_ > 0)
	{
		currentLocationKeyNumber_--;
		SetCurrentLocation(locationsKeys_[currentLocationKeyNumber_]);
	}
}

void MapMgr::ResetCurrentKey()
{
	currentLocationKeyNumber_ = 0;
	SetCurrentLocation(locationsKeys_[currentLocationKeyNumber_]);
}

std::vector<std::string> MapMgr::GetLocationsKeys() 
{ 
	return locationsKeys_; 
}

void MapMgr::SetCurrentLocation(std::string key)
{
	if (!IsStringAvailable(locationsKeys_, key))
		currentLocationKey_ = key;
	else
		std::cout << "LocationMgr::SetCurrentLocation(): There is no location with that key" << std::endl;
}

Location * MapMgr::GetCurrentLocation()
{
	return &locations_[currentLocationKey_];
}

std::map<std::string, Location>& MapMgr::GetLocations()
{
	return locations_;
}

void MapMgr::Clear()
{
	npcs_.clear(); 
	locations_.clear(); 
	locationsKeys_.clear(); 
	currentLocationKeyNumber_ = 0; 
	currentLocationKey_.clear();
}

size_t MapMgr::GetCurrentLocationKey()
{
	return currentLocationKeyNumber_;
}

void MapMgr::SetSource(const char * source)
{
	source_ = source;
}

std::string MapMgr::GetSource()
{
	if (!source_.empty())
		return source_;
	else
		std::cout << "LocationMgr::GetSource(): Source is empty" << std::endl;
}

void MapMgr::SetData(DataMgr * data)
{
	if (data)
	{
		data_ = data;
	}
	else
		std::cout << "LocationMgr::SetData(): data is nullptr" << std::endl;
}

void MapMgr::SetInput(InputMgr * input)
{
	if(input)
	{
		input_ = input;
	}
	else
		std::cout << "LocationMgr::SetInput(): input is nullptr" << std::endl;
}


void MapMgr::ReplaceLocationWith(int current, int next)
{
		std::string replaceBufor = locationsKeys_[current];
		locationsKeys_[current] = locationsKeys_[next];
		locationsKeys_[next] = replaceBufor;
		currentLocationKeyNumber_ = next;
	
		///////////////////////
		/// How it works (for example.):
		// Current - 1 Next - 3
	
		// 1. Make bufor of current location
		// 2. Change value of current location to the next one
		// 3. Change value of next location to the bufor value
}

void MapMgr::IsWaitingForFieldSelection(bool isWaiting)
{
	if(waitingForFieldSelect_ != isWaiting)
	waitingForFieldSelect_ = isWaiting;
}

bool MapMgr::IsWaitingForFieldSelection()
{
	return waitingForFieldSelect_;
}

void MapMgr::IsWaitingForNPCSelection(bool isWaiting)
{
	waitingForNPCSelect_ = isWaiting;
}

bool MapMgr::IsWaitingForNPCSelection()
{
	return waitingForNPCSelect_;
}


GameObjects & MapMgr::GetGameObjects()
{
	return gameObjects_;
}

std::vector<std::string>::iterator & MapMgr::GetIteratorToCurrentKey()
{
	if (locationsKeys_.size() > 1 && currentLocationKeyNumber_ != 0)
		for (locationsKeysIT_ = locationsKeys_.begin(); locationsKeysIT_ != locationsKeys_.end(); locationsKeysIT_++)
			if (std::distance(locationsKeys_.begin(), locationsKeysIT_) == currentLocationKeyNumber_)
				if (std::distance(locationsKeys_.begin(), locationsKeysIT_) >= locationsKeys_.size() - 1)
				{
					Previous();
					return locationsKeysIT_;
				}
				else return locationsKeysIT_;
}

