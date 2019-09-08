#include "CompanyEmployee.h"
#include "Occupant.h"
#include <iostream>
CompanyEmployee::CompanyEmployee(std::string fName, std::string lName, std::string status, std::string companyWorkedFor) : Occupant(fName, lName, status)
	{
	companyEmployed = companyWorkedFor;
	}

CompanyEmployee::CompanyEmployee()
{
	companyEmployed = "NULL";
}


void CompanyEmployee::setCompanyWorkedFor(std::string company)
{
	companyEmployed = company;
}

std::string CompanyEmployee::getCompanyWorkedFor()
{
	return companyEmployed;
}


void CompanyEmployee::printStatus()
{
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Company Employed At: " << getCompanyWorkedFor() << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

void CompanyEmployee::printOccupantMenu()
{
	std::cout << "Company Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Company Employee" << std::endl << "[2] - View all current Company Employees" << std::endl
		<< "Company Employee Menu Choice: ";

}



