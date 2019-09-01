#include "PrintResource.h"
#include "Company.h"
#include <iostream>
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
		<< "[1] - Add a Company" << std::endl << "[2] - Remove a Company" << std::endl
		<< "[3] - View all current Companies" << std::endl << "Company Menu Choice: ";
}

void PrintResource::printOccupantStatus()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add an Occupant" << std::endl << "[2] - Remove an Occupant" << std::endl
		<< "[3] - View all current Occupants" << std::endl << "Occupant Menu Choice: ";
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

void PrintResource::printCompanies()
{
	
}




