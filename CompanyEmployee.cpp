#include "CompanyEmployee.h"
#include "Occupant.h"
#include <iostream>
CompanyEmployee::CompanyEmployee(std::string fName, std::string lName, std::string status, int identification, std::string companyWorkedFor) : Occupant(fName, lName, status)
	{
	id = identification; 
	companyEmployed = companyWorkedFor;
	}

CompanyEmployee::CompanyEmployee()
{
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

void CompanyEmployee::printStatus()
{
}

void CompanyEmployee::printOccupantMenu()
{
	std::cout << "Company Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Company Employee" << std::endl << "[2] - View all current Company Employees" << std::endl
		<< "Company Employee Menu Choice: ";

}



