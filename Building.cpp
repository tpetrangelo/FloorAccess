#include <iostream>
#include "Building.h"




Building::Building(int numFloors) : numberOfFloors{numFloors}
{
	while (numFloors < 0)
	{
		std::cout << "Invalid number of floors please re-enter: ";
		std::cin >> numFloors;
	}
	static std::vector<int> numberOfFloorsLeft{ numFloors };

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


