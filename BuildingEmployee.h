//Pre-processor directives
#pragma once
#include <string>
#include "Occupant.h"

//Interface for class BuildingEmployee, inherited by abstract clas Occupant (base)
class BuildingEmployee :  virtual public Occupant
{
public:


	//Constructor for BuildingEmployee object
	BuildingEmployee(std::string fName, std::string lName, std::string position);
	
	//Default constructor for BuildingEmployee object
	BuildingEmployee();

	//Destructor for BuildingEmployee object
	~BuildingEmployee();

	//Sets the current job title of the BuildingEmployee object
	void setPosition(std::string position);

	//Returns the current title of a BuildingEmployee object
	std::string getPosition() const;

	//Prints out information based on a specfific BuildingEmployee object
	virtual void printStatus();

	//Prints out menu options based on a specfific BuildingEmployee object
	virtual void printOccupantMenu();

private:

	//Private data members that represents a BuildingEmployee's first name, last name, and job title
	std::string firstName;
	std::string lastName;
	std::string buildingPosition;
	

};

