#include "Group.h"

using namespace std;

Sudoku::Group::Group(std::vector<Sudoku::Cell> cells) {
	for(int i=0;i<(int)cells.size();i++)
		this->cells.push_back(cells.at(i));
}
std::vector<Sudoku::Cell> Sudoku::Group::getCells() {
	return this->cells;
}
void Sudoku::Group::addOverlapper(Sudoku::Group group) {
	this->overlap.push_back(group);
}
std::vector<Sudoku::Group> Sudoku::Group::getOverlappers() {
	return this->overlap;
}