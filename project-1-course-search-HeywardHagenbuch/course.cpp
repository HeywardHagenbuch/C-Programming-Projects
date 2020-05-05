//Author: Heyward Hagenbuch
//COP3530 Project 1

#include "course.hpp"
using namespace std;

Course::Course()
{
	this->instructor = Instructor("Bar,Foo");
	this->classtime = ClassTime("1,2,3", "1:00-1:15");
	coursePrefix = "CS";
	courseNumber = 1;
	seatsAvailable = 0;
	max_seats = 0;
}

Course::Course(string courseDetails)
//Parsed out input to correlate with the correct variables
{
	string name = "";
	string days = "";
	string time = "";

	stringstream courseStream(courseDetails);
	courseStream >> coursePrefix >> courseNumber;
	courseStream >> name;

	courseStream >> max_seats >> seatsAvailable;
	courseStream >> days;
	courseStream >> time;

	this->instructor = Instructor(name);
	this->classtime = ClassTime(days, time);	
}
//Enrollment based on available seats
bool Course::Enroll()
{
	if (seatsAvailable != 0)
	{
		seatsAvailable--; 
		return true;  
	}
	return false;
}

bool Course::MatchesCourseNumberSearch(int courseNumber)
{
	if (this->courseNumber == courseNumber)
	{
		return true;
	}
	else
		return false;
}	

bool Course::MatchesPrefixSearch(string coursePrefix)
{	
	if (this->coursePrefix == coursePrefix)
	{
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& os, const Course& c)
{
		os << c.coursePrefix << " "  << c.courseNumber <<'\n';
  		os << '\t' << c.seatsAvailable;
	       	if(c.seatsAvailable ==1)
		{
			os << " seat ";		
		}
		else
		{
			os << " seats ";
		}
		os << "remaining of ";
	       	os << c.max_seats << "." << '\n';
    		os << '\t' << "Instructor: " << c.instructor << "." << '\n';
       		os << '\t' << c.classtime;
	return os;
}

//Testing methods
string Course::getCoursePrefix()
{
	return coursePrefix;
}

int Course::getCourseNumber()
{
	return courseNumber;
}

int Course::getSeatsAvailable()
{
	return seatsAvailable;
}

Instructor Course::getInstructor()
{
	return this->instructor;
}



