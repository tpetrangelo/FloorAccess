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
	int firstFloor{ 0 };
	int lastFloor{ 0 };
	int input{ 0 };

	std::cout << "Welcome to Building Builder 2019!" << std::endl
		<< "Please enter the number of floors for your new building!" << std::endl
		<< "Number of floors (floor 1 is the lobby): ";

	std::cin >> numberOfFloors;

	Building building1(numberOfFloors);
	
	Building::numberOfFloorsLeft.resize( numberOfFloors );
	
	building1.openFloorsLeft();
	
	while (1) {
		building1.printBuildingStatus();

		std::cin >> input;
		if (input == 1) {
			building1.printCompanyStatus();
			std::cin >> input;
			break;
		}
		else if(input==2){
			building1.printOccupantStatus();
			std::cin >> input;
			break;
		}
		else {
			while (input != 1 && input != 2) {
				std::cout << "Invalid Input. Please re-enter: ";
				building1.printBuildingStatus();
				std::cin >> input;
			}

		}
	}
	//Company company1("Test company", 2, 4);
	//company1.printCompanyInfo();
	//building1.openFloorsLeft();

	//Company company2("New Company", 5,5);
	//company2.printCompanyInfo();




	
	
return 0;
}