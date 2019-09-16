//Pre-processor directives
#pragma once
#include <string>
#include <iostream>
//Interface for class Occupant (Base Class)
class Occupant 
{
public:

	//Constructor for Occupant class
	Occupant(std::string fName, std::string lName);
	
	//Default constructor for Occupant class
	Occupant();

	//Destrcutor for occupant class
	~Occupant();


	//Sets the first name of the Occupant object
	void setFirstName(std::string fName);

	//Returns the first name of the occupant object
	std::string getFirstName() const;

	//Sets the last name of the Occupant object
	void setLastName(std::string lName);

	//Returns the last name of the Occupant object
	std::string getLastName() const;

	//virtual functions used for derived classes
	virtual void printStatus() = 0;
	


private:

	//Private data members that represents an Occupant's first name and last name
	std::string firstName;
	std::string lastName;
};

