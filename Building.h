#pragma once
#include <string>
#include <vector>


class Building {


public:
	
	static std::vector<int> numberOfFloorsLeft;
	
	Building(int numFloors);
	Building();
	~Building();
	
	void openFloorsLeft();
	bool validateCompanyFloors(int startFloor, int endFloor);

private:
	int numberOfFloors{ 0 };
	const int maxNumberOfCompanies{ numberOfFloors - 1 };
};

