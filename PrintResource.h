#pragma once
#include <string>

class PrintResource
{
public:
	PrintResource();
	void printBuildingStatus();
	void printCompanyStatus();
	void printOccupantStatus();
	void runStartMenu();
	void newCompanyName();
	void companyAddition(std::string company, int firstFloor, int lastFloor);
	void guestAddition(std::string firstName, std::string lastName, int age);
	void buildingEmployeeAddition(std::string firstName, std::string lastName, std::string position);
	void printOccupantOptions();
	void printOccupantNumber(int guestCount, int companyEmployeeCount, int buildingEmployeeCount);
	private:
};

