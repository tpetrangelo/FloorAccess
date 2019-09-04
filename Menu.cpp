#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "Occupant.h"
#include "PrintResource.h"

Menu::Menu()
{
}

void Menu::userStartMenu()
{
	printView.runStartMenu();
	std::cin >> numberOfFloors;
	Building building(numberOfFloors);
	Building::numberOfFloorsLeft.resize(numberOfFloors);
	Building::numberOfFloorsLeft[0] = 9999;
}

void Menu::userMenu()
{
	while (1) {
		printView.printBuildingStatus();
		std::cin >> input;
		std::cout << std::endl;;
		if (input == 1) {
			printView.printCompanyStatus();
			std::cin >> input;
			std::cout << std::endl;
			if (input == 1) {
				companyCount++;

				newCompany.resize(companyCount);
				printView.newCompanyName();
				std::cin >> companyName;
				building.openFloorsLeft();
				std::cout << "Please enter your company's first floor: ";
				std::cin >> firstFloor;
				std::cout << "Please enter your company's last floor: ";
				std::cin >> lastFloor;
				building.validateCompanyFloors(firstFloor, lastFloor);
				std::cout << std::endl;
				newCompany.push_back(Company(companyName, firstFloor, lastFloor));
				
				std::cout << companyName << " has been added to the directory!" << std::endl;
				std::cout << companyName << " first floor: " << firstFloor << std::endl;
				std::cout << companyName << " last floor: " << lastFloor << std::endl;
				continue;
			}
			else if (input == 2) {
				for (auto& companies : newCompany) {
					companies.printCompanyInfo();
				}
			}
			else {
				while (input != 1 && input != 2) {
					std::cout << "Invalid Input. Please re-enter" << std::endl;
					break;

				}
			}
		}
		else if (input == 2) {
			printView.printOccupantStatus();
			std::cin >> input;
			break;
		}
		else {
			while (input != 1 && input != 2) {
				std::cout << "Invalid Input. Please re-enter\n ";
				break;

			}

		}
	}
	
}
