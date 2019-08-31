#pragma once
#include <string>
#include <vector>


class Building {


public:
	
	Building(int numFloors);
	Building();
	~Building();
	
	void giveAccess();
	void removeAccess();

	bool hasAccess();

	void openFloorsLeft();

	void companyFloor(int start, int end);

private:
	int numberOfFloors;
	static std::vector<int> numberOfFloorsLeft;

};

