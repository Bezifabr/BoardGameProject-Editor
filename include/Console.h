#pragma once
#include "Commands.h"

class Console
{
public:
	Console() {};
	~Console() {};

	/////////////////
	/// Process all console commands.
	/// Need to be turned on by TurnOn() method.
	///
	/////////////////
	bool Running();
	
	/////////////////
	/// Runs console.
	/// Changes isRunning_ variable's value to true.
	///
	/////////////////
	void TurnOn();

	void LoadRenderWindow(sf::RenderWindow* renderWindow);
	void LoadGameObjects(GameObjects* gameObjects);
private:
	bool isRunning_;

	void TurnOff();
	void CloseEditor();
	void Help();

	std::string lastCommand_;

	sf::RenderWindow* renderWindow_;
	GameObjects* gameObjects_;
	
	Commands commands_;

};
