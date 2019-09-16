//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

//Pre-processor directives
#include "Occupant.h"

//Occupant object constructor
Occupant::Occupant(std::string fName, std::string lName) : firstName{fName} , lastName{lName}
{
}

//Default constructor for Occupant class
Occupant::Occupant()
{
	firstName = "John";
	lastName = "Smith";
}

//Destrcutor for occupant class
Occupant::~Occupant()
{
}

//Sets the first name of the Occupant object
void Occupant::setFirstName(std::string fName)
{
	firstName = fName;
}

//Sets the last name of the Occupant object
std::string Occupant::getFirstName() const
{
	return firstName;
}

//Returns the last name of the Occupant object
void Occupant::setLastName(std::string lName)
{
	lastName = lName;
}

//Returns the last name of the Occupant object
std::string Occupant::getLastName() const
{
	return lastName;
}





