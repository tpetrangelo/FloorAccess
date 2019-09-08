#include <iostream>
#include "Building.h"

std::vector<int> Building::numberOfFloorsLeft;

Building::Building(int numFloors) : numberOfFloors{numFloors}
{
}

Building::Building()
{
	numberOfFloors = 1;
}

Building::~Building()
{
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


bool Building::validateCompanyFloors(int startFloor, int endFloor)
{
	int floorErase = startFloor;
	if (endFloor < startFloor) {
		std::cout << "First floor cannot be greater than last floor of company!" << std::endl;
		return false;
	}
	for (startFloor; startFloor <= endFloor; startFloor++) {
		if (numberOfFloorsLeft.at(startFloor-1) != 0) {
			std::cout << "Floor " << startFloor << " is already occupied!";
			std::cout << std::endl;
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




