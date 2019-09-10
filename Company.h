#pragma once
#include <string>
#include "Building.h"
class Company
{
public:
	Company(std::string nameOfCompany, int firstFloor, int lastFloor);
	Company();

	void setStartingFloor(int sFloor);
	int getStartingFloor() const;

	void setEndingFloor(int eFloor);
	int getEndingFloor() const;

	void setCompanyName(std::string cName);
	std::string getCompanyName() const;

	void printCompanyInfo();


private:

	int startingFloor;
	int endingFloor;
	std::string companyName;
	Building newBuilding;

};

