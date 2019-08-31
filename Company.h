#pragma once
#include <string>
#include "Building.h"
class Company
{
public:
	Company(std::string nameOfCompany, int firstFloor, int lastFloor);


	void setStartingFloor(int sFloor);
	int getStartingFloor();

	void setEndingFloor(int eFloor);
	int getEndingFloor();

	void setCompanyName(std::string cName);
	std::string getCompanyName();

	void printCompanyInfo();

private:
	int startingFloor;
	int endingFloor;
	std::string companyName;
	Building newBuilding;
};

