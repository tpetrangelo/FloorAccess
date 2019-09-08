#pragma once
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "Occupant.h"
#include "PrintResource.h"
class Menu
{
public:
	void userStartMenu();
	void userMenu();

private:
	Building building;
	Occupant occupants;
	Guest guest;
	PrintResource printView;
	CompanyEmployee compEmployee;
	BuildingEmployee buildEmpyloyee;
	Company company;

	int numberOfFloors{ 0 };
	int input{ 0 };
	int companyCount{ 0 };

	int firstFloor{ 0 };
	int lastFloor{ 0 };
	int id{ 0 };
	std::string position;
	std::string firstName;
	std::string lastName;
	int age{ 0 };
	std::string companyName;
	std::string companyEmployed;


};

