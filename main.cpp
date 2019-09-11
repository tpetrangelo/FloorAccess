//////////////////////////
// Tom Petrangelo 
// CIS 554 - OOP in C++ Final Project
// Building and Floor Access
// Due Date: 9/17/19
//////////////////////////

//Pre-processor directives
#include <iostream>
#include "Menu.h"

int main() {

	//Creation of Menu object
	//Menu is the main output of this program
	Menu buildingMenu;	

	//userStartMenu asks user to input a number that represents the number of floors in a building
	buildingMenu.userStartMenu();

	//userMenu is the main driver for user-input operations
	buildingMenu.userMenu();

return 0;
}