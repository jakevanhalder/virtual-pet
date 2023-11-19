#pragma once

#include "includes.h"

enum button_states { IDLE = 0, HOVER, ACTIVE };

class button
{
public:

	// button constructor

	button(float x, float y, float newWidth, float newHeight, sf::Font* newFont, std::string newText, sf::Color newIdleColor, sf::Color newHoverColor, sf::Color newActiveColor)
	{
		this->text.setPosition(sf::Vector2f(x, y));
		this->shape.setSize(sf::Vector2f(newWidth, newHeight));

		this->font = newFont;
		this->text.setFont(*this->font);
		this->text.setString(newText);
		this->text.setFillColor(sf::Color::Cyan);
		this->text.setOutlineColor(sf::Color::Black);
		this->text.setOutlineThickness(1);
		this->text.setCharacterSize(24);
		this->shape.setPosition(
			(this->text.getPosition().x + this->text.getGlobalBounds().width / 2.0) - this->shape.getGlobalBounds().width / 2.0,
			(this->text.getPosition().y + this->text.getGlobalBounds().height / 2.0) - this->shape.getGlobalBounds().height / 2.0 - 13.0
		);

		this->idleColor = newIdleColor;
		this->hoverColor = newHoverColor;
		this->activeColor = newActiveColor;

		this->shape.setFillColor(this->idleColor);

		this->buttonState = IDLE;
	}

	// button destructor

	~button() {};

	// isPressed() function that checks to see if the button was clicked
	bool isPressed() const 
	{
		if (this->buttonState == ACTIVE)
		{
			return true;			
		}

		return false;
	}

	// update() function that checks for if the button is being hovered or pressed
	void update(const sf::Vector2f mousePos)
	{
		this->buttonState = IDLE; // if nothing happens the button will just keep being idle

		if (this->shape.getGlobalBounds().contains(mousePos)) // hover
		{
			this->buttonState = HOVER;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // if the button is pressed
			{
				this->buttonState = ACTIVE;
			}
		}

		switch (this->buttonState)
		{
		case IDLE:
			this->shape.setFillColor(this->idleColor);
			break;

		case HOVER:
			this->shape.setFillColor(this->hoverColor);
			break;

		case ACTIVE:
			this->shape.setFillColor(this->activeColor);
			break;

			// this shouldn't happen unless the program breaks
		default:
			this->shape.setFillColor(sf::Color::Red);
			break;

		}
	}

	// render() function that shows the button to the screen
	void render(sf::RenderTarget* target)
	{
		target->draw(this->shape);
		target->draw(this->text);
	}


private:

	sf::RectangleShape shape; // buttons basic shape
	sf::Font* font;
	sf::Text text; // for the text that will be in the button

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	short unsigned buttonState;

};