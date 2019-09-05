#pragma once
#include <string>
#include "Occupant.h"

class Guest : virtual public Occupant
{
public:
	Guest(std::string fName, std::string lName, std::string status, int age);
	Guest();
	void setAge(int age);
	int getAge();
	virtual void printStatus();
	virtual void printOccupantMenu();

private:
	std::string firstName;
	std::string lastName;
	int guestAge;
};

