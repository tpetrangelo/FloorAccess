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
static int& companyEmployeeCountRef = companyEmployeeCount;
static int& buildingEmployeeCountRef = buildingEmployeetCount;



void Menu::userStartMenu()
{
	//Outputs start menu, askes user to input the number of floors in a building
	printView.runStartMenu();

	//Input for menu
	std::cin >> numberOfFloors;
	std::cout << std::endl;

	//Checks if user-input is less than 0 or equal to 1. Outputs and error message if so
	while (numberOfFloors == 1 || numberOfFloors < 0) {
		
		std::cout << "There must be a postive number of floors, greater than one , please re-enter: ";

		//Input for menu
		std::cin >> numberOfFloors;
		std::cout << std::endl;
	}
	
	//Creates room for numberOfFloors-1 companies
	newCompany.reserve(numberOfFloors-1);

	//Creates a Building obejct with the number of floors based on user input
	Building building(numberOfFloors);

	//Resizes numberOfFloorsLeft vector based on user input 
	Building::numberOfFloorsLeft.resize(numberOfFloors);

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

		//Input for menu
		std:: cin >> input; 
		std::cout << std::endl;

		//Main Menu Input 1: Brings user to company menu
		if (input == 1) {

			//Outputs options for user based on company menu
			printView.printCompanyStatus();

			//Input for menu
			std:: cin >> input;
			std::cout << std::endl;
			
			//Company Menu Input 1: Add a company to the directory
			if (input == 1) {

				//Increments the company counter
				companyCount++;

				//Asks user to input company name
				printView.newCompanyName();

				//Input for menu
				std::cin >> companyName;

				//Prints out open floors left for user to pick for the new company
				building.openFloorsLeft();
				std::cout << "Please enter your company's first floor: ";

				//Input for menu
				std::cin >> firstFloor;
				std::cout << "Please enter your company's last floor: ";

				//Input for menu
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

			//Input for menu
			std:: cin >> input; 
			std::cout << std::endl;


			//Occupant Main Menu Input 1: Add an Occupant
			if (input == 1) {

				//Output options for user based on Occupant Menu
				printView.printOccupantOptions();

				//Input for menu
				std:: cin >> input; 
				std::cout << std::endl;

				//Occupant Options Input 1: Guest menu
				if (input == 1) {
					
					//Print out possible options for user based on Guest object
					guest.printOccupantMenu();

					//Input for menu
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

						//Input for menu
						std::cin >> firstName;
						std::cout << "Please enter your guest's last name: ";

						//Input for menu
						std::cin >> lastName;
						std::cout << "Please enter your guest's age: ";

						//Input for menu
						std::cin >> age;
						std::cout << std::endl;

						//Adds guest to directory
						newGuest.push_back(Guest(firstName, lastName, age));

						//Output confirming the new guest has been added to the directory, uses overloaded printIdentifier function that takes in an object
						printView.guestAddition(firstName, lastName, printView.printIdentifier(newGuest.back()));

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
				//Occupant Options Input 2: Company Employee menu
				else if (input == 2) {

					//Print out possible options for user based on Company Employee object
					compEmployee.printOccupantMenu();

					//Input for menu
					std::cin >> input; 
					std::cout << std::endl;


					//Company Employee Menu Input 1: Add a Company Employee
					if (input == 1) {

						//Sets companyCheck to false, companyCheck validates that a company exists in the directory for
						//a Company Employee to be employed to
						bool companyCheck = false;

						//Increments number of Company Employees
						companyEmployeeCountRef++;

						//Creates space on the newCompany vector for a new Company Employee
						newCompanyEmployee.reserve(companyEmployeeCountRef);
						std::cout << "Please enter your company employee's first name: ";

						//Input for menu
						std::cin >> firstName;
						std::cout << "Please enter your company employee's last name: ";

						//Input for menu
						std::cin >> lastName;
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
						else {
							std::cout << "Company Directory" << std::endl;
							for (auto& company : newCompany) {
								company.printCompanyInfo();
							}
						}


						std::cout << "Please enter your employer based on the provided companies in the directory: ";

						//Input for company employed to
						std::cin >> companyEmployed;

						//If the name input into companyEmployed is in newCompany, set company check to true and break out of the range based for loop
						for (auto& companyDirectory : newCompany) {
							if (companyDirectory.getCompanyName() == companyEmployed) {
								companyCheck = true;
								break;
							}
						}

						//If user input a valid company, then add them into the directory
						if (companyCheck==true) {
							newCompanyEmployee.push_back(CompanyEmployee(firstName, lastName, companyEmployed));
							printView.companyEmployeeAddition(firstName, lastName, printView.printIdentifier(newCompanyEmployee.back()));
						}

						//Output message if company employee could not be added to the directory
						else {
							std::cout << firstName << " " << lastName << " could not be added, as " << companyEmployed << " is not in directory!" << std::endl;

							//Company Employee could not be added, decrement from counter
							companyEmployeeCountRef--;
						}
						continue;

					}
					//Company Employee Menu Input 2: View all Company Employees
					else if (input == 2) {

						//If there are no Company Employees, then output message letting user know
						if (newCompanyEmployee.empty() == true) {
							std::cout << "There are no company employees in the directory!" << std::endl << std::endl;
						}
						else {

							//Print out first and last name, along with company they work for
							for (auto& compEmp : newCompanyEmployee) {
								compEmp.printStatus();
							}
						
						}
						continue;
					}
					//Company Employee Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2 && input != 3) {
							std::cout << "Invalid Input. Please re-enter\n ";
							break;
						}
					}
				}
				//Occupant Options Input 3: Building Employee menu
				else if (input == 3) {

					//Print out possible options for user based on Company Employee object
					buildEmpyloyee.printOccupantMenu();

					//Input for menu
					std:: cin >> input; 
					std::cout << std::endl;


					//Company Employee Menu Input 2: Add a Building Employee
					if (input == 1) {

						//Increment counter for number of Building Employees
						buildingEmployeeCountRef++;

						//Reserve space on newBuildingEmployee vector for a new Building Employee
						newBuildingEmployee.reserve(buildingEmployeeCountRef);


						std::cout << "Please enter the building employees's first name: ";

						//Input for Building Employee's first name
						std::cin >> firstName;
						std::cout << "Please enter your building employees's last name: ";

						//Input for Building Employee's last name
						std::cin >> lastName;
						std::cout << "Please enter your building employees's position: ";

						//Input for Building Employee's position
						std::cin >> position;

						//Add employee to newBuildingEmployee vector
						newBuildingEmployee.push_back(BuildingEmployee(firstName, lastName, position));

						//Print confirmation that the new Building Employee has been added to the directory, uses overloaded "printIdentifier"
						//function by passing in type Building Employee
						printView.buildingEmployeeAddition(firstName,lastName,printView.printIdentifier(newBuildingEmployee.back()));
						std::cout << std::endl;
						continue;
					}
					//Building Employee Menu Input 2: View all Building Employees
					else if (input == 2) {

						//Output if there are no current Building Employees
						if (newBuildingEmployee.empty() == true) {
							std::cout << "There are no building employees in the directory!" << std::endl << std::endl;
						}
						
						//Use range based for loop to print out all Building Employees
						else {
							std::cout << "Building Employee Directory" << std::endl;
							for (auto& buildEmp : newBuildingEmployee) {
								buildEmp.printStatus();
							}
						}
						continue;
					}
					//Building Employee Menu: If 1 or 2 was not entered, output error message and have user re-input
					else {
						while (input != 1 && input != 2 && input != 3) {
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
			printView.printOccupantNumber(guestCountRef, companyEmployeeCountRef, buildingEmployeeCountRef);
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
				std::cout << "Invalid Input. Please re-enter\n ";
				break;
			}

		}
	}
}
