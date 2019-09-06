#include "Guest.h"
#include "Occupant.h"
#include <iostream>

Guest::Guest(std::string fName, std::string lName, std::string status, int age) : Occupant(fName,lName, status)
{
	age = guestAge;
}

Guest::Guest()
{
}

void Guest::setAge(int age)
{
	age = guestAge;
}

int Guest::getAge()
{
	return guestAge;
}

void Guest::printStatus()
{
	std::cout << "First Name: " << firstName << std::endl
		<<  "Last Name: " << lastName << std::endl
		<<  "Age: " << guestAge;
}

void Guest::printOccupantMenu()
{
	std::cout << "Guest Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Guest" << std::endl << "[2] - View all current Guests" << std::endl
		<< "Guest Menu Choice: ";
}

