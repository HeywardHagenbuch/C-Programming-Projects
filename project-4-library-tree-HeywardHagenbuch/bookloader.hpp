//Heyward Hagenbuch
//COP3530 - Project 4
//Bookloader Hpp

#ifndef BOOK_LOADER_HPP_
#define BOOK_LOADER_HPP_
#include "book.hpp"
#include <fstream>
#include <string>

class BookLoader
{
    private:
	    std::string fileName;
	    std::ifstream fileInput;
	    bool factor = false;
    
    public:
	    bool SetFileName(std::string);
	    Book* GetNextBook();
};
#endif