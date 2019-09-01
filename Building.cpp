#include <iostream>
#include "Building.h"

std::vector<int> Building::numberOfFloorsLeft;

Building::Building(int numFloors) : numberOfFloors{numFloors}
{
	while (numFloors < 0)
	{
		std::cout << "Invalid number of floors please re-enter: ";
		std::cin >> numFloors;
	}

}

Building::Building()
{
	numberOfFloors = 1;
}

Building::~Building()
{
}



void Building::giveAccess()
{
}

void Building::removeAccess()
{
}

bool Building::hasAccess()
{
	return false;
}


void Building::openFloorsLeft()
{
	std::cout << "Floors open for occupation: ";
	for (size_t i = 1; i < numberOfFloorsLeft.size(); i++) {
		if (numberOfFloorsLeft[i] == 0) {
			std::cout << "[" <<  i + 1 << "] ";
		}
	}
	std::cout << std::endl;
}

void Building::companyFloor(int start, int end)
{
	int companiesUsedFloors = end - start;

	for (start; start <= end; start++) {
		if (numberOfFloorsLeft[start - 1] != 0) {
			std::cout << "Floor " << start-1 << " already occupied!";
			break;
		}
		else {
			numberOfFloorsLeft[start - 1] = start;
		}
		
	}
}

void Building::printBuildingStatus()
{
	std::cout << "Welcome! Would you like to access:" << std::endl
		<< "[1] - Company" << std::endl << "[2] - Occupant" << std::endl
		<< "Access Choice: " ;
}

void Building::printCompanyStatus()
{
	std::cout << "Company Access Menu" << std::endl << "-------------------" << std::endl
		<< "[1] - Add a Company" << std::endl << "[2] - Remove a Company" << std::endl
		<< "[3] - View all current Companies" << std::endl << "Company Menu Choice: ";
}

void Building::printOccupantStatus()
{
	std::cout << "Occupant Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add an Occupant" << std::endl << "[2] - Remove an Occupant" << std::endl
		<< "[3] - View all current Occupants" << std::endl << "Occupant Menu Choice: ";
}


