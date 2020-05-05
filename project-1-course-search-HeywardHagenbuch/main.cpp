//Author: Heyward Hagenbuch
//COP3530 Project 1

#include <iostream>
#include <fstream>
#include <string>

#include "course.hpp"
#include "instructor.hpp"
#include "courselist.hpp"

using namespace std;

int main()
{
	string fileName = "";	
	bool a = false;
	//Checking for valid file format
	do
	{
		cout << "Input the name of the file with the course data:" << endl;
		cin >> fileName;
		
		if (fileName.find(".txt") != string::npos)
		{
			a = true;
		}
	}
	while(!a);

	CourseList cl1 = CourseList(fileName);
	cout << cl1.GetAllCourses() << endl;
	cout << "\n";

	//Main menu for user input
	char selection;
	while(true)
	{
		cout << "----------------------------------------------" << endl;
		cout << "-=|\tMAIN MENU\t|=-" << endl;
		cout << "To search for a course, press 'S'." << endl;
		cout << "To Enroll, press 'E'." << endl;
		cout << "To view your current enrollments, press 'V'." << endl;
		cout << "To exit this application, press 'Q'." << endl;
		cout << "Enter a selection: ";
	
		cin >> selection;
		cout << endl;
	
			switch(selection) 
			{
				case 'S':
				case 's':
					cout << "Enter 'P' to search by course prefix, or 'N' to search by instructor name: " << endl;
					cout << "'N' is the default: " << endl;
					char choice;
					cin >> choice;

						switch(choice)
						{
							case 'P':
							case 'p':
							{
								cout << "\tEnter the course prefix to search for: " << endl;
								string prefix;
								cin >> prefix;
									if (" " == cl1.PrefixSearch(prefix))
									{
										cout <<"Invalid Prefix" << endl;
									}
									else
									{
										cout << cl1.PrefixSearch(prefix);
									}
									break;						
							}

							default:
								cout << "Enter the first or last name of the instructor to search for: " << endl;
								Instructor i;
								string name;
								cin >> name;
									if (" " == cl1.InstructorSearch(name))
									{
										cout <<"Invalid Instructor Name" << endl;
									}
									else
									{
										cout << cl1.InstructorSearch(name);
									}						
						}
					break;

				case 'E':
				case 'e':
					cout << "Enter the ID of the couse you want to enroll in: " << endl;
					int id;
					cin >> id;
						if (!cl1.Enroll(id))
						{
							cout << "You have entered an invalid course ID, or no seats remain." << endl;
						}
						else
						{
							cout << "Enrolled in " << id << endl;
						}
					break;

				case 'V':
				case 'v':
					cout << cl1.GetMyCourses() << endl;
					break;

				case 'Q':
				case 'q':
					cout<< "Goodbye, have a nice day!" << endl;
					exit(0);
					break;
				
				default:
					cout << "Invalid selection" << endl;
					break;
					
			}			
	}
return 0;
}