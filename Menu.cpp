//Pre-processor directives
#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Building.h"
#include "BuildingEmployee.h"
#include "Company.h"
#include "CompanyEmployee.h"
#include "Guest.h"
#include "PrintResource.h"

//Initialization of static vectors for each type of resizable object
static std::vector<Company> newCompany;
static std::vector<Guest> newGuest;
static std::vector<CompanyEmployee> newCompanyEmployee;
static std::vector<BuildingEmployee> newBuildingEmployee;

//Static counters for resizable occupants, used for printing out number of occupants in a building
static int guestCount{ 0 };
static int companyEmployeeCount{ 0 };
static int buildingEmployeetCount{ 0 };

//Reference variables used for adding to occupant counters
static int& guestCountRef = guestCount;
static int& companyEmployeetCountRef = companyEmployeeCount;
static int& buildingEmployeetCountRef = buildingEmployeetCount;



void Menu::userStartMenu()
{
	//Outputs start menu, askes user to input the number of floors in a building
	printView.runStartMenu();
	std::cin >> numberOfFloors;
	std::cout << std::endl;

	//Checks if user-input is less than 0 or equal to 1. Outputs and error message if so
	while (numberOfFloors == 1 || numberOfFloors < 0) {
		
		std::cout << "There must be a postive number of floors, greater than one , please re-enter: ";
		std::cin >> numberOfFloors;
		std::cout << std::endl;
	}
	
	//Creates room for numberOfFloors-1 companies
	newCompany.reserve(numberOfFloors-1);

	//Creates a Building obejct with the number of floors based on user input
	Building building(numberOfFloors);

	//Resizes numberOfFloorsLeft vector based on user input 
	Building::numberOfFloorsLeft.reserve(numberOfFloors);

	//Check this
	//Building::numberOfFloorsLeft[0] = 0;
}


void Menu::userMenu()
{
	while (1) {

		//Outputs initial options for user
		//Input 1 will bring user to company menu
		//Input 2 will bring user to occupant menu
		printView.printBuildingStatus();
		std:: cin >> input; 
		std::cout << std::endl;

		//Main Menu Input 1: Brings user to company menu
		if (input == 1) {

			//Outputs options for user based on company menu
			printView.printCompanyStatus();
			std:: cin >> input;
			std::cout << std::endl;
			
			//Company Menu Input 1: Add a company to the directory
			if (input == 1) {

				//Increments the company counter
				companyCount++;

				//Asks user to input company name
				printView.newCompanyName();
				std::cin >> companyName;

				//Prints out open floors left for user to pick for the new company
				building.openFloorsLeft();
				std::cout << "Please enter your company's first floor: ";
				std::cin >> firstFloor;
				std::cout << "Please enter your company's last floor: ";
				std::cin >> lastFloor;
				std::cout << std::endl;

				//Validates user-input to ensure floor selection was acceptable
				if (building.validateCompanyFloors(firstFloor, lastFloor) == true) {

					//If floor input is okay, push new company on to the newCompany vector
					newCompany.push_back(Company(companyName, firstFloor, lastFloor));

					//Output confirming company has been added to directory
					printView.companyAddition(companyName, firstFloor, lastFloor);
					std::cout << std::endl;
				}
				else {
					
					//User input for company floors was not valid
					std::cout << companyName << " could not be added to the directory!" << std::endl << std::endl;
					
					//Decrement number of companies in company count
					companyCount--;
				}

				//Start back at the beginning of the menu screen
				continue;
			}

			//Company Menu Input 2: Outputs all the companies and their respective floors
			else if (input == 2) {

				//If there are no companies in the directory, output error
				if (newCompany.empty() == true) {
					std::cout << "There are no companies in the directory!" << std::endl << std::endl;
				}

				//Print out all the company information using range based for loop
				else {
					std::cout << "Company Directory" << std::endl;
					for (auto& company : newCompany) {
						company.printCompanyInfo();
					}
				}

			}
			//Company Menu: If 1 or 2 was not entered, output error message and have user re-input
			else {
				while (input != 1 && input != 2) {
					std::cout << "Invalid Input. Please re-enter" << std::endl;
					break;
				}
			}
		}
		//Main Menu Input 2: Brings user to Occupant Menu
		else if (input == 2) {

			//Print out options for user in Occupant menu
			printView.printOccupantStatus();
			std:: cin >> input; 
			std::cout << std::endl;


			//Occupant Menu Input 1: Add an Occupant
			if (input == 1) {

				//Output options for user based on Occupant Menu
				printView.printOccupantOptions();
				std:: cin >> input; 
				std::cout << std::endl;

				//Occupant Options Input 1: Guest menu
				if (input == 1) {
					
					//Print out possible options for user based on Guest object
					guest.printOccupantMenu();
					std:: cin >> input; 
					std::cout << std::endl;


					//Guest Menu Input 1: Add a guest
					if (input == 1) {

						//Add to guest counter
						guestCountRef++;

						//Create space on newGuest vector for an addtional Guest
						newGuest.reserve(guestCountRef);

						//Asks user to input details about the new guest
						std::cout << "Please enter your guest's first name: ";
						std::cin >> firstName;
						std::cout << "Please enter your guest's last name: ";
						std::cin >> lastName;
						std::cout << "Please enter your guest's age: ";
						std::cin >> age;
						std::cout << std::endl;

						//Adds guest to directory
						newGuest.push_back(Guest(firstName, lastName, age));

						//Output confirming the new guest has been added to teh directory
						printView.guestAddition(firstName, lastName, age);

						//Bring user back to the Building menu
						continue;
					}
					//Guest Menu Input 2: View all guests in directory
					else if (input == 2) {

						//If there are no current guests, let user know
						if (newGuest.empty() == true) {
							std::cout << "There are no guests in the directory!" << std::endl << std::endl;
						}

						//Output all guest information using range based for loop
						else {
							std::cout << "Guest Directory" << std::endl;
							for (auto& guests : newGuest) {
								guests.printStatus();
							}
						}

						//Bring user back to the Building menu
						continue;
					}
					//Guest Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2 && input != 3) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;

						}
					}
				}
				//Occupant Options Input 2: Guest menu
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
							newCompanyEmployee.push_back(CompanyEmployee(firstName, lastName, companyEmployed));
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
						newBuildingEmployee.push_back(BuildingEmployee(firstName, lastName, position));
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
