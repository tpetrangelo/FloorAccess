//Pre-processor directives
#pragma once
#include <string>
#include <vector>

//Interface for Building class
class Building {


public:
	
	//static vector that indicates the number of floors left for occupation in a given building
	static std::vector<int> numberOfFloorsLeft;
	
	//Building constructor
	Building(int numFloors);

	//Default Building constructor, intializes number of floors to 2
	Building();

	//Building destructor
	~Building();
	
	//Returns a string that states the number of floors open for a Company to choose from
	void openFloorsLeft();
	
	//Checks to ensure a user inputs a valid selection of floors for their new Company
	bool validateCompanyFloors(int startFloor, int endFloor);

private:

	//Int variable containing the number of floors in a building
	int numberOfFloors{ 0 };

	//A const int containing the maximum number of companies, each company must be at least one floor, we use
	//numberOfFloors - 1 because the lobby (floor 1) cannot be occupied by a company
	const int maxNumberOfCompanies{ numberOfFloors - 1 };
};

