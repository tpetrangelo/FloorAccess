#include <iostream>
#include <vector>
#include <string>
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "Occupant.h"
#include "PrintResource.h"
int main() {

	int numberOfFloors;
	int input{ 0 };
	int companyCount{ 0 };
	int firstFloor{ 0 };
	int lastFloor{ 0 };
	std::string companyName;
	PrintResource printView;
	printView.runStartMenu();
	std::cin >> numberOfFloors;
	Building building1(numberOfFloors);
	Building::numberOfFloorsLeft.resize( numberOfFloors );
	static std::vector<Company> newCompany;

	while (1) {
		printView.printBuildingStatus();
		std::cin >> input;
		if (input == 1) {
			printView.printCompanyStatus();
			std::cin >> input;
			if (input == 1) {
				companyCount++;
				newCompany.resize(companyCount);
				printView.newCompanyName();
				std::cin >> companyName;
				building1.openFloorsLeft();
				std::cout << "Please enter your company's first floor: ";
				std::cin >> firstFloor;
				std::cout << "Please enter your company's last floor: ";
				std::cin >> lastFloor;
				newCompany.push_back(Company(companyName, firstFloor, lastFloor));
				std::cout << companyName << " has been added to the directory!" << std::endl;
				std::cout << companyName << " first floor: " << firstFloor << std::endl;
				std::cout << companyName << " last floor: " << lastFloor << std::endl;
				continue;
			}
			else if (input == 2) {

			}
			else if (input == 3) {
				for (auto& companies : newCompany) {
					companies.printCompanyInfo();
				}
			}
			else {

			}
		}
		else if (input == 2) {
			printView.printOccupantStatus();
			std::cin >> input;
			break;
		}
		else {
			while (input != 1 && input != 2) {
				std::cout << "Invalid Input. Please re-enter: ";
				printView.printBuildingStatus();
				std::cin >> input;
			}

		}
	}
	
return 0;
}