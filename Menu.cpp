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

static std::vector<Company> newCompany;
static std::vector<Guest> newGuest;
static std::vector<CompanyEmployee> newCompanyEmployee;
static std::vector<BuildingEmployee> newBuildingEmployee;



Menu::Menu()
{
}

void Menu::userStartMenu()
{
	printView.runStartMenu();
	std::cin >> numberOfFloors;
	Building building(numberOfFloors);
	Building::numberOfFloorsLeft.resize(numberOfFloors);
	Building::numberOfFloorsLeft[0] = 0;
}


void Menu::userMenu()
{
	while (1) {
		printView.printBuildingStatus();
		std::cin >> input;
		std::cout << std::endl;
		//company menu
		if (input == 1) {
			printView.printCompanyStatus();
			std::cin >> input;
			std::cout << std::endl;
			//add a company
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
				if (building.validateCompanyFloors(firstFloor, lastFloor) == true) {
					//find out why there is garbage when printing out companies
					newCompany.push_back(Company(companyName, firstFloor, lastFloor));
					printView.companyAddition(companyName, firstFloor, lastFloor);
				}
				else {
					std::cout << companyName << " could not be added to the directory!" << std::endl;
				}
				continue;
			}
			//view all companies
			else if (input == 2) {
				for (auto& company : newCompany) {
					company.printCompanyInfo();
				}
			}
			//error validation
			else {
				while (input != 1 && input != 2) {
					std::cout << "Invalid Input. Please re-enter" << std::endl;
					break;
				}
			}
		}
		//Occupant Menu
		else if (input == 2) {
			printView.printOccupantStatus();
			std::cin >> input;
			//Add an Occupant
			if (input == 1) {
				printView.printOccupantOptions();
				std::cin >> input;
				//Guest menu
				if (input == 1) {
					//add a guest
					if (input == 1) {
						guestCount++;
						newGuest.resize(guestCount);
						guest.printOccupantMenu();

						guest.printStatus();
						std::cin >> input;
						std::cout << "Please enter your guest's first name: ";
						std::cin >> firstName;
						std::cout << "Please enter your guest's last name: ";
						std::cin >> lastName;
						std::cout << "Please enter your guest's age: ";
						std::cin >> age;
						newGuest.push_back(Guest(firstName, lastName, "Guest", age));
						printView.guestAddition(firstName, lastName, age);
					}
					//view all current guests
					else if (input == 2) {

					}
					//error checking
					else {
						while (input != 1 && input != 2 && input != 3) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;

						}
					}
				}
				//company employee menu
				else if (input == 2) {
					compEmployee.printOccupantMenu();
					compEmployee.printStatus();
					std::cin >> input;
					//add a company employee
					if (input == 1) {

					}
					//view all current company employees
					else if (input == 2) {

					}
					//error checking
					else {
						while (input != 1 && input != 2 && input != 3) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;
						}
					}
				}
				//building employee menu
				else if (input == 3) {
					buildEmpyloyee.printOccupantMenu();
					buildEmpyloyee.printStatus();
					std::cin >> input;
					//add a building employee
					if (input == 1) {

					}
					//view all current building employees
					else if (input == 2) {

					}
					//error checking
					else {
						while (input != 1 && input != 2 && input != 3) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;

						}
					}
				}
				//error validation 
				else {
					while (input != 1 && input != 2 && input != 3) {
						std::cout << "Invalid Input. Please re-enter\n ";
						break;

					}
				}
			}
			//Print out number of Occupants
			else if (input == 2) {

			}
			//validation
			else {
				while (input != 1 && input != 2) {
					std::cout << "Invalid Input. Please re-enter\n ";
					break;

				}
			}
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
