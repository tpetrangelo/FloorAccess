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
	std::cout << "First Name: " << firstName << std::endl
		<< "Last Name: " << lastName << std::endl
		<< "Position: " << buildingPosition;
}

void BuildingEmployee::printOccupantMenu()
{
	std::cout << "Building Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Building Employee" << std::endl << "[2] - View all current Building Employees" << std::endl
		<< "Building Employee Menu Choice: ";
}

