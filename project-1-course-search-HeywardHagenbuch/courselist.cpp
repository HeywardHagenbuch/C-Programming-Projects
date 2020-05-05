//Author: Heyward Hagenbuch
//COP3530 Project 1

#include "courselist.hpp"
#include <fstream>
#include <sstream>

using namespace std;

//Storing information from text file into vec1
CourseList::CourseList(string textFile)
{
    ifstream inputFile;
    inputFile.open(textFile);
    string str = "";

        while(getline(inputFile, str))
        {
            vec1.push_back(str);
        }
    
    inputFile.close();

    string str2 = "";
    ostringstream printedCourse;

 //Creates a vector of courses, vec2   
    for (int i = 0; i < vec1.size(); i++)
    {
        Course c2 = Course(vec1.at(i));
        vec2.push_back(c2);
        printedCourse << vec2.at(i);
        str2 = "ID " + to_string(i) +": " + printedCourse.str() + '\n';
        courseId.push_back(str2);
        printedCourse.str("");
    }
}
//Enrollment checks through the enrolled course vector to determine if classes are already enrolled
bool CourseList::Enroll(int id)
{
if ((id < 0) || (id > courseId.size()))
{
    return false;
}

    string s2 = "";
    int b = 0;
    bool boolEnrolled = false; 
    ostringstream printedCourse;
  
        for(int i = 0; i < enrolledCourses.size(); i++)
        {
            if (enrollCourseId.at(i).substr(3, 5) == courseId.at(id).substr(3, 5))
            {
                boolEnrolled = true;
                break;
            }
        }
//if not, adds the course to the enrolledCourses vector        
        if(!boolEnrolled)
        {
            if (vec2.at(id).Enroll())
            {
                enrolledCourses.push_back(vec2.at(id));
        
                    for (int i = 0; i < courseId.size(); i++)
                    {
                        string str3 = courseId.at(i).substr(3, 5);
                        int a = stoi(str3);
                            if (a == id)
                            {
                                b = a;
                                break;
                            }
                    }
            }
            else
            {
                return false;
            }
            
        for(int i = 0; i < enrolledCourses.size(); i ++)
        {  
            if (enrolledCourses.at(i).getCourseNumber() == vec2.at(id).getCourseNumber())
            {
                printedCourse << enrolledCourses.at(i);
            }   
        } 

        s2 = "ID " + to_string(b) +": " + printedCourse.str() + '\n';
        enrollCourseId.push_back(s2);
        
        return true;
        }

    return false;  
}

//Loops through enrolledCourseId vector and lists the courses
string CourseList::GetMyCourses()
{
    string s2 = "";
    
    if (enrollCourseId.size() == 0)
    {
        return "You are not enrolled in any courses\n";
    }

    for (int i = 0; i < enrollCourseId.size(); i++)
    {
        s2 = s2 + enrollCourseId.at(i);
    }

return s2;
}

string CourseList::GetAllCourses()
{
    string str1 = "";

    for(int i = 0; i < courseId.size(); i++)
    {
       str1 = str1 + courseId.at(i);
    }
   
return str1;
}

string CourseList::InstructorSearch(string iName)
{
    string s1 = "";
        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec2.at(i).getInstructor().MatchesInstructorSearch(iName))
            {
                s1 = s1 + courseId.at(i);
            }        
        }
    return s1;
}

string CourseList::PrefixSearch(string prefix)
{
    string s1= "";
        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec2.at(i).getCoursePrefix() == prefix)
            {
                s1 = s1 + courseId.at(i);
            }
        }

    return s1;
}