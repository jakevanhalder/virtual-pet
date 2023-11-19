#pragma once

#include "includes.h"
#include "window.h"
#include "dog.h"
// include other animal headers here

class Game {
public:

	// Game() constructor
	Game() : window("Virtual-pet", sf::Vector2u(500,500)), dog()
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
		window.Draw(dog);
		window.EndDraw();
	}

	// GetWindow() function that gets the private window variable
	Window* GetWindow()
	{
		return& window;
	}

	// GetElapsed() function that measures the time elapsed since the last instance of the clock being restarted
	sf::Time GetElapsed()
	{
		return elapsed;
	}

	// RestartClock() function that restarts the clock/works in tandem with GetElapsed() function
	void RestartClock()
	{
		elapsed = clock.restart();
	}

private:

	Window window;
	sf::Clock clock;
	sf::Time elapsed;
	Dog dog;

};