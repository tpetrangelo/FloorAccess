#include "Occupant.h"

Occupant::Occupant(std::string fName, std::string lName, std::string status) : firstName{fName} , lastName{lName} , occupantStatus{status}
{

}

Occupant::Occupant()
{
}

void Occupant::setFirstName(std::string fName)
{
	firstName = fName;
}

std::string Occupant::getFirstName() const
{
	return firstName;
}

void Occupant::setLastName(std::string lName)
{
	lastName = lName;
}

std::string Occupant::getLastName() const
{
	return lastName;
}

void Occupant::setOccupantStatus(std::string status)
{
	occupantStatus = status;
}

std::string Occupant::getOccupantStatus() const
{
	return occupantStatus;
}



