#include "PrintResource.h"
#include "Company.h"
#include <iostream>
#include <string>
PrintResource::PrintResource()
{
}
void PrintResource::printBuildingStatus()
{
	std::cout << "Welcome! Would you like to access:" << std::endl
		<< "[1] - Company" << std::endl << "[2] - Occupant" << std::endl
		<< "Access Choice: ";
}

void PrintResource::printCompanyStatus()
{
	std::cout << "Company Access Menu" << std::endl << "-------------------" << std::endl
		<< "[1] - Add a Company" << std::endl << "[2] - View all current Companies" << std::endl
		<< "Company Menu Choice: ";
}

void PrintResource::printOccupantStatus()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add an Occupant" << std::endl << "[2] - View current number of occupants" << std::endl
		<< "Occupant Menu Choice: ";
}

void PrintResource::runStartMenu()
{
	std::cout << "Welcome to Building Builder 2019!" << std::endl
		<< "Please enter the number of floors for your new building!" << std::endl
		<< "Number of floors (floor 1 is the lobby): ";
}

void PrintResource::newCompanyName()
{
	std::cout << "Please enter the name of your new company: ";
}

void PrintResource::companyAddition(std::string company, int firstFloor, int lastFloor)
{
	std::cout << company << " has been added to the directory!" << std::endl;
	std::cout << company << " first floor: " << firstFloor << std::endl;
	std::cout << company << " last floor: " << lastFloor << std::endl;
}

void PrintResource::guestAddition(std::string firstName, std::string lastName, int age)
{
	std::cout << firstName << " "<< lastName << ", Age: " << age << " has been added to the directory!" << std::endl;
}

void PrintResource::printOccupantOptions()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Guest" << std::endl << "[2] - Company Employee" << std::endl
		<< "[3] - Building Employee" << std::endl
		<< "Occupant Menu Choice: ";

}





