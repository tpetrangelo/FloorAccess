//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

//Pre-processor directives
#pragma once
#include <string>
#include "Building.h"

//interface for Company class
class Company
{
public:

	//Constructor for Company object
	Company(std::string nameOfCompany, int firstFloor, int lastFloor);

	//Default constructor for Company object
	Company();

	//Company destructor
	~Company();

	//Sets starting floor for a  Company object
	void setStartingFloor(int sFloor);

	//Returns starting floor for a Company object
	int getStartingFloor() const;

	//Set last floor for a Company object
	void setEndingFloor(int eFloor);

	//Returns last floor for a Company object
	int getEndingFloor() const;

	//Sets the company name for a Company object
	void setCompanyName(std::string cName);

	//Returns the company name for a Company object
	std::string getCompanyName() const;

	//Prints out the name of the Company object, and it's first and last floor
	void printCompanyInfo();


private:

	//Private data members that represent a companies first and last floor, as well as it's name
	int startingFloor;
	int endingFloor;
	std::string companyName;

};

