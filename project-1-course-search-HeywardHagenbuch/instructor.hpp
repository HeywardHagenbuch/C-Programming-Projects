//Author: Heyward Hagenbuch
//COP3530 Project 1

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

class Instructor{

	private:
		std::string firstName;
		std::string lastName;

	public:
		std::string nameData;
		Instructor();
		Instructor(std::string nameData);
		friend std::ostream& operator<<(std::ostream& os, const Instructor& i);
		bool MatchesInstructorSearch(std::string nameData);		
};

#endif
