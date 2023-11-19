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
	Dog() : movement(Movement::IDLE) 
	{
		setOrigin(getSize().x / 2, getSize().y / 2);
		setSize(sf::Vector2f(25, 25));
		setFillColor(sf::Color::Cyan);

	}

	// Dog destructor
	~Dog() {}
	
private:
	Movement movement;
    
};