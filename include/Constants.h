/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Constants.h
// Purpose: Contains game constants and strings of text.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////
#pragma once

#define TextLine const std::string
#define WND_SIZE sf::Vector2f(1028,720)


#define DEFAULT_LEVEL_CAP 1.0f
#define SCALE_OF_LEVELING 1
#define MAX_LEVEL 50
#define MAX_EXP 999999

#define MAX_AGILITY 200
#define MAX_STRENGTH 200
#define MAX_ENDURANCE 200
#define MAX_SPEED 50
#define MAX_INTELLIGENCE 200
#define MAX_WILLPOWER 200

#define MAX_DAMAGE 5000
#define MAX_SPELL_FUEL 5000
#define MAX_HEALTH 5000
#define MAX_ARMOR 5000

#define MAX_ITEM_PRICE 99999
#define MAX_ITEM_CHARGES 5

TextLine VERSION = "Game Editor 0.1.0 pre alpha in build";


TextLine DEFAULT_LOCATION_NAME = "Location name";
TextLine DEFAULT_LOCATION_NUMBER = "Location: 0";

TextLine MENU_NEW = "New map";
TextLine MENU_LOAD = "Load map";
TextLine MENU_QUIT = "Quit";
TextLine MENU_BACK = "Back";
TextLine EDITOR_SAVE = "Save map";


TextLine M_FILE = "File";
TextLine M_EDIT = "Edit";
TextLine M_TOOLS = "Tools";
TextLine M_HELP = "Help";

TextLine M_FILE_NEW = "New map";
TextLine M_FILE_OPEN = "Load";
TextLine M_FILE_SAVE = "Save";
TextLine M_FILE_SAVEAS = "Save as";
TextLine M_FILE_PREF = "Preferences";
TextLine M_FILE_QUIT = "Quit";

TextLine M_EDIT_UNDO = "Undo";
TextLine M_EDIT_REDO = "Redo";
TextLine M_EDIT_COPY = "Copy";
TextLine M_EDIT_PASTE = "Paste";
TextLine M_EDIT_SELECT= "Select";
TextLine M_EDIT_UNSELECT = "Unselect";
TextLine M_EDIT_RESET_CAM = "Reset camera position";
TextLine M_EDIT_FIND = "Find";
TextLine M_EDIT_FINDANDREPLACE = "Find and replace";

TextLine LOC_MOVE = "Move";
TextLine LOC_REPLACE = "Replace";
TextLine LOC_CLOSE = "Close";
TextLine LOC_MOVE_REPLACE = "Move/Replace";
TextLine LOC_APPLY = "Apply";

TextLine M_TOOLS_SETTINGS = "Settings";
TextLine M_TOOLS_DATA_MANAGER = "Import & Export";
TextLine M_TOOLS_LOCATIONS = "Locations";

TextLine FIELD_OK = "Ok";
TextLine FIELD_CANCEL = "Cancel";

TextLine M_HELP_HELP = "Help";
TextLine M_HELP_ABOUT = "About";

TextLine MAP_SETTINGS_DESC_BACKGROUND = "Map background path:";
TextLine MAP_SETTINGS_DESC_SETTINGS = "Map settings:";

TextLine OBJ_PROPERTIES_TITLE = "Properties";

TextLine LOAD_MAP_DESC = "What do you want do load?";
TextLine SAVE_MAP_DESC = "Type name of map file";

TextLine WND_SAVE = "Save";
TextLine WND_LOAD = "Load";
TextLine WND_CANCEL = "Cancel";
TextLine WND_OK = "Ok";

TextLine WND_LOADMAP_TITLE = "Type source of map file";
TextLine WND_SAVEMAP_TITLE = "Type source of map file";

TextLine WND_CURRENT_LOCATION = "Current ID";
TextLine WND_NEXT_LOCATION = "Next ID";

TextLine NPC_WINDOW_ID = "Id";
TextLine NPC_WINDOW_NAME = "Name";
TextLine NPC_WINDOW_CLASS = "Class";
TextLine NPC_WINDOW_LEVEL = "Level";
TextLine NPC_WINDOW_TEXTURE = "Texture";
TextLine NPC_WINDOW_ATTITUDE = "Attitude";
TextLine NPC_WINDOW_ROLE = "Role";
TextLine NPC_WINDOW_SET_STATS = "Set stats";
TextLine NPC_WINDOW_SET_SPELLS = "Set spells";
TextLine NPC_WINDOW_SET_ARMOR = "Set armor";
TextLine NPC_WINDOW_SET_INVENTORY = "Set inventory";
TextLine NPC_WINDOW_SET_POSITION = "Set position";

TextLine NPC_WINDOW_CREATE = "Create";
TextLine NPC_WINDOW_CANCEL = "Cancel";

TextLine WND_NPC_ARMOR_TITLE = "Armor";
TextLine WND_NPC_INV_TITLE = "Inventory";
TextLine WND_NPC_STATS_TITLE = "Statistics";
TextLine WND_NPC_POSITION_TITLE = "Position";
TextLine WND_NPC_SPELLS_TITLE = "Spells";
