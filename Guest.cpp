#include "Guest.h"
#include "Occupant.h"
#include <iostream>

Guest::Guest(std::string fName, std::string lName, std::string status, int age) : Occupant(fName,lName, status)
{
	guestAge = age;
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
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Age: " << getAge() << std::endl;

	std::cout << "----------------------------------------" << std::endl;

}

void Guest::printOccupantMenu()
{
	std::cout << "Guest Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Guest" << std::endl << "[2] - View all current Guests" << std::endl
		<< "Guest Menu Choice: ";
}

