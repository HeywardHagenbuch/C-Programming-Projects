#include "gameboard.hpp"
using namespace std;

//Constructor creates a 4X4 2D array of Cells
Gameboard::Gameboard()
{
	board = new Cell*[4]; 
    for(int i = 0 ; i < 4; i++)
	{
        board[i] = new Cell[4];
    }
}

//This paramaterized constructor initializes the 2D array with mines from the fourXfour.in file
Gameboard::Gameboard(string fileName)
{
	ifstream inputFile;
	char info;
	board = new Cell*[4];
	for(int i = 0 ; i < 4; i++)
	{
		board[i] = new Cell[4];
	}

	inputFile.open(fileName.c_str());
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			inputFile.get(info);
			if(info == '\n')
			{
				inputFile.get(info);
			}
			if(info == ' ')
			{
				board[j][i] = Cell(false);
			}
			else{
				board[j][i] = Cell(true);
			}
		}
	}
	inputFile.close();
	
SetMineCount();
}

//Clicking Functions
bool Gameboard::Click(int row, int col)
{ 
	return board[row][col].Click();
}

bool Gameboard::Clicked(int row, int col)
{
	return board[row][col].IsClicked();
}

//Recursive method for clicking
bool Gameboard::MultiClick(int row, int col) 
{
	if(!board[row][col].IsClicked())
	{
		Click(row, col);
		if(board[row][col].GetAdjacentMineCount() == 0)
		{
			if(row > 0)//down
			{
				MultiClick(row - 1, col);
			}
			if(col > 0)//right
			{
				MultiClick(row, col - 1);
			}
			if(row < 3)//up
			{
				MultiClick(row + 1, col);
			}
			if(col < 3)//left
			{
				MultiClick(row, col + 1);
			}
			if(row > 0 && col < 3)//down left
			{
				MultiClick(row - 1, col + 1);
			}
			if(row > 0 && col > 0)//down right
			{
				MultiClick(row - 1, col - 1);
			}
			if( row < 3 && col < 3)//up left
			{
				MultiClick(row + 1, col + 1);
			}
			if(row < 3 && col > 0)//up right
			{
				MultiClick(row + 1, col - 1);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

//Flag Functions
void Gameboard::ToggleFlag(int row, int col)
{
	board[row][col].ToggleFlag();
}

bool Gameboard::GetFlag(int row, int col)
{
	return board[row][col].IsFlag();
}

//Mine Functions

bool Gameboard::GetMine(int row, int col)
{
	return board[row][col].IsMine();
}

//This function keeps track of the adjacent mines count 
void Gameboard::SetMineCount()
{ 
	for(int row = 0; row < 4; row++)
	{
		for(int col = 0; col < 4; col++)
		{
			int mines = 0;
			if((row > 0) && (GetMine(row - 1, col)))
			{
	        	mines++;
	        }
			if((col > 0) && (GetMine(row, col - 1)))
			{
				mines++;
	        }
			if((row < 3) && (GetMine(row + 1, col)))
			{
				mines++;
	        }
			if((col < 3) && (GetMine(row, col + 1)))
			{
				mines++;
	        }
			if((row > 0 && col > 0) && (GetMine(row - 1, col - 1)))
			{
				mines++;
			}
			if(( row < 3 && col < 3) && (GetMine(row + 1, col + 1)))
			{
				mines++;
			}        
	        if((row > 0 && col < 3) && (GetMine(row - 1, col + 1)))
			{
				mines++;
			}  
	        if((row < 3 && col > 0) && (GetMine(row + 1, col - 1)))
			{
				mines++;
			} 
			board[row][col].SetAdjacentMineCount(mines);
		}
	}
}

string Gameboard::GetPos(int row, int col)
{
	stringstream display;
	display << board[row][col];
	return display.str();
}

//The game is won if everything is "clicked" except for the mines
bool Gameboard::Winner()
{
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(!Clicked(i, j))
			{
				if(!GetMine(i, j))
				{
					return false;
				}
			}
		}
	}
	return true;
}

//Function for deleting the Gameboard
void Gameboard::Delete()
{
	for (int i = 0; i < 4; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}


