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

	void printOccupantOptions();
	private:
};

