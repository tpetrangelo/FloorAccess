//Pre-processor directives
#pragma once
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "PrintResource.h"
#include "Occupant.h"

//Interface for Menu class
class Menu
{
public:

	//userStartMenu creates a bulding object based on the number of floors input by the user
	void userStartMenu();

	//userMenu is the main driver for the program, allowing the user to fill a bulding's directory with companies and occupants
	void userMenu();

private:

	//Composition creating objects that will interract with each other inside of Menu.cpp
	Building building;
	Guest guest;
	PrintResource printView;
	PrintResource& printViewRef{ printView };
	CompanyEmployee compEmployee;
	BuildingEmployee buildEmployee;
	Company company;
	
	//Initialization of integer variables that are private data members of the above composition objects
	
	//Building
	int numberOfFloors{ 0 };
	
	//Menu
	int input{ 0 };
	
	//Menu
	int companyCount{ 0 };
	
	//Guest
	int age{ 0 };
	
	//Company
	int firstFloor{ 0 };
	int lastFloor{ 0 };

	//Initialization of string variables that are private data members of the above composition objects
	
	//Building Employee
	std::string position;
	
	//Occupant
	std::string firstName;
	std::string lastName;
	
	//Company
	std::string companyName;
	
	//Company Employee
	std::string companyEmployed;


};

