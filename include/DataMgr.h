/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// DataMgr.h
// Purpose: Contains data manager that handles operations on resource files.
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
#include <map>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

////////////////////////////////
/// \brief class that loads game data
///
////////////////////////////////
	class DataMgr
	{
	public:
		DataMgr();
		~DataMgr();

		//////////////////////////////////
		/// \brief Loads texture and adds to the std::map
		///
		/// This method first loads texture from source
		/// then adds it to std::map and makes ID as key
		///
		/// \param ID			Key to texture in std::map
		/// \param source		Source to load texture
		///
		//////////////////////////////////
		bool LoadTexture(const string& ID, const string& source);

		//////////////////////////////////
		/// \brief Loads sound and adds to the std::map
		///
		/// This method first loads sound from source
		/// then adds it to std::map and makes ID as key
		///
		/// \param ID			Key to sound in std::map
		/// \param source		Source to load sound
		///
		//////////////////////////////////
		bool LoadSound(const string& ID, const string& source);

		//////////////////////////////////
		/// \brief Loads font and adds to the std::map
		///
		/// This method first loads font from source
		/// then adds it to std::map and makes ID as key
		///
		/// \param ID			Key to font in std::map
		/// \param source		Source to load font
		///
		//////////////////////////////////
		bool LoadFont(const string& ID, const string& source);

		//////////////////////////////////
		/// \brief returns reference to sf::Texture class object
		///
		/// \param ID	Key to texture from std::map	
		///
		//////////////////////////////////
		sf::Texture& GetTexture(const string& ID);

		//////////////////////////////////
		/// \brief returns reference to sf::Sound class object
		///
		/// \param ID	Key to sound from std::map	
		///
		//////////////////////////////////
		sf::Sound& GetSound(const string& ID);

		//////////////////////////////////
		/// \brief returns reference to sf::Font class object
		///
		/// \param ID	Key to font from std::map	
		///
		//////////////////////////////////
		sf::Font& GetFont(const string& ID);

		//////////////////////////////////
		/// \brief removes sf::Texture class object from std::map container
		///
		/// \param ID	Key to texture from std::map
		///
		//////////////////////////////////
		bool RemoveTexture(const string& ID);

		//////////////////////////////////
		/// \brief removes sf::Sound class object from std::map container
		///
		/// \param ID	Key to sound from std::map
		///
		//////////////////////////////////
		bool RemoveSound(const string& ID);

		void LoadDataFromFile(const char* source);

		// Use this after initial file exist tests
		void SaveDataToFile(const char* source);

		//////////////////////////////////
		/// Returns source of resource
		///
		/// \param key	std::string type key to std::map of sources
		/// \return		std::string reference to source of texture
		///
		//////////////////////////////////
		std::string& GetTextureSource(string key);

		//////////////////////////////////
		/// Returns source of resource
		///
		/// \param key	std::string type key to std::map of sources
		/// \return		std::string reference to source of sound
		///
		//////////////////////////////////
		std::string& GetSoundSource(string key);

		//////////////////////////////////
		/// Returns source of resource
		///
		/// \param key	std::string type key to std::map of sources
		/// \return		std::string reference to source of font
		///
		//////////////////////////////////
		std::string& GetFontSource(string key);
	private:

		sf::SoundBuffer tempSoundBuffer_;		///< Temporary sound buffer variable for sound loading

		std::map<string, sf::Texture> textures_;		///< std::map of textures
		std::map<string, sf::Sound>	 sounds_;			///< std::map of sounds
		std::map<string, sf::Font>	 fonts_;			///< std::map of fonts

		std::map<string, string> textureSources_;
		std::map<string, string> soundSources_;
		std::map<string, string> fontSources_;

		void Clear();
	};

//////////////////////////////////////////////////
/// \class Data
/// \ingroup data handler
/// 
/// This is data handler class - loads and handles data
/// It's used in LoadData() method from state namespace classes
///
/// //Data loading
/// Data files are saved in std::map within access key
/// Source of resource is saved in std::map container of sources
/// All loading methods has Load prefix and data type suffix
/// For example LoadTexture() loads sf::Texture type file.
///
/// //Get reference to data
/// To get data from a std::map, you must know the key
/// All accessor methods has Get prefix and data type suffix
/// Used data is reference not copy so it can reduce memory consumption
/// 
/// //Release loaded data
/// To remove data from a std::map, you must know the key
/// All removing methods has Remove prefix and data type suffix
/// Don't use ID of this object while location in std::map is empty
///
/// //Get source of data
/// To get data source from a std::map, you must know the key
/// All accessor methods has Get prefix and data type + "source" suffix
/// Returned sources are references so it can reduce memory consumption
///
///////////////////////////////////////////////////