#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include "cell.hpp"
#include <fstream>
#include <string>
#include <iostream>

class Gameboard{

	private:
		Cell** board;

	public:
		Gameboard();
		Gameboard(std::string fileName);		
		bool GetFlag(int row, int col); 
		void ToggleFlag(int row, int col); 
		bool Click(int row, int col); 
		bool Clicked(int row, int col); 
		bool MultiClick(int row, int col); 
		bool Winner();
		bool GetMine(int, int); 
		void SetMineCount();
		void Delete();
		std::string GetPos(int, int); //Get Position
};
#endif
