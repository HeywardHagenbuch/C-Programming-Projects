//Author: Heyward Hagenbuch
//COP3530 Project 1

#ifndef COURSE_HPP
#define COURSE_HPP

#include "instructor.hpp"
#include "classtime.hpp"

#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>

class Course
{
	private:
		std::string coursePrefix;
		int courseNumber;
		int seatsAvailable;
		int max_seats;

		Instructor instructor;
		ClassTime classtime;

	public:	
		Course();
		Course(std::string courseDetails);
		bool MatchesCourseNumberSearch(int courseNumber);
		bool MatchesPrefixSearch(std::string coursePrefix);
		bool Enroll();
		friend std::ostream& operator<<(std::ostream& os, const Course& c);
		std::string getCoursePrefix();
		int getCourseNumber();
		int getSeatsAvailable();
		Instructor getInstructor();		
};

#endif
