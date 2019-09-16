//Pre-processor directives
#include "BuildingEmployee.h"
#include "Occupant.h"
#include <iostream>

//Constructor for BuildingEmployee object, passes first name and last name to Occupant base class
BuildingEmployee::BuildingEmployee(std::string fName, std::string lName, std::string position) : Occupant(fName, lName)
{
	//Initializes job title for BuildingEmployee object
	buildingPosition = position;
}

//Default BuildingEmployee object constructor
BuildingEmployee::BuildingEmployee()
{
	firstName = "John";
	lastName = "Smith";
	buildingPosition = "Building Employee";
}

//Destructor for BuildingEmployee object
BuildingEmployee::~BuildingEmployee()
{
}

//sets the job title for a BuildingEmployee object
void BuildingEmployee::setPosition(std::string position)
{
	buildingPosition = position;
}

//Returns job title for a BuildingEmployee object
std::string BuildingEmployee::getPosition() const
{
	return buildingPosition;
}

//Prints out information based on a specfific BuildingEmployee object
void BuildingEmployee::printStatus() 
{
	std::cout << "----------------------------------------" << std::endl;

	//prints out the first and last name, along with the BuildingEmployee's job title
	std::cout << "First Name: " << getFirstName() << ", " << getLastName() << " Position: " << getPosition() << std::endl;

	std::cout << "----------------------------------------" << std::endl << std::endl;

}

//Prints out menu options based on a specfific BuildingEmployee object
void BuildingEmployee::printOccupantMenu()
{
	std::cout << "Building Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Building Employee" << std::endl << "[2] - Main Menu" << std::endl
		<< "Building Employee Menu Choice: ";
}

