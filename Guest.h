#pragma once
#include <string>
#include "Occupant.h"

class Guest : public Occupant
{
public:
	Guest(std::string fName, std::string lName, std::string status, int age);

	void setAge(int age);
	int getAge();

private:
	std::string firstName;
	std::string lastName;
	int guestAge;
};

