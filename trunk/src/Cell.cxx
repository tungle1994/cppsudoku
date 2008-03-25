#include "Cell.h"

using namespace std;

Sudoku::Cell::Cell(int horizontal, int vertical, int value, int maxValue) {
	this->given = false;
	this->horizontal=horizontal;
	this->vertical=vertical;
	if(value>0) { //Given
		this->value=value;
		this->given=true;
	}
	else if(value==0) { //No given
		this->value=0;
		for(int i=1;i<=maxValue;i++) {
			this->candidates.push_back(i);
		}
	}
	else //Must stay empty
		this->value=-1;
}

Sudoku::Cell::Cell(Sudoku::Cell& cell) {
	this->horizontal = cell.getHorizontal();
	this->vertical = cell.getVertical();
	this->given = cell.isGiven();
	this->candidates = cell.getCandidates();
	if(this->candidates.size()==1)
		this->value = cell.value;
	else if(this->candidates.size()==0)
		this->value = -1;
	else
		this->value = 0;
}
vector<int> Sudoku::Cell::getCandidates(){
	vector<int> foobar;
	for(int i=0;i<(int)(this->candidates).size();i++) {
		foobar.push_back(this->candidates.at(i));
	}
	return foobar;
}
int Sudoku::Cell::getHorizontal() {
	return this->horizontal;
}
int Sudoku::Cell::getVertical() {
	return this->vertical;
}
bool Sudoku::Cell::isGiven() {
	return given;
}

void Sudoku::Cell::addGroup(Sudoku::Group& group) {
	this->groups.push_back(group);
}
std::vector<Sudoku::Group> Sudoku::Cell::getGroups() {
	return this->groups;
}