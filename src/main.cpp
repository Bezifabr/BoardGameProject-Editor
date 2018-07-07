/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// main.cpp
// Purpose: Main loop with StateMgr class methods.
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
#include <SFML/Graphics.hpp>
#include <cmath>
#include "StateMgr.h"



int main()
{	
	AppWindow appWindow;
	appWindow.Get().resetGLStates();
	sfg::SFGUI sfgui;
	StateMgr statemgr;
	statemgr.Init(&appWindow);


	sf::Clock stoper;
	appWindow.Get().create(sf::VideoMode(WND_SIZE.x, WND_SIZE.y), VERSION);
	appWindow.Get().setFramerateLimit(60);


	while (appWindow.Get().isOpen())
	{
		sf::Event event;
		while (appWindow.Get().pollEvent(event))
			statemgr.HandleEvents(event);

		statemgr.Update(event);
		appWindow.Get().clear();
		statemgr.Draw();
		sfgui.Display(appWindow.Get());
		appWindow.Get().display();
	}
	return EXIT_SUCCESS;
}

