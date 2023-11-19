#pragma once

#include "includes.h"

enum class Behavior
{
	HAPPY,
	SAD,
	EXCITED,
	CALM,
	AGGRESSIVE,
	CURIOUS,
	SCARED
};

enum class Gender
{
	MALE,
	FEMALE
};

enum class HealthStatus
{
	HEALTHY,
	SICK
};

enum class Movement
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UPLEFT,
    UPRIGHT,
    DOWNLEFT,
    DOWNRIGHT,
    IDLE
};

class animal : public sf::RectangleShape
{
public:
	
    // Default constructor
    animal() : hunger(0), age(0), weight(0.0f), sleep(false), name(), behavior(Behavior::CALM), gender(Gender::MALE), healthStatus(HealthStatus::HEALTHY), timeSinceLastRandomMove(0), movement(Movement::IDLE)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // for the AnimalMovement() function
    }

    // Destructor
    ~animal() {}

    // Setter functions

    void setName(const sf::Text& newName)
    {
        name.setString(newName.getString());
    }

    void setAge(unsigned int newAge)
    {
        age = newAge;
    }

    void setGender(Gender newGender)
    {
        gender = newGender;
    }

    void setWeight(float newWeight)
    {
        if (newWeight < 0)
        {
            weight = 0;
        }

        weight = newWeight;
    }

    void setHealthStatus(HealthStatus newHealthStatus)
    {
        healthStatus = newHealthStatus;
    }

    void setBehavior(Behavior newBehavior)
    {
        behavior = newBehavior;
    }

    void setHunger(unsigned int newHunger) 
    {
        if (newHunger < 0)
        {
            hunger = 0;
        }

        hunger = newHunger;
    }

    void setSleep(bool newSleep) 
    {
        sleep = newSleep;
    }

    // Getter functions

    const sf::Text& getName() const
    {
        return name;
    }

    unsigned int getAge() const
    {
        return age;
    }

    Gender getGender() const
    {
        return gender;
    }

    float getWeight() const
    {
        return weight;
    }

    HealthStatus getHealthStatus() const
    {
        return healthStatus;
    }

    Behavior getBehavior() const
    {
        return behavior;
    }

    unsigned int getHunger() const
    {
        return hunger;
    }

    bool getSleep() const
    {
        return sleep;
    }

private:

    // AnimalMovement() function that serves as the general movement for all animals in the game
    void AnimalMovement(animal& animalInstance, float dt)
    {
        // Update the time since the last random move
        animalInstance.timeSinceLastRandomMove += dt;

        // Check if it's time to make a random move
        if (animalInstance.timeSinceLastRandomMove >= animalInstance.timeBetweenRandomMoves)
        {
            // Reset the timer
            animalInstance.timeSinceLastRandomMove = 0;

            // Randomly choose a new movement state
            int randomValue = std::rand() % 100; // A random number between 0 and 99

            if (randomValue < idleProbability)
            {
                animalInstance.movement = Movement::IDLE;
            }
            else
            {
                // Randomly choose one of the other movements
                switch (std::rand() % 8)
                {
                case 0:
                    animalInstance.movement = Movement::UP;
                    break;
                case 1:
                    animalInstance.movement = Movement::DOWN;
                    break;
                case 2:
                    animalInstance.movement = Movement::LEFT;
                    break;
                case 3:
                    animalInstance.movement = Movement::RIGHT;
                    break;
                case 4:
                    animalInstance.movement = Movement::UPLEFT;
                    break;
                case 5:
                    animalInstance.movement = Movement::UPRIGHT;
                    break;
                case 6:
                    animalInstance.movement = Movement::DOWNLEFT;
                    break;
                case 7:
                    animalInstance.movement = Movement::DOWNRIGHT;
                    break;
                case 8:
                    animalInstance.movement = Movement::IDLE;
                    break;
                }
            }
        }

        sf::Vector2f currentPosition = animalInstance.getPosition();

        // Modify the position based on the current movement
        switch (animalInstance.movement)
        {
        case Movement::UP:
            currentPosition.y -= (animalInstance.movementSpeed * dt);
            break;
        case Movement::DOWN:
            currentPosition.y += animalInstance.movementSpeed;
            break;
        case Movement::LEFT:
            currentPosition.x -= animalInstance.movementSpeed;
            break;
        case Movement::RIGHT:
            currentPosition.x += animalInstance.movementSpeed;
            break;
        case Movement::UPLEFT:
            currentPosition.x -= animalInstance.movementSpeed;
            currentPosition.y -= animalInstance.movementSpeed;
            break;
        case Movement::UPRIGHT:
            currentPosition.x += animalInstance.movementSpeed;
            currentPosition.y -= animalInstance.movementSpeed;
            break;
        case Movement::DOWNLEFT:
            currentPosition.x -= animalInstance.movementSpeed;
            currentPosition.y += animalInstance.movementSpeed;
            break;
        case Movement::DOWNRIGHT:
            currentPosition.x += animalInstance.movementSpeed;
            currentPosition.y += animalInstance.movementSpeed;
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

        // Update the animals current position
        animalInstance.move(currentPosition);

    }
    
    // animal class private variables

    Movement movement;
    float movementSpeed = 0.025f;
    float timeSinceLastRandomMove;
    float timeBetweenRandomMoves = 25.0f; // Time in seconds between random moves
    int idleProbability = 70; // Probability (in percentage) of IDLE state / change this later so that we set each animals instance to be differing values i.e sloth

	int hunger;
	int age;
	float weight;
	bool sleep;
	sf::Text name;	
	Behavior behavior;
	Gender gender;
	HealthStatus healthStatus;
};
