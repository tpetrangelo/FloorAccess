//Pre-processor directives
#include "Company.h"
#include <iostream>

//Constructor for Company object
Company::Company(std::string nameOfCompany, int firstFloor, int lastFloor) : companyName{nameOfCompany},startingFloor{firstFloor},endingFloor{lastFloor}
{
}

//Default constructor for Company object
Company::Company()
{
	companyName = "New Company";
	startingFloor = 2;
	endingFloor = 2;
}

//Company destructor
Company::~Company()
{
}

//Sets starting floor for a  Company object
void Company::setStartingFloor(int sFloor)
{
	startingFloor = sFloor;
}

//Returns starting floor for a Company object
int Company::getStartingFloor() const
{
	return startingFloor;
}

//Set last floor for a Company object
void Company::setEndingFloor(int eFloor)
{
	endingFloor = eFloor;
}

//Returns last floor for a Company object
int Company::getEndingFloor() const
{
	return endingFloor;
}

//Sets the company name for a Company object
void Company::setCompanyName(std::string cName)
{
	companyName = cName;
}

//Returns the company name for a Company object
std::string Company::getCompanyName() const
{
	return companyName;
}

//Prints out the name of the Company object, and it's first and last floor
void Company::printCompanyInfo()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Company Name: " << getCompanyName() << std::endl;

	//If the company's first and last floor are equal (Company is only one floor), print accordingly
	if (getStartingFloor() == getEndingFloor()) {
		std::cout << getCompanyName() << " Occupies Floor: " << getStartingFloor() << std::endl;
	}

	//If company is multiple floors, print range of floors occupied
	else {
		std::cout << getCompanyName() << " Occupies Floors: " << getStartingFloor() << " through " << getEndingFloor() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

}

