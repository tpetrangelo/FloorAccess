//Pre-processor directives
#pragma once
#include <string>
#include "Occupant.h"

//Interface for class CompanyEmployee, inherited by abstract clas Occupant (base)
class CompanyEmployee : virtual public Occupant
{
public:

	//Constructor for CompanyEmployee object
	CompanyEmployee(std::string fName, std::string lName, std::string companyWorkedFor);
	
	//Default constructor for a CompanyEmployee object
	CompanyEmployee();
	
	//Destructor for a CompanyEmployee object
	~CompanyEmployee();

	//Sets the CompanyEmployee's company that they work for
	void setCompanyWorkedFor(std::string company);
	
	//Returns the CompanyEmployee's company that they work for
	std::string getCompanyWorkedFor() const;

	//Prints out information based on a specfific CompanyEmployee object
	virtual void printStatus();

	//Prints out menu options based on a specfific CompanyEmployee object
	virtual void printOccupantMenu();


private:

	//Private data members that represents a CompanyEmployee's first name, last name, and the company they are employed to
	std::string firstName;
	std::string lastName;
	std::string companyEmployed;
	
};

