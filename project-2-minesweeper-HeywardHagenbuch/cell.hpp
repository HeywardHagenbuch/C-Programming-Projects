#ifndef CELL_HPP
#define CELL_HPP
#include <string>
#include <sstream>
class Cell
{
	private:
		bool mine;
		bool flag;
		bool clicked;
		int mineCount;

	public:
		Cell();
		Cell(bool);
		bool IsMine();
		bool IsFlag();
		void ToggleFlag();
		bool Click();
		bool IsClicked();
		void SetAdjacentMineCount(int mineCount);
		int GetAdjacentMineCount();

		friend std::ostream& operator<<(std::ostream& os, const Cell& c);

		static std::string NO_ADJACENT_MINES;
        static std::string FLAG;
		static std::string MINE;
};
#endif
