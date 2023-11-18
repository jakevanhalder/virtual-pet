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
	Dog() : movement(Movement::IDLE), timeSinceLastRandomMove(0) {}

	// Dog() constructor
	Dog(sf::Vector2f position) : movement(Movement::IDLE), timeSinceLastRandomMove(0)
	{
		character.setSize(sf::Vector2f(25, 25));
		character.setOrigin(character.getSize().x / 2, character.getSize().y / 2);
		character.setFillColor(sf::Color::Cyan);
		character.setPosition(position);

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	// Dog destructor
	~Dog() {}

    // dogName() function that allows the user to set the name of a specific dog

    void render(sf::RenderTarget* target)
    {
        // drawing the character to the window

        target->draw(this->character);
        target->draw(this->getName());
    }


    // updatePosition function that updates the position of the dog based on the current movement
    void updatePosition(float dt)
    {
        // Update the time since the last random move
        timeSinceLastRandomMove += dt;

        // Check if it's time to make a random move
        if (timeSinceLastRandomMove >= timeBetweenRandomMoves)
        {
            // Reset the timer
            timeSinceLastRandomMove = 0;

            // Randomly choose a new movement state
            int randomValue = std::rand() % 100; // A random number between 0 and 99

            if (randomValue < idleProbability)
            {
                movement = Movement::IDLE;
            }
            else
            {
                // Randomly choose one of the other movements
                switch (std::rand() % 8)
                {
                case 0:
                    movement = Movement::UP;
                    break;
                case 1:
                    movement = Movement::DOWN;
                    break;
                case 2:
                    movement = Movement::LEFT;
                    break;
                case 3:
                    movement = Movement::RIGHT;
                    break;
                case 4:
                    movement = Movement::UPLEFT;
                    break;
                case 5:
                    movement = Movement::UPRIGHT;
                    break;
                case 6:
                    movement = Movement::DOWNLEFT;
                    break;
                case 7:
                    movement = Movement::DOWNRIGHT;
                    break;
                case 8:
                    movement = Movement::IDLE;
                    break;
                }
            }
        }
            
        sf::Vector2f currentPosition = getPosition();

        // Modify the position based on the current movement
        switch (movement)
        {
        case Movement::UP:
            currentPosition.y -= movementSpeed;
            break;
        case Movement::DOWN:
            currentPosition.y += movementSpeed;
            break;
        case Movement::LEFT:
            currentPosition.x -= movementSpeed;
            break;
        case Movement::RIGHT:
            currentPosition.x += movementSpeed;
            break;
        case Movement::UPLEFT:
            currentPosition.x -= movementSpeed;
            currentPosition.y -= movementSpeed;
            break;
        case Movement::UPRIGHT:
            currentPosition.x += movementSpeed;
            currentPosition.y -= movementSpeed;
            break;
        case Movement::DOWNLEFT:
            currentPosition.x -= movementSpeed;
            currentPosition.y += movementSpeed;
            break;
        case Movement::DOWNRIGHT:
            currentPosition.x += movementSpeed;
            currentPosition.y += movementSpeed;
            break;
        case Movement::IDLE:
            // No movement
            break;
        }

        // Check boundaries to ensure the dog stays within the window
        /*sf::Vector2f windowSize = sf::Vector2f(500, 500);

        if (currentPosition.x = getPosition().x < 0)
            currentPosition.x = 0;
        else if (currentPosition.x = getPosition().x > windowSize.x)
            currentPosition.x = windowSize.x;

        if (currentPosition.y = getPosition().y < 0)
            currentPosition.y = 0;
        else if (currentPosition.y = getPosition().y > windowSize.y)
            currentPosition.y = windowSize.y;*/

        // Update the position
        character.move(currentPosition);
        
    }
	
private:

    sf::RectangleShape character;
    Movement movement;
    float movementSpeed = 0.015f;
    float timeSinceLastRandomMove;
    float timeBetweenRandomMoves = 25.0f; // Time in seconds between random moves
    int idleProbability = 70; // Probability (in percentage) of IDLE state
};