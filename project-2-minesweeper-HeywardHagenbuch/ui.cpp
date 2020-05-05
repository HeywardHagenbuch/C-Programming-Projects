#include "ui.hpp"
using namespace std;

//Constructor
UI::UI()
{
	gameOver = false;
	gameWon = false;
	validMove = true;
	fileName = "";
	validFileName = false;
}

//UI prompts
string UI::GetPrompt()
{
	string prompt = "";
	if(validFileName)
	{
		if(validMove)
		{
			prompt = prompt +
			"      0   1   2   3 \n"
			"    +---+---+---+---+\n"
			"  0 | "+b.GetPos(0,0)+" | "+b.GetPos(1,0)+" | "+b.GetPos(2,0)+" | "+b.GetPos(3,0)+" |\n"
			"    +---+---+---+---+\n"
			"  1 | "+b.GetPos(0,1)+" | "+b.GetPos(1,1)+" | "+b.GetPos(2,1)+" | "+b.GetPos(3,1)+" |\n"
			"    +---+---+---+---+\n"
			"  2 | "+b.GetPos(0,2)+" | "+b.GetPos(1,2)+" | "+b.GetPos(2,2)+" | "+b.GetPos(3,2)+" |\n"
			"    +---+---+---+---+\n"
			"  3 | "+b.GetPos(0,3)+" | "+b.GetPos(1,3)+" | "+b.GetPos(2,3)+" | "+b.GetPos(3,3)+" |\n"
			"    +---+---+---+---+\n";
			if(!gameOver)
			{
				prompt = prompt + "Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: ";
			}
			else
			{
				if(gameWon)
				{
					prompt = prompt + "Game Over!";
					//Delete();
				}
				else
				{
					prompt = "";
					prompt = prompt + ShowAll();
					//Delete();
				}
			}
		}
		else{
			prompt = prompt + "Invalid move. Please enter your next move: ";
		}	
	}
	else{
		prompt = prompt + "Please enter a file name with the minefield information: ";
	}
return prompt;
}

//This method displays the whole board if player loses the game
string UI::ShowAll()
{
	string show, fill = "";
	int row;
	show = show + "      0   1   2   3 \n";
	for(row = 0; row < 4; row ++)
	{
		show = show + "    +---+---+---+---+\n";
		show = show + "  " + to_string(row);
		for(int j = 0; j < 4; j++)
		{
			if(b.GetMine(j, row))
			{
				fill = "*";
			}
			else
			{
				fill = " ";
			}
			show = show + " | "+fill;
		}
		show = show + " |\n";
	}
	show = show + "    +---+---+---+---+\nGame Over!";
return show;
}


bool UI::IsGameOver()
{
	if(gameOver)
	{
		return true;
	}
	return false;
}

//Move Function
bool UI::Move(char choice, int col, int row)
{
	bool condition = false;

	if(choice == 'F' || choice == 'f') //Player chooses flag
	{
		if((col >= 0) && (row >= 0) && (row < 4) && (col < 4) && (!b.Clicked(row, col)))
		{
            b.ToggleFlag(row, col);
			condition = true;
        }
        else
		{
        	condition = false;
        }
	}
	else if(choice == 'C' || choice == 'c') //Player chooses to click
	{
		if((col >= 0) && (row >= 0) && (row < 4) && (col < 4))
		{
			if(b.GetFlag(row, col))
			{
				validMove = false;
				condition = false;
			}
			else
			{
				condition = b.MultiClick(row, col);
				validMove = condition;
				if(b.GetMine(row, col))
				{
					gameOver = true;
				}
				else if(b.Winner())
				{
					gameWon = true;
					gameOver = true;
				}
			}
		}
		else
		{
			condition = false;
			validMove = false;
		}
	}
	else
	{
		condition = false;
		validMove = false;
	}
	return condition;
}

//Validity of file name is checked with the ".in" extension
bool UI::SetFileName(string fileName)
{
    if(fileName.find(".in") != string::npos)
	{
		validFileName = true;
		b = Gameboard(fileName);
		return true;
	}
	return false;
}

bool UI::IsValidFile()
{
	return validFileName;
}

void UI::Delete()
{
	b.Delete();
}