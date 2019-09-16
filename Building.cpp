//Pre-processor directives
#include <iostream>
#include "Building.h"

//Static vector containing the number of open floors left in a building for a company to occupy
std::vector<int> Building::numberOfFloorsLeft;



//Building constructor
Building::Building(int numFloors) : numberOfFloors{numFloors}
{
}

//Default Building constructor
Building::Building()
{
	//set private data member numberOfFloors to 2
	numberOfFloors = 2;
}

//building destructor
Building::~Building()
{
}

//Prints out the number of floors left for a new company to choose from
void Building::openFloorsLeft()
{
	
	std::cout << "Floors open for occupation: ";
	//for floor 2 to the size of the numberOfFloorsLeft, if an element is equal to 0, then it is a open floor, print out that floor number
	for (size_t i = 1; i < numberOfFloorsLeft.size(); i++) {
		if (numberOfFloorsLeft[i] == 0) {
			std::cout << "[" <<  i + 1 << "] ";
		}
	}
	std::cout << std::endl;
}

//Checks to ensure user can add a new company to the directory
//Iterates through numberOfFloorsLeft to find any empty elements
//If there are "zero" filled elements, user can add at least one company
//Else, directory is full
bool Building::canAddCompany()
{
	for (size_t i = 1; i < numberOfFloorsLeft.size(); i++) {
		if (numberOfFloorsLeft[i] == 0) {
			return true;
			break;
		}
	}
	return false;
}

//checks to make sure user input floors for their company is valid, takes in a starting and ending floor
bool Building::validateCompanyFloors(int startFloor, int endFloor)
{
	//floorErase initializes as startFloor that is passed in
	int floorErase = startFloor;

	//If the last floor from the user-input is greater than the size of the building, output an error
	if (endFloor > numberOfFloorsLeft.size()) {
		std::cout << "Last floor cannot be greater than the top floor of the building!" << std::endl << std::endl;
		return false;
	}

	//If the last floor of a new company is less than its starting floor, output error message and return false
	if (endFloor < startFloor) {
		std::cout << "First floor cannot be greater than last floor of company!" << std::endl;
		return false;
	}
	//Iterate through vector numberOfFloors left and check if any of the floors input by the user are already occupied
	for (startFloor; startFloor <= endFloor; startFloor++) {
		if (numberOfFloorsLeft.at(startFloor-1) != 0) {
			std::cout << "Floor " << startFloor << " is already occupied!";
			std::cout << std::endl;

			//If there is an occupied floor, then set all floors currently iterated over back to 0, signifiying it is free
			for (floorErase; floorErase <= startFloor; floorErase++) {
				numberOfFloorsLeft.at(floorErase - 1) = 0;
			}
			return false;
		}

		//If floors are not occupied, add user-input floors into the vector
		else {
			numberOfFloorsLeft.at(startFloor - 1) = startFloor;
		}
	}
	//Return true if all input floors were unoccupied
	return true;
}




