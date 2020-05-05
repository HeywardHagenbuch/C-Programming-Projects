//Author: Heyward Hagenbuch
//COP3530 Project 1

#ifndef COURSELIST_HPP
#define COURSELIST_HPP

#include <vector>
#include <iostream>
#include <string>
#include "course.hpp"

class CourseList
{
    private:
        std::vector<std::string> vec1;
        std::vector<std::string> courseId;
        std::vector<std::string> enrollCourseId;
        std::vector<Course> vec2;
        std::vector<Course> enrolledCourses;
       
    public:
        CourseList(std::string textFile);
        bool Enroll(int id);
        std::string GetMyCourses();
        std::string GetAllCourses();
        std::string InstructorSearch(std::string iName);
        std::string PrefixSearch(std::string prefix);
    };

#endif