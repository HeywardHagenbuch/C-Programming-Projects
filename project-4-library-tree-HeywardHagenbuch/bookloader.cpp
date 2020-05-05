//Heyward Hagenbuch
//COP3530 - Project 4
//Bookloader cpp

#include "bookloader.hpp"
using namespace std;

bool BookLoader::SetFileName(string fileName)
{
	if (fileName.find(".txt") == string::npos) 
    {
		return false;
	}
    else
    {
        this->fileName = fileName;
	    return true;
    }	
}

Book* BookLoader::GetNextBook()
{
    if (factor == true)
    {
        return nullptr;
    }
    string title, author, subject, format, publisher, next = "";
    int number_available;
    
    if (!fileInput.is_open())//Open the file if it's not open 
    {
		fileInput.open(fileName.c_str());
	}

    for (int i = 0; i < 6; i++) 
    {
		if (std::getline(fileInput, next)) 
        {
			if (i == 0) 
            {
				title = next;
			}
			else if (i == 1) 
            {
				author = next;	
			}
			else if (i == 2) 
            {
                subject = next;
			}
			else if (i == 3) 
            {
                format = next;
			}
			else if (i == 4) 
            {
				publisher = next;
			}
			else if (i == 5) 
            {
				number_available = stoi(next);
			}
		}

		else 
        {
            factor = true;
			fileInput.close();
			return nullptr;
		}
	}
	Book* book = new Book(title, author, subject, format, publisher, number_available);
	return book;
}
