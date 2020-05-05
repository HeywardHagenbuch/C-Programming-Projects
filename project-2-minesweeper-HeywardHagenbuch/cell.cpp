#include "cell.hpp"
using namespace std;

string Cell::FLAG = "\u2691";
string Cell::MINE = "\u25A2";
string Cell::NO_ADJACENT_MINES = "\u2610"; 

Cell::Cell()
{
	this->mine = false;
	this->clicked = false;
	this->flag = false;
	mineCount = 0;
}

Cell::Cell(bool mine)
{
	this->mine = mine;
	this->clicked = false;
	this->flag = false;
	mineCount = 0;
}

bool Cell::IsMine()
{
	return mine;
}

bool Cell::IsFlag()
{
	return flag;
}

void Cell::ToggleFlag()
{
	if (!flag)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	
}

bool Cell::Click()
{
	if(flag)
	{
		return false;
	}
	else if(clicked)
	{
		return false;
	}	
	clicked = true;
	return true;
}

bool Cell::IsClicked()
{
	return clicked;
}

void Cell::SetAdjacentMineCount(int mineCount)
{
	this->mineCount =mineCount;
}

int Cell::GetAdjacentMineCount()
{
	return mineCount;
}

ostream& operator << (ostream& os, const Cell& c)
{
	if(c.flag)
	{
		os << Cell::FLAG;
	}

	else if(c.clicked)
	{
		if(c.mine)
		{
			os << Cell::MINE;
		}
		else if(c.mineCount == 0)
		{
			os << Cell::NO_ADJACENT_MINES;
		}
		else
		{
			os << c.mineCount;
		}
	}
	else
	{
		os << " ";
	}
	return os;
}
