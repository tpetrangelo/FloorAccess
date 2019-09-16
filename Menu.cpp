//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

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
#include "Occupant.h"


//Initialization of static vectors for each type of resizable object
//derivedOccupantHolder is the base class for derived classes of Occupants
static std::vector<Company> newCompany;
static std::vector<Occupant*> derivedOccupantHolder;

//Static counters for resizable occupants, used for printing out number of occupants in a building
static int guestCount{ 0 };
static int companyEmployeeCount{ 0 };
static int buildingEmployeetCount{ 0 };
static int occupantCount{ 0 };

//Reference variables used for adding to occupant counters
static int& guestCountRef = guestCount;
static int& companyEmployeeCountRef = companyEmployeeCount;
static int& buildingEmployeeCountRef = buildingEmployeetCount;
static int& occupantCountRef = occupantCount;

void Menu::userStartMenu()
{
	//Outputs start menu, asks user to input the number of floors in a building
	printViewRef.runStartMenu();

	//Input for menu
	std::cin >> numberOfFloors;
	std::cout << std::endl;

	//Checks if user-input is less than 0 or equal to 1. Outputs and error message if so
	while (numberOfFloors == 1 || numberOfFloors < 0 || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "There must be a postive number of floors, greater than one , please re-enter: ";

		//Input for menu
		std::cin >> numberOfFloors;
		std::cout << std::endl;
	}
	
	//Creates room for numberOfFloors-1 companies, cast to long type to avoid arithmetic overflow
	newCompany.reserve((long)numberOfFloors-1);

	//Creates a Building obejct with the number of floors based on user input
	Building building(numberOfFloors);

	//Resizes numberOfFloorsLeft vector based on user input 
	Building::numberOfFloorsLeft.resize(numberOfFloors);

}

void Menu::userMenu()
{
	while (1) {

		//Outputs initial options for user
		//Input 1 will bring user to company menu
		//Input 2 will bring user to occupant menu
		printViewRef.printBuildingStatus();

		//Input for Building menu
		std:: cin >> input; 

		//Input Validation
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << std::endl << "Invalid input, please re-enter: ";
			std::cin >> input;
		}
		std::cout << std::endl;

		//Main Menu Input 1: Brings user to company menu
		if (input == 1) {

			//Outputs options for user based on company menu
			printViewRef.printCompanyStatus();

			//Input for menu
			std:: cin >> input;

			//Input Validation
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(80, '\n');
				std::cout << std::endl << "Invalid input, please re-enter: ";
				std::cin >> input;
			}
			std::cout << std::endl;
			
			//Company Menu Input 1: Add a company to the directory
			if (input == 1) {

				//Checks to see if user can add a new company
				if (building.canAddCompany() == false) {
					std::cout << "The directory is full! No more companies can be added" << std::endl << std::endl;
					continue;
				}
				

				//Increments the company counter
				companyCount++;

				//Asks user to input company name
				printViewRef.newCompanyName();

				//Input for menu
				std::cin >> companyName;

				//Input Validation
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(80, '\n');
					std::cout << std::endl << "Invalid input, please re-enter: ";
					std::cin >> input;
				}

				//Prints out open floors left for user to pick for the new company
				building.openFloorsLeft();

				//Input for menu
				std::cout << "Please enter your company's first floor: ";
				std::cin >> firstFloor;

				//Input Validation
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(80, '\n');
					std::cout << std::endl << "Invalid input, please re-enter: ";
					std::cin >> input;
				}

				//Input for menu
				std::cout << "Please enter your company's last floor: ";
				std::cin >> lastFloor;

				//Input Validation
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(80, '\n');
					std::cout << std::endl << "Invalid input, please re-enter: ";
					std::cin >> input;
				}
				std::cout << std::endl;

				//Validates user-input to ensure floor selection was acceptable
				if (building.validateCompanyFloors(firstFloor, lastFloor) == true) {

					//If floor input is okay, push new company on to the newCompany vector
					newCompany.push_back(Company(companyName, firstFloor, lastFloor));

					//Output confirming company has been added to directory
					printViewRef.companyAddition(companyName, firstFloor, lastFloor);
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
			printViewRef.printOccupantStatus();

			//Input for menu
			std:: cin >> input; 

			//Input Validation
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(80, '\n');
				std::cout << std::endl << "Invalid input, please re-enter: ";
				std::cin >> input;
			}

			std::cout << std::endl;


			//Occupant Main Menu Input 1: Add an Occupant
			if (input == 1) {

				//Output options for user based on Occupant Menu
				printViewRef.printOccupantOptions();

				//Input for menu
				std:: cin >> input; 

				//Input Validation
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(80, '\n');
					std::cout << std::endl << "Invalid input, please re-enter: ";
					std::cin >> input;
				}

				std::cout << std::endl;

				//Occupant Options Input 1: Guest menu
				if (input == 1) {
					
					//Print out possible options for user based on Guest object
					guest.printOccupantMenu();

					//Input for menu
					std:: cin >> input; 

					//Input Validation
					while (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(80, '\n');
						std::cout << std::endl << "Invalid input, please re-enter: ";
						std::cin >> input;
					}

					std::cout << std::endl;


					//Guest Menu Input 1: Add a guest
					if (input == 1) {

						//Add to guest counter
						guestCountRef++;
						occupantCountRef++;

						//Create space on derivedOccupantHolder vector for an addtional Guest
						derivedOccupantHolder.reserve(occupantCountRef);

						//Asks user to input details about the new guest
						std::cout << "Please enter your guest's first name: ";
						std::cin >> firstName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}
						
						//Input for menu
						std::cout << "Please enter your guest's last name: ";
						std::cin >> lastName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						//Input for menu
						std::cout << "Please enter your guest's age: ";
						std::cin >> age;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						std::cout << std::endl;

						//Adds guest to directory
						derivedOccupantHolder.push_back(new Guest(firstName, lastName, age));

						//Output confirming the new guest has been added to the directory, uses overloaded Addtion function that determines which function to use
						//base on the third argument
						printViewRef.Addition(firstName, lastName, age);

						//Bring user back to the Building menu
						continue;
					}

					//Guest Menu Input 2:  Return to the Main Menu
					else if (input == 2) {

						//Bring user back to the Building menu
						continue;

					}
					//Guest Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;

						}
					}
				}
				//Occupant Options Input 2: Company Employee menu
				else if (input == 2) {

					//Print out possible options for user based on Company Employee object
					compEmployee.printOccupantMenu();

					//Input for menu
					std::cin >> input; 

					//Input Validation
					while (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(80, '\n');
						std::cout << std::endl << "Invalid input, please re-enter: ";
						std::cin >> input;
					}

					std::cout << std::endl;

					//Company Employee Menu Input 1: Add a Company Employee
					if (input == 1) {

						//Sets companyCheck to false, companyCheck validates that a company exists in the directory for
						//a Company Employee to be employed to
						static bool companyCheck = false;

						//Increments number of Company Employees
						companyEmployeeCountRef++;
						occupantCountRef++;

						//Creates space on the derivedOccupantHolder vector for a new Company Employee
						derivedOccupantHolder.reserve(occupantCountRef);
						std::cout << "Please enter your company employee's first name: ";

						//Input for menu
						std::cin >> firstName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						std::cout << "Please enter your company employee's last name: ";

						//Input for menu
						std::cin >> lastName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						std::cout << "Current Companies in the directory" << std::endl;
						std::cout << "----------------------------------" << std::endl;

						//If there are no companies in the directory, then a Company Employee cannot be added
						if (newCompany.empty() == true) {
							std::cout << "There are no companies in the directory!" << std::endl << std::endl;
							std::cout << firstName << " " << lastName << " could not be added to the directory!" << std::endl << std::endl;

							//Return user to main menu
							continue;
						}

						//If companies do exist in the directory, print out all of the options for a Company Employee to pick from
						//using a range based for loop
						else {

							std::cout << "Company Directory" << std::endl;
							for (auto& company : newCompany) {
								company.printCompanyInfo();
							}

						}

						std::cout << "Please enter your employer based on the provided companies in the directory: ";

						//Input for company employed to
						std::cin >> companyEmployed;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						//If the name input into companyEmployed is in newCompany, set company check to true and break out of the range based for loop
						for (auto& companyDirectory : newCompany) {
							if (companyDirectory.getCompanyName() == companyEmployed) {
								companyCheck = true;
								break;
							}
						}

						//If user input a valid company, then add them into the directory
						if (companyCheck==true) {
							derivedOccupantHolder.push_back( new CompanyEmployee(firstName, lastName, companyEmployed));

							//Output letting user know their new company employee has been added to the directory using an overloaded function
							printViewRef.Addition(firstName, lastName, companyEmployed);
						}

						//Output message if company employee could not be added to the directory
						else {

							std::cout << firstName << " " << lastName << " could not be added, as " << companyEmployed << " is not in directory!" << std::endl;

							//Company Employee could not be added, decrement from counters
							companyEmployeeCountRef--;
							occupantCountRef--;
						}

						continue;

					}

					//Company Employee Menu Input 2:  Return to the Main Menu
					else if (input == 2) {
						//Bring user back to the Building menu
						continue;
					}

					//Company Employee Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;
						}
					}
				}
				//Occupant Options Input 3: Building Employee menu
				else if (input == 3) {

					//Print out possible options for user based on Building Employee object
					buildEmployee.printOccupantMenu();

					//Input for menu
					std:: cin >> input; 

					//Input Validation
					while (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(80, '\n');
						std::cout << std::endl << "Invalid input, please re-enter: ";
						std::cin >> input;
					}

					std::cout << std::endl;


					//Building Employee Menu Input 1: Add a Building Employee
					if (input == 1) {

						//Increment counter for number of Building Employees and occupants
						buildingEmployeeCountRef++;
						occupantCountRef++;

						//Reserve space on derivedOccupantHolder vector for a new Building Employee
						derivedOccupantHolder.reserve(occupantCountRef);

						//Input for Building Employee's first name
						std::cout << "Please enter the building employees's first name: ";
						std::cin >> firstName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}
						
						//Input for Building Employee's last name
						std::cin >> lastName;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						std::cout << "Please enter your building employees's last name: ";

						//Input for Building Employee's position
						std::cout << "Please enter your building employees's position: ";
						std::cin >> position;

						//Input Validation
						while (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(80, '\n');
							std::cout << std::endl << "Invalid input, please re-enter: ";
							std::cin >> input;
						}

						//Add building employee to derivedOccupantHolder vector
						derivedOccupantHolder.push_back(new BuildingEmployee(firstName, lastName, position));

						//Print confirmation that the new Building Employee has been added to the directory, uses overloaded "Addition"
						//function by passing a string in the third argument
						std::cout << std::endl;
						printViewRef.Addition(firstName,lastName,position);
						continue;
					}

					//Building Employee Menu Input 2: Return to the Main Menu
					else if (input == 2) {

						//Bring user back to the Building menu
						continue;
					}

					//Building Employee Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;

						}
					}
				}
				//Occupant Choice  Menu: If 1 or 2 was not entered, output error message and have user re-input
				else {
					while (input != 1 && input != 2 && input != 3) {
						std::cout << "Invalid Input. Please re-enter\n ";
						break;

					}
				}
			}

			//Occupant Main Menu Input 2: Print out number of Occupants, printed by class of occupant (Guest, Company Employee, Building Employee)
			else if (input == 2) {

			//Prints out counter for each type of Occupant
			printViewRef.printOccupantNumber(guestCountRef, companyEmployeeCountRef, buildingEmployeeCountRef);
			continue;
			}

			else if (input == 3) {
			if (derivedOccupantHolder.empty() == true) {
				std::cout << "There are no occupants currently!" << std::endl << std::endl;
				continue;
				}
				std::cout << "All Occupants of the Building" << std::endl;
				for (Occupant* occupantPtr : derivedOccupantHolder) {
					utilityPrint(occupantPtr);
				}
				continue;
			}

			//Occupant Main Menu: If 1 or 2 was not entered, output error message and have user re-input
			else {
				while (input != 1 && input != 2) {
					std::cout << "Invalid Input. Please re-enter\n ";
					break;

				}
			}
			break;
		}

		//Building Menu: If 1 or 2 was not entered, output error message and have user re-input
		else {
			while (input != 1 && input != 2) {
				std::cout << "Invalid Input. Please re-enter\n\n ";
				break;
			}

		}
	}
}

void Menu::utilityPrint(Occupant*  baseClassPtr)
{
	baseClassPtr->printStatus();
}

