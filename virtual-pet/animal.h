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
    animal() : hunger(0), age(0), weight(0.0f), sleep(false), name(""), behavior(Behavior::CALM), gender(Gender::MALE), healthStatus(HealthStatus::HEALTHY) {}

    // Destructor
    ~animal() {}

    // Setter functions

    void setName(const std::string& newName)
    {
        name = newName;
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

    const std::string& getName() const
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

	int hunger;
	int age;
	float weight;
	bool sleep;
	std::string name;	
	Behavior behavior;
	Gender gender;
	HealthStatus healthStatus;
};
