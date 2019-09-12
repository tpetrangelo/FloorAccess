//Pre-processor directives
#include "PrintResource.h"
#include "Company.h"
#include <iostream>
#include <string>

//Prints options for a building menu
void PrintResource::printBuildingStatus()
{
	std::cout << "Welcome! Would you like to access:" << std::endl
		<< "[1] - Company" << std::endl << "[2] - Occupant" << std::endl
		<< "Access Choice: ";
}

//Prints options for a company menu
void PrintResource::printCompanyStatus()
{
	std::cout << "Company Access Menu" << std::endl << "-------------------" << std::endl
		<< "[1] - Add a Company" << std::endl << "[2] - View all current Companies" << std::endl
		<< "Company Menu Choice: ";
}

//Prints options for an occupant menu
void PrintResource::printOccupantStatus()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Occupant Options" << std::endl << "[2] - View current number of occupants" << std::endl
		<< "Occupant Menu Choice: ";
}

//Opening output and menu options for building creation
void PrintResource::runStartMenu()
{
	std::cout << "Welcome to Building Builder 2019!" << std::endl
		<< "Please enter the number of floors for your new building!" << std::endl
		<< "Number of floors (floor 1 is the lobby): ";
}

//Output asking for user to input new company name
void PrintResource::newCompanyName()
{
	std::cout << "Please enter the name of your new company: ";
}

//Output when a new company has been added to the directory
void PrintResource::companyAddition(std::string company, int firstFloor, int lastFloor)
{
	std::cout << company << " has been added to the directory!" << std::endl;
	std::cout << company << "'s first floor: " << firstFloor << std::endl;
	std::cout << company << "'s last floor: " << lastFloor << std::endl;
}

//Output when a new guest has been added to the directory
void PrintResource::guestAddition(std::string firstName, std::string lastName, int age)
{
	std::cout << firstName << " "<< lastName << ", Age: " << age << " has been added to the directory!" << std::endl;
}

//Output when a new company employee has been added to the directory
void PrintResource::companyEmployeeAddition(std::string firstName, std::string lastName, std::string companyEmployer)
{
	std::cout << firstName << " " << lastName << ", Company: " << companyEmployer << " has been added to the directory!" << std::endl;

}

//Output when a new building employee has been added to the directory
void PrintResource::buildingEmployeeAddition(std::string firstName, std::string lastName, std::string position)
{
	std::cout << firstName << " " << lastName << ", Position: " << position << ", has been added to the directory!" << std::endl;

}

//Ouput for options for an occupant
void PrintResource::printOccupantOptions()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Guest" << std::endl << "[2] - Company Employee" << std::endl
		<< "[3] - Building Employee" << std::endl
		<< "Occupant Menu Choice: ";

}

//Outputs the number of occupants, separated by type	
void PrintResource::printOccupantNumber(int guestCount, int companyEmployeeCount, int buildingEmployeeCount)
{
	std::cout << "Number of Guests - [" << guestCount << "]" << std::endl;
	std::cout << "Number of Company Employees - [" << companyEmployeeCount << "]" << std::endl;
	std::cout << "Number of Building Employees - [" << buildingEmployeeCount << "]" << std::endl;
	std::cout << std::endl;
}

//Overloaded function that will print out distinguishing identifier for a guest (age)
int PrintResource::printIdentifier(Guest guestOverload)
{
	return guestOverload.getAge();
}

//Overloaded function that will print out distinguishing identifier for a building employee (job title)
std::string PrintResource::printIdentifier(BuildingEmployee buildingEmployeeOverload)
{
	return buildingEmployeeOverload.getPosition();
}

//Overloaded function that will print out distinguishing identifier for a company employee (company worked for)
std::string PrintResource::printIdentifier(CompanyEmployee companyEmployeeOverload)
{
	return companyEmployeeOverload.getCompanyWorkedFor();
}





