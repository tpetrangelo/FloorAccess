#include "CompanyEmployee.h"
#include "Occupant.h"
CompanyEmployee::CompanyEmployee(std::string fName, std::string lName, std::string status, int identification, std::string companyWorkedFor) : Occupant(fName, lName, status)
	{
	id = identification; 
	companyEmployed = companyWorkedFor;
	}


void CompanyEmployee::setCompanyWorkedFor(std::string company)
{
	companyEmployed = company;
}

std::string CompanyEmployee::getCompanyWorkedFor()
{
	return companyEmployed;
}

void CompanyEmployee::setID(int identification)
{
	identification = id;
}

int CompanyEmployee::getID()
{
	return id;
}



