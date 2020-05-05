//Heyward Hagenbuch
//COP3530 - Project 4
//Book Hpp

#ifndef BOOK_HPP_
#define BOOK_HPP_
#include <string>

class Book
{
    private:
        std::string title, author, subject, format, publisher;
        int number_available;

    public:
        Book();
        Book (std::string title, std::string author, std::string subject, std::string format, std::string publisher, int number_available);
        std::string GetTitle();
        std::string GetAuthor();
	    std::string GetSubject();
	    std::string GetFormat();
	    std::string GetPublisher();
	    int GetNumAvailable();
        bool Checkout();
        bool Checkin();
        friend bool operator == (const Book &a, const Book &b);
        friend bool operator < (const Book &a, const Book &c);
};
#endif