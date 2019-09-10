#pragma once
#include <string>
#include "Occupant.h"
class BuildingEmployee :  virtual public Occupant
{
public:

	BuildingEmployee(std::string fName, std::string lName, std::string status, int identification, std::string position);
	BuildingEmployee();
	void setPosition(std::string position);
	std::string getPosition() const;

	virtual void printStatus();
	virtual void printOccupantMenu();

private:
	std::string status;
	std::string firstName;
	std::string lastName;
	std::string buildingPosition;
	int id;
};

