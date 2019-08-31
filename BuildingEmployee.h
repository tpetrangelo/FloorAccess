#pragma once
#include <string>
#include "Occupant.h"
class BuildingEmployee : public Occupant
{
public:

	BuildingEmployee(std::string fName, std::string lName, std::string status, int identification, std::string position);

	void setPosition(std::string position);
	std::string getPosition();

private:
	std::string buildingPosition;
	int id;
};

