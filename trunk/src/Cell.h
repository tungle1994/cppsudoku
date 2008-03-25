#ifndef SUDOKU_CELL
#define SUDOKU_CELL

#include <vector>
#include "Group.h"

class Group;

namespace Sudoku {
	class Cell {
	public:
		Cell(int horizontal, int vertical, int value, int maxValue);
		Cell(Cell& cell);
		std::vector<int> getCandidates();
		int getHorizontal();
		int getVertical();
		bool isGiven();
		int getValue();
		void addGroup(Group& group);
		std::vector<Group> getGroups();
	private:
		int horizontal;
		int vertical;
		int value;
		std::vector<int> candidates;
		bool given;
		std::vector<Group> groups;
	};
}
#endif