//Pre-processor directives
#include "Guest.h"
#include "Occupant.h"
#include <iostream>

//Constructor for Guest object, passes first name and last name to Occupant base class
Guest::Guest(std::string fName, std::string lName, int age) : Occupant(fName,lName)
{
	//Initializes age of Guest object
	guestAge = age;
}

//Default constructor for a Guest object
Guest::Guest()
{
	firstName = "John";
	lastName = "Smith";
	guestAge = 1;
}

//Destructor for Guest object
Guest::~Guest()
{
}

//Sets age for a Guest object
void Guest::setAge(int age)
{
	age = guestAge;
}

//Returns age for a Guest object
int Guest::getAge() const
{
	return guestAge;
}

//Prints out information based on a specfific Guest object (first name, last name, and age)
void Guest::printStatus()
{
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Age: " << getAge() << std::endl;

	std::cout << "----------------------------------------" << std::endl;

}

//Prints out menu options based on a specfific Guest object
void Guest::printOccupantMenu()
{
	std::cout << "Guest Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Guest" << std::endl << "[2] - View all current Guests" << std::endl
		<< "Guest Menu Choice: ";
}

