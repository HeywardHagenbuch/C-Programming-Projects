//Heyward Hagenbuch
//COP3530 - Project 4
//Main Cpp

#include <iostream>
#include <limits>
#include "node.hpp"
#include "tree.hpp"
#include "bookloader.hpp"
#include "book.hpp"
using namespace std;
int main() 
{
	int selection = -1;
	Node<Book>* node;
    Book* book ;
    Tree<Book> tree;
	BookLoader load;
    string look = "";
	load.SetFileName("book_data.txt");

    do
    {
		book = load.GetNextBook();
		if(book != nullptr)
        {
			tree.Insert(book);
		}
	} while (book != nullptr);

    cout << "----------------------------------------------" << endl;
	cout << "\t-=|\tTHE MAIN MENU\t|=- "<< endl;
    do
    {
		cout << "----------------------------------------------" << endl;
        cout << "\n Please Select From the Following Options \n\n";
		cout << "  1  Find a Book by Title in the Library System" << endl;
		cout << "  2  List of Books in the Library System (Lists Titles)" << endl;
        cout << "  3  List of Books in the Library System (Lists Details)" << endl;
        cout << "  4  Display Availability of Book for Loan (By Title)" << endl;
        cout << "  5  Reserve a Book" << endl;
        cout << "  6  Return a Loaned Book" << endl;
        cout << "  0  Exit the Program" << endl;
		cin >> selection;
		
        if (cin.fail()) 
        {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			selection = -1;
		}

		switch (selection) 
        {
		    case 1: //Find a book by title
                cout << "Please enter the title of the book you are searching for:  " <<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, look);
                node = tree.Search(look);
                if (node != nullptr) 
                {
                    book = node->GetValue();
                    cout << "\n";
                    cout << "Title: " << book->GetTitle() << endl;
                    cout << "Author: " << book->GetAuthor() << endl;
                    cout << "Subject: " << book->GetSubject() << endl;
                    cout << "Publisher: " << book->GetPublisher() << endl;
                    cout << book->GetNumAvailable() << "  available copies left" << endl;
                    cout << "Format: " << book->GetFormat() << endl;
		        }
                else
                {
                    cout << "Sorry, that book is not available in this library.";
                }
                break;
                    
            case 2: //List Book Titles
                cout << tree.Traverse(false);
                break;
                
            case 3: //List Book Details
                cout << tree.Traverse(true);
                break;

            case 4: //Display book availability
                cout << "Please enter the title of the book you are searching for: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, look);
                node = tree.Search(look);  
                if (node != nullptr) 
                {
                    book = node->GetValue();
                    cout << "Book Title: " << book->GetTitle() << endl;
                    cout << "Available Copies: " << book->GetNumAvailable() << endl;
                }
                else
                {
                    cout << "Sorry, that book is not available in this library." <<endl;
                }
                break;
                
            case 5: //Checkout a book
                cout << "Please enter the title of the book you would like to reserve: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, look);
                node = tree.Search(look);
            
                if (node != nullptr)
                {
                    book = node->GetValue();
                    if (book->Checkout()) 
                    {
                        cout << "\n";
                        cout << "You have reserved the book: " << book->GetTitle() << endl;
                        cout << book->GetNumAvailable() << " available copies are currently in the library" << endl;
                    }
                    else 
                    {
                        cout << "Sorry, all of the copies are currently rented out.";
                    }
                }
                else 
                {
                    cout << "Sorry, that book is not available in this library." <<endl;
                }
                break;
            
            case 6: //Check in a book
                cout << "Please enter the title of the book you would like to return: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, look);
                node = tree.Search(look);
            
                if (node != nullptr) 
                {
                    book = node->GetValue();
                    if (book->Checkin()) 
                    {
                        cout << "\n";
                        cout << "Thank you for returning: " << book->GetTitle() << endl;
                        cout << book->GetNumAvailable() << " available copies are currently in the library" << endl;
                    }
                }
                
                else 
                {
                    cout << "Sorry, that title is not valid." << endl;
                }
                break;

            case 0: //exit
					cout<< "\n-------Goodbye, have a nice day!-------\n" << endl;
					exit(0);
					break;

            default:
                break;
        }
    } 
    while (true);
    return 0;
}
