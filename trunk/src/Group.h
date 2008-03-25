#ifndef SUDOKU_GROUP
#define SUDOKU_GROUP

#include <vector>
#include "Cell.h"

class Cell;

namespace Sudoku {
	class Group {
	public:
		Group(std::vector<Cell> cells);
		std::vector<Cell> getCells();
		void addOverlapper(Group group);
		std::vector<Group> getOverlappers();
	private:
		std::vector<Cell> cells;
		std::vector<Group> overlap;
	};
}
#endif