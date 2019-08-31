#include "BuildingEmployee.h"


BuildingEmployee::BuildingEmployee(std::string fName, std::string lName, std::string status, int identification, std::string position) : Occupant(fName, lName, status)
{
	id = identification;
	buildingPosition = position;
}

void BuildingEmployee::setPosition(std::string position)
{
	buildingPosition = position;
}

std::string BuildingEmployee::getPosition()
{
	return buildingPosition;
}
