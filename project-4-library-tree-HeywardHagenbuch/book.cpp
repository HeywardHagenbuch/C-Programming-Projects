//Heyward Hagenbuch
//COP3530 - Project 4
//Book Cpp

#include "book.hpp"
using namespace std;

Book::Book()
{
}

Book::Book(string title, string author, string subject, string format, string publisher, int number_available)
{
    this->title = title;
    this->author = author;
    this->subject = subject;
    this->format = format;
    this->publisher = publisher;
    this->number_available = number_available;
}

string Book::GetTitle()
{
    return this->title;
}
  
string Book::GetAuthor()
{
    return this->author;
}

string Book::GetSubject()
{
    return this->subject;
}

string Book::GetFormat()
{
    return this->format;
}

string Book::GetPublisher()
{
    return this->publisher;
}

int Book::GetNumAvailable()
{
    return this->number_available;
}

bool Book::Checkout()
{
	bool condition = false;
	if (number_available > 0) 
    {
		this->number_available--;
		condition = true;
	}
	else 
    {
		condition = false;
	}
	return condition;
}

bool Book::Checkin()
{
    this->number_available++;
    return true;
}

bool operator ==(const Book &a, const Book &b)
{
   return (a.title == b.title);
}

bool operator < (const Book &a, const Book &c)
{
    return (a.title < c.title);   
}