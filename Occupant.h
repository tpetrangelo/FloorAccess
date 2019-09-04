#pragma once
#include <string>
class Occupant 
{
public:
	Occupant(std::string fName, std::string lName, std::string status);
	Occupant();

	void setFirstName(std::string fName);
	std::string getFirstName();

	void setLastName(std::string lName);
	std::string getLastName();

	void setOccupantStatus(std::string status);
	std::string getOccupantStatus();

	void printStatus();

private:
	std::string firstName;
	std::string lastName;
	std::string occupantStatus;
};

