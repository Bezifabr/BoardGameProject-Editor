/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// StateMgr.h
// Purpose: It supports all operations in the main loop
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
#include <sstream>

#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Desktop.hpp>

#include "Camera.h"
#include "EditorMgr.h"


class StateMgr
{
public:
	StateMgr();
	~StateMgr();

	void Draw();
	void Update(sf::Event event);
	void HandleEvents(sf::Event& event);

	void Init(AppWindow* window) 
	{ 
		appWindow_ = window; 
		Initialize(); 
	}

private:

	void Initialize();
	void StartingSettings();
	void ClearMap();

	DataMgr data_;
	Camera camera_;
	InputMgr input_;
	AppWindow* appWindow_;
	GUIMgr guiMgr_;
	MapMgr mapMgr_;
	FieldMgr fieldMgr_;
	NPCMgr npcMgr_;
	EditorMgr editorMgr_;
	Console console_;


	bool isDataLoaded_ = false;
	
	enum ToolSelected { Field, NPC };
	ToolSelected selectedTool_;

	bool canClick_;
	bool canPressKey_;


	sf::Clock cameraMovementTimer_;
	sf::Clock elapsed_;
	sf::Clock autoSaveTime_;

	sfg::Desktop desktop_;

	void CameraMoving();
	void ChangeTool();
	void Autosave();
	
	void OpenNPCProperties();
	void OpenFieldProperties();


	void CameraMouseMoving();
	void CameraArrowsMoving();

	void ChangeToolByKey(sf::Keyboard::Key key, ToolSelected tool);

	void FieldEvents();
	void NPCEvents();
};
