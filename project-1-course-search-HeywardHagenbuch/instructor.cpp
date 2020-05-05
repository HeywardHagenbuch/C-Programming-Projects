//Author: Heyward Hagenbuch
//COP3530 Project 1

#include "instructor.hpp"
using namespace std;

Instructor::Instructor()
{
	firstName = "Crazy";
	lastName = "George";
}

Instructor::Instructor(string nameData)
{
	lastName = nameData.substr(0, nameData.find(","));
	firstName = nameData.substr(nameData.find(",") + 1, nameData.length());	
}

bool Instructor::MatchesInstructorSearch(string nameData)
{
	if (nameData == firstName || nameData == lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const Instructor& i)
{	
	os << i.firstName << " " << i.lastName;
	return os;
}

