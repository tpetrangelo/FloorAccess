//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

//Pre-processor directives
#pragma once
#include <string>
#include "Guest.h"
#include "BuildingEmployee.h"
#include "CompanyEmployee.h"

//Interface for class PrintResource
class PrintResource
{
public:

	//Prints options for a building menu
	void printBuildingStatus();
	
	//Prints options for a company menu
	void printCompanyStatus();
	
	//Prints options for an occupant menu
	void printOccupantStatus();
	
	//Opening output and menu options for building creation
	void runStartMenu();
	
	//Output asking for user to input new company name
	void newCompanyName();
	
	//Output when a new company has been added to the directory
	void companyAddition(std::string company, int firstFloor, int lastFloor);
	
	//Output when a new guest has been added to the directory
	void Addition(std::string firstName, std::string lastName, int age);
	
	//Output when a new company or building employee has been added to the directory
	void Addition(std::string firstName, std::string lastName, std::string identifier);
	
	//Ouput for options for an occupant
	void printOccupantOptions();
	
	//Outputs the number of occupants, separated by type	
	void printOccupantNumber(int guestCount, int companyEmployeeCount, int buildingEmployeeCount);

	int printIdentifier(Guest guestOverload);
	std::string printIdentifier(BuildingEmployee buildingEmployeeOverload);
	std::string printIdentifier(CompanyEmployee companyEmployeeOverload);
};

