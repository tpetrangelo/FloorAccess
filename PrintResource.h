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
private:
};

