/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// FieldMgr.h
// Purpose: Handles operations in the fields.
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
#include "MapLoader.h"
#include <iostream>

class FieldMgr
{
	typedef std::vector<Field> FieldContainer;
	typedef FieldContainer::iterator FIterator;

public:
	FieldMgr() {};
	~FieldMgr() {};

	///////////////////////
	/// Initilize Field Manager
	///
	/// \param data - Pointer to DataMgr object
	/// \param mapMgr - Pointer to MapMgr object
	/// \param input - Pointer to InputMgr object
	/// \param appWindow - Pointer to AppWindow object
	///
	///////////////////////
	void Init(DataMgr* data, MapMgr* mapMgr, InputMgr* input, AppWindow* appWindow);

	//////////////////////
	/// Changes template of field
	/// Checks if button from 1 to 9 has been pushed by player
	///
	//////////////////////
	void ChangeTool();

	//////////////////////
	/// Returns number of field templates
	///
	/// \return size of fieldBars vector
	///
	//////////////////////
	size_t GetFieldBarSize();

	//////////////////////
	/// Returns Field template
	///
	/// \param ID - number of field template in fieldBar vector
	/// \return field template from fieldBar vector
	///
	//////////////////////
	Field& GetFieldTemplate(int ID);

	//////////////////////
	/// Returns true if number of field's templates is zero
	///
	/// \return value returned from Empty() method used in fieldBar vector
	///
	//////////////////////
	bool IsFieldBarEmpty();

	/////////////////////
	/// Returns true is one of fields is selected
	///
	/// \return value of isFieldSelected boolean variable
	///
	/////////////////////
	bool IsFieldSelected();

	//////////////////////
	/// Draws tool or field selected by user
	///
	//////////////////////
	void DrawTool();

	/////////////////////
	/// The loop of fields manager.
	///
	/// \param isMenuOpened - If it's true player cannot place or move field
	///
	/////////////////////
	void Update(bool isMenuOpened);

	/////////////////////
	/// Loads template Fields
	/// They are used in Field placing tool
	///
	/// \param source - source of text file with Fields scripts
	///
	/////////////////////
	void LoadFieldsFromFile(const char* source);
private:

	enum EditorModes { EditMode, ShowTracks, ShowOrder, ShowID };
	EditorModes editorModes_;

	FieldContainer fieldsBar_;
	Field currentField_;
	DataMgr* data_;
	MapMgr* mapMgr_;
	InputMgr* input_;
	AppWindow* appWindow_;


	int selectedField_;
	int selectedTool_;
	bool isFieldGrabbed_ = false;
	bool isFieldToolSelected_ = false;
	bool isFieldSelected_ = false;
	sf::Vector2f mouse_prev_location_;
	sf::Vector2i field_prev_location_;

	bool canClick_;

	sf::Clock clickTimer_;

	bool engineSet_;

	void AddFieldType(std::string type);

	void DeleteField();
	void PlaceField();
	void MoveField();
	void SelectField();
	void UnselectField();
	void GUIUpdate();
};
