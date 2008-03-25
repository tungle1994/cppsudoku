#include <algorithm>
#include "SudokuGrid.h"
#include "HelperFunctions.h"

using namespace std;
/**
* Constructor for a SudokuGrid.
* list contains the values:
*  - a positive number if there's a given
*  - 0 if the number is unknown
*  - -1 for an empty spot
*/
Sudoku::SudokuGrid::SudokuGrid(int maximumNumber, std::vector<int>& list, \
							   int maxWidth) throw(std::out_of_range) {
		Sudoku::SudokuGrid::squaresAddable = true;
		Sudoku::SudokuGrid::width = maxWidth;
		if(maximumNumber<=0) {
				throw std::out_of_range("maximumNumber <= 0");
		}
		Sudoku::SudokuGrid::maxNumber = maximumNumber;
		int height = ((int) list.size())/width;
		for(int i=0;i<height;i++) { //All the lines
			vector<vector<int> > newLine;
			for(int j=0;j<width;j++) { //All the squares
				vector<int> item; //One square
				if(list.at(i*width+j)==0) { //No given
					for(int k=1;k<=maximumNumber;k++) {
						item.push_back(k);
					}
				}
				else if(list.at(i*width+j)>0) { //Given
					item.push_back(list.at(i*width+j));
					vector<int> givensLocation;
					givensLocation.push_back(i); //height
					givensLocation.push_back(j); //width
					givens.push_back(givensLocation);
				}
				else { //Empty spot
					item.push_back(-1);
				}
				newLine.push_back(item);
			}
			gridContainer.push_back(newLine);
		}
		//Sort the givens
		std::sort(Sudoku::SudokuGrid::givens.begin(), \
		Sudoku::SudokuGrid::givens.end(), \
		Sudoku::givenCompare);
}

int Sudoku::SudokuGrid::addGiven(int vertical, int horizontal, int value) {
	std::cout << "addGiven: STUB" << std::endl;
	return 0;
}

int Sudoku::SudokuGrid::addSquare(int vertical, int horizontal) {
	std::cout << "addSquare: STUB" << std::endl;
	return 0;
}

int Sudoku::SudokuGrid::addGroup(std::vector<std::vector<int> >& group) {
	//std::cout << "addGroup: STUB" << std::endl;
	if(Sudoku::SudokuGrid::squaresAddable) {
		Sudoku::SudokuGrid::groupsList.push_back(group);
		return 0;
	}
	else return 1;
}

int Sudoku::SudokuGrid::closeSquaresAccess() {
	Sudoku::SudokuGrid::squaresAddable = false;
	return 0;
}

bool Sudoku::SudokuGrid::isGiven(int vertical, int horizontal) {
	std::cout << "Partial stub: no error checking!" << std::endl;
	std::binary_search(Sudoku::SudokuGrid::givens.begin(), \
		Sudoku::SudokuGrid::givens.end(), \
		Sudoku::SudokuGrid::gridContainer.at(vertical).at(horizontal), \
		Sudoku::givenEquals);
	return true;
}

int Sudoku::SudokuGrid::getValue(int vertical, int horizontal) \
throw(std::out_of_range) {
	if(vertical<0 || horizontal<0 \
	|| vertical >= (int) Sudoku::SudokuGrid::gridContainer.size() \
	|| horizontal >= (int) Sudoku::SudokuGrid::gridContainer.at(0).size()) {
		throw std::out_of_range("vertical or horizontal out of range");
	}
	else if(Sudoku::SudokuGrid::isGiven(vertical, horizontal)) {
		return Sudoku::SudokuGrid::gridContainer.at(vertical).at(horizontal).at(0);
	}
	else {
		return -1;
	}
}
