#include "ui.hpp"
#include "cell.hpp"
#include "gameboard.hpp"
#include <iostream>

using namespace std;

int main()
{
	UI ui;
	string userInput, row, col;
	char choice; //C click, F flag

	do
	{
		cout << ui.GetPrompt();
		if(ui.IsGameOver())
		{
			break;
		}

		if(!ui.IsValidFile())
		{
			userInput = "";
			cin >> userInput;
			ui.SetFileName(userInput);
		}

		else
		{
			cin >> choice;
			cin >> row;
			cin >> col;
			ui.Move(choice, stoi(row), stoi(col));
		}
	}
	while(true);
	return 0;
}
