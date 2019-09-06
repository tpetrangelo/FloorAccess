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
static int guestCount{ 0 };
static int companyEmployeeCount{ 0 };
static int buildingEmployeeCount{ 0 };


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
		std:: cin >> input; 
		std::cout << std::endl;
		//company menu
		if (input == 1) {
			printView.printCompanyStatus();
			std:: cin >> input;
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
				std::cout << std::endl;
				if (building.validateCompanyFloors(firstFloor, lastFloor) == true) {
					//find out why there is garbage when printing out companies
					newCompany.push_back(Company(companyName, firstFloor, lastFloor));
					printView.companyAddition(companyName, firstFloor, lastFloor);
					std::cout << std::endl;
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
			std:: cin >> input; 
			std::cout << std::endl;
			//Add an Occupant
			if (input == 1) {
				printView.printOccupantOptions();
				std:: cin >> input; 
				std::cout << std::endl;
				//Guest menu
				if (input == 1) {
					guest.printOccupantMenu();
					std:: cin >> input; 
					std::cout << std::endl;
					//add a guest
					if (input == 1) {
						guestCount++;
						newGuest.resize(guestCount);

					
						std::cout << "Please enter your guest's first name: ";
						std::cin >> firstName;
						std::cout << "Please enter your guest's last name: ";
						std::cin >> lastName;
						std::cout << "Please enter your guest's age: ";
						std::cin >> age;
						std::cout << std::endl;
						newGuest.push_back(Guest(firstName, lastName, "Guest", age));
						printView.guestAddition(firstName, lastName, age);
						continue;
					}
					//view all current guests
					else if (input == 2) {
						for (auto& guests : newGuest) {
							guests.printStatus();
						}
						continue;
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
					std:: cin >> input; 
					std::cout << std::endl;
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
					std:: cin >> input; 
					std::cout << std::endl;
					//add a building employee
					if (input == 1) {
						buildingEmployeeCount++;
						newBuildingEmployee.resize(buildingEmployeeCount);
						std::cout << "Please enter the building employees's first name: ";
						std::cin >> firstName;
						std::cout << "Please enter your building employees's last name: ";
						std::cin >> lastName;
						std::cout << "Please enter your building employees's ID Number: ";
						std::cin >> id;
						std::cout << "Please enter your building employees's position: ";
						std::cin >> position;
						newBuildingEmployee.push_back(BuildingEmployee(firstName, lastName,"Building Employee", id, position));
						printView.buildingEmployeeAddition(firstName,lastName,position);
						std::cout << std::endl;
						continue;
					}
					//view all current building employees
					else if (input == 2) {
						for (auto& buildEmp : newBuildingEmployee) {
							buildEmp.printStatus();
						}
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
			//Print out number of Occupants, printed by class of occupant
			else if (input == 2) {
			printView.printOccupantNumber(guestCount, companyEmployeeCount, buildingEmployeeCount);
			continue;
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
