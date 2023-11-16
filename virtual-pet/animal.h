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

class animal
{
public:
	
    // Default constructor
    animal() : hunger(0), age(0), weight(0.0f), sleep(false), name(""), behavior(Behavior::CALM), gender(Gender::MALE), healthStatus(HealthStatus::HEALTHY) {}

    // Destructor
    ~animal() {}

    // Setter functions
    void setHunger(int newHunger) 
    {
        hunger = newHunger;
    }

    void setAge(int newAge) 
    {
        age = newAge;
    }

    void setWeight(float newWeight) 
    {
        weight = newWeight;
    }

    void setSleep(bool newSleep) 
    {
        sleep = newSleep;
    }

    void setName(const std::string& newName) 
    {
        name = newName;
    }

    void setBehavior(Behavior newBehavior) 
    {
        behavior = newBehavior;
    }

    void setGender(Gender newGender) 
    {
        gender = newGender;
    }

    void setHealthStatus(HealthStatus newHealthStatus) 
    {
        healthStatus = newHealthStatus;
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
