//Pre-processor directives
#pragma once
#include <string>

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
	void guestAddition(std::string firstName, std::string lastName, int age);
	
	//Output when a new company employee has been added to the directory
	void companyEmployeeAddition(std::string firstName, std::string lastName, std::string companyEmployer);

	//Output when a new building employee has been added to the directory
	void buildingEmployeeAddition(std::string firstName, std::string lastName, std::string position);
	
	//Ouput for options for an occupant
	void printOccupantOptions();
	
	//Outputs the number of occupants, separated by type	
	void printOccupantNumber(int guestCount, int companyEmployeeCount, int buildingEmployeeCount);
};

