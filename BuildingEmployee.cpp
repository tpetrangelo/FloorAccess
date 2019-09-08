#include "BuildingEmployee.h"
#include "Occupant.h"
#include <iostream>

BuildingEmployee::BuildingEmployee(std::string fName, std::string lName, std::string status, int identification, std::string position) : Occupant(fName, lName, status)
{
	id = identification;
	buildingPosition = position;
}

BuildingEmployee::BuildingEmployee()
{
	firstName = "Joe";
	lastName = "Smith";
	status = "Building Employee";
	id = 12345;
	buildingPosition = "Building Help";
}

void BuildingEmployee::setPosition(std::string position)
{
	buildingPosition = position;
}

std::string BuildingEmployee::getPosition()
{
	return buildingPosition;
}

void BuildingEmployee::printStatus()
{
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Position: " << getPosition() << std::endl;

	std::cout << "----------------------------------------" << std::endl;

}

void BuildingEmployee::printOccupantMenu()
{
	std::cout << "Building Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Building Employee" << std::endl << "[2] - View all current Building Employees" << std::endl
		<< "Building Employee Menu Choice: ";
}

