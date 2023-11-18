#pragma once

#include "includes.h"
#include "window.h"

class Game {
public:

	// Game() constructor
	Game() : window("Virtual-pet", sf::Vector2u(500,500))
	{
		
	}

	// Game destructor
	~Game()
	{

	}

	// HandleInput() function that handles all of the games inputs
	void HandleInput()
	{

	}

	// Update() function that updates the games objects
	void Update()
	{
		window.Update();
	}

	// Render() function that renders in all of the objects for the game
	void Render()
	{
		window.BeginDraw();
		window.EndDraw();
	}

	// GetWindow() function that gets the private window variable
	Window* GetWindow()
	{
		return& window;
	}

private:

	Window window;
};