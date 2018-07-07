#include "Console.h"
#include <iostream>

using namespace std;

bool Console::Running()
{
	if (isRunning_ == true)
	{
		lastCommand_ = commands_.RunGameObjects();
		
		TurnOff();
		CloseEditor();
		Help();

		return true;
	}
	return false;
}

void Console::TurnOn()
{
	cout << "//////////////////////////" << endl;
	cout << "    CONSOLE TURNED ON     " << endl;
	cout << "//////////////////////////" << endl;

	commands_.SetCommands();
	isRunning_ = true;
}

void Console::LoadRenderWindow(sf::RenderWindow * renderWindow)
{
	renderWindow_ = renderWindow;
}

void Console::LoadGameObjects(GameObjects * gameObjects)
{
	gameObjects_ = gameObjects;
	commands_.LoadGameObjects(gameObjects);
}

void Console::TurnOff()
{
	if (lastCommand_ == "Exit" || lastCommand_ == "EXIT" || lastCommand_ == "exit")
	{
		cout << "//////////////////////////" << endl;
		cout << "    CONSOLE TURNED OFF    " << endl;
		cout << "//////////////////////////" << endl;
		isRunning_ = false;
	}
}

void Console::CloseEditor()
{
	if (lastCommand_ == "Close" || lastCommand_ == "CLOSE" || lastCommand_ == "close")
		renderWindow_->close();
}

void Console::Help()
{
	if (lastCommand_ == "Help" || lastCommand_ == "help" || lastCommand_ == "HELP")
	{
		std::cout << "Commands: " << std::endl;
		cout << "Help - Shows list of commands." << endl
			<< "Exit - Closes console window." << endl
			<< "Close - Closes editor window." << endl;
		commands_.ShowCommands();
	}
}