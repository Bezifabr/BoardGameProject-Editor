/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// DataMgr.cpp
// Purpose: Contains operations on resource files.
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
#include "DataMgr.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

DataMgr::~DataMgr()
{
	Clear();
}
void DataMgr::Clear()
{
	fonts_.clear();
	textures_.clear();
	sounds_.clear();
}
DataMgr::DataMgr() 
{
}


bool DataMgr::LoadTexture(const string& ID, const string& source)
{
	if (!textures_[ID].loadFromFile(source))
	{
		cout << "Can't load " << ID << " texture from " << source << endl;
		MessageBox(NULL, "Error occured when tried to load file",
			"Critical error", MB_OK | MB_ICONERROR);
		return false;
	}
	std::cout << "Texture " + ID + " loaded." << std::endl;
	textureSources_[ID] = source;
	return true;
}

bool DataMgr::LoadSound(const string& ID, const string& source)
{
	if (!tempSoundBuffer_.loadFromFile(source))
	{
		cout << "Can't load " << ID << " sound from " << source << endl;
		MessageBox(NULL, "Error occured when tried to load file",
			"Critical error", MB_OK | MB_ICONERROR);
		return false;
	}
	sounds_[ID].setBuffer(tempSoundBuffer_);
	std::cout << "Sound " + ID + " loaded." << std::endl;
	soundSources_[ID] = source;
	return true;
}

bool DataMgr::LoadFont(const string& ID, const string& source)
{
	if (!fonts_[ID].loadFromFile(source))
	{
		cout << "Can't load " << ID << " font from " << source << endl;
		MessageBox(NULL, "Error occured when tried to load file",
			"Critical error", MB_OK | MB_ICONERROR);
		return false;
	}
	fonts_[ID].loadFromFile(source);
	std::cout << "Font " + ID + " loaded." << std::endl;
	fontSources_[ID] = source;
	return true;
}

sf::Texture & DataMgr::GetTexture(const string& ID){return this->textures_[ID];}
sf::Sound & DataMgr::GetSound(const string& ID) { return this->sounds_[ID]; }
sf::Font & DataMgr::GetFont(const string& ID) { return this->fonts_[ID]; }

bool DataMgr::RemoveTexture(const string & ID)
{
	if (textures_.find(ID) == textures_.end()) 
	{
		cout << ID << " not exists" << endl;
		MessageBox(NULL, "Error occured when tried to unload file",
			"Critical error", MB_OK | MB_ICONERROR);
		return false;
	}
	else {
		textures_.erase(ID);
		std::cout << "Texture " + ID + " removed." << std::endl;
		return true;
	}
}

bool DataMgr::RemoveSound(const string & ID)
{
	if (sounds_.find(ID) == sounds_.end())
	{
		cout << ID << " not exists" << endl;
		MessageBox(NULL, "Error occured when tried to unload file",
			"Critical error", MB_OK | MB_ICONERROR);
		return false;
	}
	else {
		sounds_.erase(ID);
		std::cout << "Sound " + ID + " removed." << std::endl;
		return true;
	}
}

void DataMgr::LoadDataFromFile(const char* source)
{
	std::ifstream openfile(source);
	if (openfile.is_open())
	{
		std::string tempType;
		std::string tempName;
		std::string tempSource;
		while (!openfile.eof())
		{

			std::string line;

			std::getline(openfile, line); //< Load line

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("Texture{") != std::string::npos)
				tempType = "Texture";
			else if (line.find("Sound{") != std::string::npos)
				tempType = "Sound";
			else if (line.find("Font{") != std::string::npos)
				tempType = "Font";


			if (tempType == "Texture" || tempType == "Sound" || tempType == "Font")
				if (line.find("Name=") != std::string::npos || line.find("name=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempName = line;
					std::cout << "Name(" << line << ")" << std::endl;
				}
				else if (line.find("Source=") != std::string::npos || line.find("source=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempSource = line;
					std::cout << "Source(" << line << ")" << std::endl;
				}

		
			if (line.find('}') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
				std::cout << " Type(" << tempType << ")" << std::endl;

				if (tempType == "Texture")
					LoadTexture(tempName, tempSource);
				else if (tempType == "Sound")
					LoadSound(tempName, tempSource);
				else if (tempType == "Font")
					LoadFont(tempName, tempSource);


				tempName = "";
				tempSource = "";
				tempType = "";
			}

		}
	}
}

void DataMgr::SaveDataToFile(const char * source)
{
	ofstream Outfile;
	Outfile.open(source, std::ofstream::out | std::ofstream::app);

	for (auto itr = textures_.begin(), end = textures_.end(); itr != end; ++itr)
	{
		Outfile << "Texture{" << std::endl;
		cout << "Texture{" << endl;
		Outfile << "Name= " << itr->first << std::endl;
		cout << "Name = " << itr->first <<endl;
		Outfile << "Source= " <<  GetTextureSource(itr->first) << std::endl;
		cout << "Source = " <<  GetTextureSource(itr->first) << endl;
		Outfile << "}" << std::endl;
		cout << "}" << endl;
	}
	for (auto itr = sounds_.begin(), end = sounds_.end(); itr != end; ++itr)
	{
		Outfile << "Sound{" << std::endl;
		cout << "Sound{" << endl;
		Outfile << "Name= " << itr->first << std::endl;
		cout << "Name = " << itr->first << endl;
		Outfile << "Source= " << GetSoundSource(itr->first) << std::endl;
		cout << "Source = " << GetSoundSource(itr->first) << endl;
		Outfile << "}" << std::endl;
		cout << "}" << endl;
	}
	for (auto itr = fonts_.begin(), end = fonts_.end(); itr != end; ++itr)
	{
		Outfile << "Font{" << std::endl;
		cout << "Font{" << endl;
		Outfile << "Name= " << itr->first << std::endl;
		cout << "Name = " << itr->first << endl;
		Outfile << "Source= " << GetFontSource(itr->first) << std::endl;
		cout << "Source = " << GetFontSource(itr->first) << endl;
		Outfile << "}" << std::endl;
		cout << "}" << endl;
	}
	Outfile.close();
}

std::string & DataMgr::GetTextureSource(string key)
{
	return textureSources_[key];
}

std::string & DataMgr::GetSoundSource(string key)
{
	return soundSources_[key];
}

std::string & DataMgr::GetFontSource(string key)
{
	return fontSources_[key];
}
