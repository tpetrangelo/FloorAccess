#include "Company.h"
#include "Building.h"
#include <iostream>
Company::Company(std::string nameOfCompany, int firstFloor, int lastFloor) : companyName{nameOfCompany},startingFloor{firstFloor},endingFloor{lastFloor}
{
	while (firstFloor == 1)
	{
		std::cout << "Floor 1 is the lobby, please re-enter a starting floor for your company: ";
		std::cin >> firstFloor;
	}
	while (endingFloor < startingFloor) {
		std::cout << "Last floor occupied of your company must be larger than it's starting floor, please re-enter";
			newBuilding.openFloorsLeft();
			std::cout << "Starting floor: ";
			std::cin >> startingFloor;
			std::cout << "Ending floor: ";
			std::cin >> endingFloor;
	}
	newBuilding.companyFloor(firstFloor, lastFloor);
}

Company::Company()
{
}

void Company::setStartingFloor(int sFloor)
{
	startingFloor = sFloor;
}

int Company::getStartingFloor()
{
	return startingFloor;
}

void Company::setEndingFloor(int eFloor)
{
	endingFloor = eFloor;
}

int Company::getEndingFloor()
{
	return endingFloor;
}

void Company::setCompanyName(std::string cName)
{
	companyName = cName;
}

std::string Company::getCompanyName()
{
	return companyName;
}

void Company::printCompanyInfo()
{
	std::cout << "Company Name: " << getCompanyName() << std::endl;
	if (getStartingFloor() == getEndingFloor()) {
		std::cout << getCompanyName() << " Occupied Floor: " << getStartingFloor() << std::endl;
	}
	else {
		std::cout << getCompanyName() << " Occupied Floors: " << getStartingFloor() << " through " << getEndingFloor() << std::endl;
	}

}

void Company::printStatus()
{

}
