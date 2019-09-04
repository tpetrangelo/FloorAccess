#pragma once
#include <string>
#include "Occupant.h"
class CompanyEmployee : public Occupant
{
public:

	CompanyEmployee(std::string fName, std::string lName, std::string status, int identification, std::string companyWorkedFor);
	CompanyEmployee();
	void setCompanyWorkedFor(std::string company);
	std::string getCompanyWorkedFor();

	void setID(int identification);
	int getID();



private:
	std::string firstName;
	std::string lastName;
	std::string companyEmployed;
	int id;
};

