#ifndef UI_HPP
#define UI_HPP
#include <string>
#include <sstream>
#include <iostream>
#include "gameboard.hpp"

class UI
{
	private:
		Gameboard b;
		bool gameOver;
		bool gameWon;
		bool validFileName;
		bool validMove;
		std::string fileName;
	
	public:
		UI();
		bool IsGameOver();
		bool SetFileName(std::string);
		bool IsValidFile();
		bool Move(char choice, int row, int col);
		void Delete();
		std::string GetPrompt();
		std::string ShowAll();	
};
#endif
