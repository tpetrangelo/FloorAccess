#include "Company.h"
#include "Building.h"
#include <iostream>
Company::Company(std::string nameOfCompany, int firstFloor, int lastFloor) : companyName{nameOfCompany},startingFloor{firstFloor},endingFloor{lastFloor}
{

}

Company::Company()
{
}

void Company::setStartingFloor(int sFloor)
{
	startingFloor = sFloor;
}

int Company::getStartingFloor() const
{
	return startingFloor;
}

void Company::setEndingFloor(int eFloor)
{
	endingFloor = eFloor;
}

int Company::getEndingFloor() const
{
	return endingFloor;
}

void Company::setCompanyName(std::string cName)
{
	companyName = cName;
}

std::string Company::getCompanyName() const
{
	return companyName;
}

void Company::printCompanyInfo()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Company Name: " << getCompanyName() << std::endl;
	if (getStartingFloor() == getEndingFloor()) {
		std::cout << getCompanyName() << " Occupies Floor: " << getStartingFloor() << std::endl;
	}
	else {
		std::cout << getCompanyName() << " Occupies Floors: " << getStartingFloor() << " through " << getEndingFloor() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

}

