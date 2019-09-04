#include <iostream>
#include "Building.h"

std::vector<int> Building::numberOfFloorsLeft;

Building::Building(int numFloors) : numberOfFloors{numFloors}
{
	if (numFloors == 1) {
		std::cout << "There is only one floor for the lobby!" << std::endl << std::endl;
		
	}
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

//void Building::companyFloor(int start, int end)
//{
//	int companiesUsedFloors = end - start;
//	std::cout << std::endl;
//	for (start; start <= end; start++) {
//		if (numberOfFloorsLeft[start - 1] != 0) {
//			std::cout << "Floor " << start-1 << " already occupied!";
//			break;
//		}
//		else {
//			numberOfFloorsLeft[start - 1] = start;
//		}
//		
//	}
//}

bool Building::validateCompanyFloors(int startFloor, int endFloor)
{
	int floorErase = startFloor;
	if (endFloor < startFloor) {
		std::cout << "First floor cannot be greater than last floor of company!" << std::endl;
		return false;
	}
	for (startFloor; startFloor <= endFloor; startFloor++) {
		if (numberOfFloorsLeft.at(startFloor-1) != 0) {
			std::cout << "Floor " << startFloor << " already occupied!";
			for (floorErase; floorErase <= startFloor; floorErase++) {
				numberOfFloorsLeft.at(floorErase - 1) = 0;
			}
			return false;
		}
		else {
			numberOfFloorsLeft.at(startFloor - 1) = startFloor;
		}
	}
	return true;
}




