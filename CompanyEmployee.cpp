//Pre-processor directives
#include "CompanyEmployee.h"
#include "Occupant.h"
#include <iostream>

//Constructor for CompanyEmployee object, passes first name and last name to Occupant base class
CompanyEmployee::CompanyEmployee(std::string fName, std::string lName, std::string companyWorkedFor) : Occupant(fName, lName)
	{

	//Initializes the company name that a CompanyEmployee works for
	companyEmployed = companyWorkedFor;
	}

//Default constructor for a CompanyEmployee object
CompanyEmployee::CompanyEmployee()
{
	firstName = "John";
	lastName = "Smith";
	companyEmployed = "No Company";
}

//Destructor for a CompanyEmployee object
CompanyEmployee::~CompanyEmployee()
{
}

//Sets the company a CompanyEmployee works for
void CompanyEmployee::setCompanyWorkedFor(std::string company)
{
	companyEmployed = company;
}

//Returns the company that a CompanyEmployee works for
std::string CompanyEmployee::getCompanyWorkedFor() const
{
	return companyEmployed;
}

//Prints out information based on a specfific CompanyEmployee object
void CompanyEmployee::printStatus()
{
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Company Employed At: " << getCompanyWorkedFor() << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

//Prints out menu options based on a specfific BuildingEmployee object
void CompanyEmployee::printOccupantMenu()
{
	std::cout << "Company Employee Access Menu" << std::endl << "--------------------" << std::endl
		<< "[1] - Add a Company Employee" << std::endl << "[2] - View all current Company Employees" << std::endl
		<< "Company Employee Menu Choice: ";

}



