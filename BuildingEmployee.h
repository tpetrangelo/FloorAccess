#pragma once
#include <string>
#include "Occupant.h"
class BuildingEmployee :  virtual public Occupant
{
public:

	BuildingEmployee(std::string fName, std::string lName, std::string status, int identification, std::string position);
	BuildingEmployee();
	void setPosition(std::string position);
	std::string getPosition();

	virtual void printStatus();
	virtual void printOccupantMenu();


private:
	std::string buildingPosition;
	int id;
};

