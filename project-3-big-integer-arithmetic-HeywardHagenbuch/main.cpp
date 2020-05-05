//Heyward Hagenbuch
//November 16, 2019
//COP3530 Project 3

#include "expression_reader.hpp"
#include <iostream>
#include <string>
using namespace std;

//Constructs an expression reader which takes in a file
int main()
{
	ExpressionReader c;
	c.ReadExpressions("expressions.txt");
	cout << c.PrintAll();
}
