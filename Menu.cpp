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
static int buildingEmployeetCount{ 0 };
static int& guestCountRef = guestCount;
static int& companyEmployeetCountRef = companyEmployeeCount;
static int& buildingEmployeetCountRef = buildingEmployeetCount;



void Menu::userStartMenu()
{
	printView.runStartMenu();
	std::cin >> numberOfFloors;
	std::cout << std::endl;

	while (numberOfFloors == 1 || numberOfFloors < 0) {
		
		std::cout << "There must be a postive number of floors, greater than one , please re-enter: ";
		std::cin >> numberOfFloors;
		std::cout << std::endl;
	}
	
	newCompany.reserve(numberOfFloors-1);
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

				
				printView.newCompanyName();
				std::cin >> companyName;
				building.openFloorsLeft();
				std::cout << "Please enter your company's first floor: ";
				std::cin >> firstFloor;
				std::cout << "Please enter your company's last floor: ";
				std::cin >> lastFloor;
				std::cout << std::endl;
				if (building.validateCompanyFloors(firstFloor, lastFloor) == true) {
					newCompany.push_back(Company(companyName, firstFloor, lastFloor));
					printView.companyAddition(companyName, firstFloor, lastFloor);
					std::cout << std::endl;
				}
				else {
					std::cout << companyName << " could not be added to the directory!" << std::endl << std::endl;
					companyCount--;
				}
				continue;
			}
			//view all companies
			else if (input == 2) {
				if (newCompany.empty() == true) {
					std::cout << "There are no companies in the directory!" << std::endl << std::endl;
				}
				else {
					std::cout << "Company Directory" << std::endl;
					for (auto& company : newCompany) {
						company.printCompanyInfo();
					}
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
						guestCountRef++;
						newGuest.reserve(guestCountRef);

					
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
						if (newGuest.empty() == true) {
							std::cout << "There are no guests in the directory!" << std::endl << std::endl;
						}
						else {
							std::cout << "Guest Directory" << std::endl;
							for (auto& guests : newGuest) {
								guests.printStatus();
							}
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
					std::cin >> input; 
					std::cout << std::endl;
					//add a company employee
					if (input == 1) {
						bool companyCheck = false;
						companyEmployeetCountRef++;
						newCompanyEmployee.reserve(companyEmployeetCountRef);
						std::cout << "Please enter your company employee's first name: ";
						std::cin >> firstName;
						std::cout << "Please enter your company employee's last name: ";
						std::cin >> lastName;
						std::cout << "Current Companies in the directory" << std::endl;
						std::cout << "----------------------------------" << std::endl;
						if (newCompany.empty() == true) {
							std::cout << "There are no companies in the directory!" << std::endl << std::endl;
							std::cout << firstName << " " << lastName << " could not be added to the directory!" << std::endl << std::endl;
							continue;
						}
						else {
							std::cout << "Company Directory" << std::endl;
							for (auto& company : newCompany) {
								company.printCompanyInfo();
							}
						}
						std::cout << "Please enter your company employee's employer based on the provided companies in the directory: ";
						std::cin >> companyEmployed;
						for (auto& companyDirectory : newCompany) {
							if (companyDirectory.getCompanyName() == companyEmployed) {
								companyCheck = true;
								break;
							}
						}

						if (companyCheck) {
							newCompanyEmployee.push_back(CompanyEmployee(firstName, lastName, "Company Employee", companyEmployed));
							printView.companyEmployeeAddition(firstName, lastName, companyEmployed);
						}
						else {
							std::cout << firstName << " " << lastName << " could not be added, as " << companyEmployed << " is not in directory!" << std::endl;
							companyEmployeetCountRef--;
						}
						continue;

					}
					//view all current company employees
					else if (input == 2) {
						if (newCompanyEmployee.empty() == true) {
							std::cout << "There are no company employees in the directory!" << std::endl << std::endl;
						}
						else {
							for (auto& compEmp : newCompanyEmployee) {
								compEmp.printStatus();
							}
						
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
				//building employee menu
				else if (input == 3) {
					buildEmpyloyee.printOccupantMenu();
					std:: cin >> input; 
					std::cout << std::endl;
					//add a building employee
					if (input == 1) {
						buildingEmployeetCountRef++;
						newBuildingEmployee.reserve(buildingEmployeetCountRef);
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
						if (newBuildingEmployee.empty() == true) {
							std::cout << "There are no building employees in the directory!" << std::endl << std::endl;
						}
						else {
							std::cout << "Building Employee Directory" << std::endl;
							for (auto& buildEmp : newBuildingEmployee) {
								buildEmp.printStatus();
							}
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
			printView.printOccupantNumber(guestCountRef, companyEmployeetCountRef, buildingEmployeetCountRef);
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

void Menu::printStatus()
{
	std::cout << "Placeholder" << std::endl;
}

void Menu::printOccupantMenu()
{
	std::cout << "Placeholder" << std::endl;

}
