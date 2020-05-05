# Project 4 - Library Tree

## Project Outcomes:
The focus of this assignment is on the following learning objectives:
* Be able to identify classes and objects required from the problem description
* Be able to identify class functionality for a Binary Search Tree
* Be able to identify an incremental approach to developing the program solution by extending the capability of the Binary search tree class to application specific classes
* Be able to implement the program solution based on the identified approach
* Understand how the program solution can evolve over time
* Perform file I/O through reading of data from plaintext files using a predefined specification
* Manipulate data in a Binary Search Tree

## Preparatory Readings:
* Chapter 6 - Input and Output
* Chapter 13 - for Node background
* Chapter 17 - Trees

## Background Information:
![Xmas tree with heap of presents XKCD comic](https://imgs.xkcd.com/comics/tree.png)
### Project overview:
Tree based data structures offer the benefit of _O(logn)_ operations in common data operations over linear data structures.
Basic operations on Binary Search Trees (and other similar trees) involve creation, search, insertions and deletions.
Additional operations that can give the height of a tree, find minimum or maximum value in the tree, or print the tree nodes in one of the three common orders are often desired.
Of the three orders, in-order traversal can provide a basic sorting on a key in tree node data.

This project is meant to familiarize the students with creation of a tree based data
structure for a specific application involving a library of books.

### Project Requirements:
Your application must function as described below:
You are to implement a program for creating a library catalog that will read in and store file data as a Binary Search Tree based on a key.
For this project, you will need to utilize the concepts of Binary Search Trees and the various tree operations that have been discussed in class.
The list of requirements and constraints for the system are as follows:
1. The system must be able to:
	1. Read in data related to books (supposed to be part of a library system) from the provided text file [book_data.txt](book_data.txt).
	Every book record in the file contains the name of the book, other particulars and a number indicating number available as the last field of the record.
	See below for file format and sample data.
	Records are sequentially stored in the file.
	Any errors possible in the file reading should be handled.
	1. Create a catalog of books out of the data and print it initially as a confirmation of successful data read and to serve as a reference to the program user for successive operations
	1. Create a Binary Search Tree of book data out of the catalog data.
2. The system must be able to generate and show a menu of options to the user to:
	1. Find a book by its name in the library system.
	A book would be in the library system if the library has ever added it to its collection.
	It is quite possible that while the book might be a part of the library system, it might not be available in the library momentarily because all copies have been loaned out.
	It is also possible, that the user is specifying a book that is not a part of the library system yet.
	This situation should also be handled.
	1. Generate a list of books in the library system in alphabetically sorted out order by book name.
	This list would just contain book names, for example:
		```
		Artificial Intelligence
		Computer Networking
		Operating System Concepts
		```
	1. Generate a list of books with full details in the library system in alphabetically sorted out order by book name.
	This list should be formatted as follows:
		```
		Artificial Intelligence, by Stuart Russell
			Subject: AI & ML
			Publisher: Pearson Education
			5 Paperback copies available
		Computer Networking, by James Kurose
			Subject: Networking
			Publisher: Pearson Education
			13 Hardcover copies available
		Operating System Concepts, by Abraham Silberschatz
			Subject: OS
			Publisher: Wiley
			17 Kindle copies available
		```
	1. Report on availability of a user-specified book for loan.
		1. It is possible that all copies of the book have been loaned out.
			1. If not, the book should be reported back as available.
		1. It is also possible that the user might be trying to loan out a book that is not in the library system.
			1. This should report back to the user that the book is not carried by the library.
	1. Reserve a book.
		1. The user must indicate the book name, and if the book is a part of the library system and if at least a copy is available, the user should be allowed to loan the book.
		1. The number of copies remaining should be updated in the tree data (do not update the original input data file).
		1. Non availability or non-library system book requests should also be handled.
	1. Return a loaned book.
		1. The user would indicate the book name, and if the book is a part of the library system, the user should be allowed to return the book.
		1. The number of copies remaining should be updated in the tree data (do not update the original input data file).
		1. Non-library system book return requests should also be handled and no such books should be accepted by the system.
	1. Exit the library system when done.
	The user should be able to exit the library system.
	If this option is not selected by the user, the user should be shown the menu after every operation.

#### Input Format and Sample data
```
Book Title
Author
Subject
Book Format, e.g. Paperback, Kindle
Publisher
#copies available
Artificial Intelligence
Stuart Russell
AI & ML
Paperback
Pearson Education
5
Computer Organization
David A. Patterson
CompOrg
Paperback
Morgan Kaufmann
3
```

### Implementation Notes:
1. Create a project that is object oriented, therefore there should be several classes.
2. The input file will match the exact format given above.

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
	1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
	If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
	1. The Travis-CI build should begin automatically when you push your code to GitHub.
	2. If your program will not compile, the graders will not be responsible for trying to test it.
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
* Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
* Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
* Please review the academic honesty policy.
	* Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	* Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.
