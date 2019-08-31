#include <iostream>
#include <string>
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "Occupant.h"
int main() {

	int numberOfFloors;
	std::string companyName;
	int firstFloor;
	int lastFloor;

	std::cout << "Welcome to Building Builder 2019!" << std::endl
		<< "Please enter the number of floors for your new building!" << std::endl
		<< "Number of floors (floor 1 is the lobby): ";

	std::cin >> numberOfFloors;

	Building building1(numberOfFloors);


	building1.openFloorsLeft();
	//Company company1("Test company", 2, 4);
	//company1.printCompanyInfo();
	//building1.openFloorsLeft();

	//Company company2("New Company", 5,5);
	//company2.printCompanyInfo();




	
	
return 0;
}