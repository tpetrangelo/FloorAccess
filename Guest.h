//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

//Pre-processor directives
#pragma once
#include <string>
#include "Occupant.h"

//Interface for Guest class the inherits from base class Occupant
class Guest : virtual public Occupant
{
public:

	//Constrcutor for Guest object
	Guest(std::string fName, std::string lName, int age);

	//Default constructor for Guest object
	Guest();

	//Destructor for Guest object
	~Guest();

	//Sets age for a Guest object
	void setAge(int age);

	//Returns age for a Guest object
	int getAge() const;
	
	//Prints out information based on a specfific Guest object
	virtual void printStatus();

	//Prints out menu options based on a specfific Guest object
	virtual void printOccupantMenu();


private:

	//Private data members that represents a Guest's first name, last name, and their age
	std::string firstName;
	std::string lastName;
	int guestAge;

};

