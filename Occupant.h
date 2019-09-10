#pragma once
#include <string>
class Occupant 
{
public:
	Occupant(std::string fName, std::string lName, std::string status);
	Occupant();

	void setFirstName(std::string fName);
	std::string getFirstName() const;

	void setLastName(std::string lName);
	std::string getLastName() const;

	void setOccupantStatus(std::string status);
	std::string getOccupantStatus() const;

	virtual void printStatus() = 0;
	virtual void printOccupantMenu() = 0;

private:
	std::string firstName;
	std::string lastName;
	std::string occupantStatus;
};

