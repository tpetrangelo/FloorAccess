#include "Guest.h"

Guest::Guest(std::string fName, std::string lName, std::string status, int age) : Occupant(fName,lName, status)
{
	age = guestAge;
}

Guest::Guest()
{
}

void Guest::setAge(int age)
{
	age = guestAge;
}

int Guest::getAge()
{
	return guestAge;
}
