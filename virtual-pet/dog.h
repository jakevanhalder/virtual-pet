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

	// Dog() constructor
	Dog(std::string& dogName, int dogAge, float dogWeight, Gender dogGender, int dogSleep)
	{
		setName(dogName);
		setAge(dogAge);
		setWeight(dogWeight);
		setGender(dogGender);
		setSleep(dogSleep);
	}

private:


};