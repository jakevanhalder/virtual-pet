#pragma once

#include "animal.h"

// implement this further down the road
//enum class Breed
//{
//
//};

class Dog : public animal 
{
public:

	// Dog() default constructor
	Dog() : movement(Movement::IDLE) {}

	// Dog() constructor
	Dog(sf::Vector2f position) : movement(Movement::IDLE)
	{
		setSize(sf::Vector2f(25, 25));
		setOrigin(getSize().x / 2, getSize().y / 2);
		setFillColor(sf::Color::Cyan);
		setPosition(position);
	}

	// Dog destructor
	~Dog() {}
	
private:
	Movement movement;
    
};