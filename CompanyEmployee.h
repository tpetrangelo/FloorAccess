#pragma once
#include <string>
#include "Occupant.h"
class CompanyEmployee : virtual public Occupant
{
public:

	CompanyEmployee(std::string fName, std::string lName, std::string status, std::string companyWorkedFor);
	CompanyEmployee();
	void setCompanyWorkedFor(std::string company);
	std::string getCompanyWorkedFor();

	void setID(int identification);
	int getID();

	virtual void printStatus();
	virtual void printOccupantMenu();


private:
	std::string firstName;
	std::string lastName;
	std::string companyEmployed;
	
};

