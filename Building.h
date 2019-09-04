#pragma once
#include <string>
#include <vector>


class Building {


public:
	
	static std::vector<int> numberOfFloorsLeft;


	Building(int numFloors);
	Building();
	~Building();
	
	void giveAccess();
	void removeAccess();

	bool hasAccess();

	void openFloorsLeft();

	void companyFloor(int start, int end);

	void printBuildingStatus();
	void printCompanyStatus();
	void printOccupantStatus();

	bool validateCompanyFloors(int startFloor, int endFloor);

private:
	int numberOfFloors;
	const int maxNumberOfCompanies{ numberOfFloors - 1 };
};

