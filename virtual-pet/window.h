#pragma once

#include "includes.h"

class Window {
public:

	// Window() default constructor
	Window()
	{
		Setup("Window", sf::Vector2u(500, 500));
	}

	// Window() constructor
	Window(const std::string& newTitle, const sf::Vector2u& newSize)
	{
		Setup(newTitle, newSize);
	}

	// Window destructor
	~Window()
	{
		Destroy();
	}

	// BeginDraw() function that clears the window
	void BeginDraw()
	{
		window.clear(sf::Color::Black);
	}

	// EndDraw() function that displays the changes
	void EndDraw()
	{
		window.display();
	}


	// Update() function that updates the events in the game
	void Update()
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				isDone = true;
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				isDone = true;
			}
		}
	}


	// IsDone() function that terminates the game
	bool IsDone()
	{
		return isDone;
	}

	// GetWindowSize() function that gets the private windowSize variable
	sf::Vector2u GetWindowSize()
	{
		return windowSize;
	}


	// Draw() function that draws out objects
	void Draw(sf::Drawable& newDrawable)
	{
		window.draw(newDrawable);
	}

private:

	// Setup() private function that sets up the window
	void Setup(const std::string& newTitle, const sf::Vector2u& newSize)
	{
		windowTitle = newTitle;
		windowSize = newSize;
		isDone = false;
		Create();
	}

	// Destroy() private function that helps the Window destructor
	void Destroy()
	{
		window.close();
	}

	// Create() private function that 
	void Create()
	{
		auto style = (sf::Style::Titlebar | sf::Style::Close);
		window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
	}

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	std::string windowTitle;
	bool isDone;
};