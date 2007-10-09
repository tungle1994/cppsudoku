#include <algorithm>
#include "SudokuGrid.h"
#include "HelperFunctions.h"

using namespace std;
Sudoku::SudokuGrid::SudokuGrid(int maximumNumber, std::vector<int>& list, \
							   int maxWidth) throw(std::out_of_range) {
		Sudoku::SudokuGrid::squaresAddable = true;
		Sudoku::SudokuGrid::width = maxWidth;
		if(maximumNumber<=0) {
				throw std::out_of_range("maximumNumber <= 0");
		}
		Sudoku::SudokuGrid::maxNumber = maximumNumber;
		int height = ((int) list.size())/width;
		for(int i=0;i<height;i++) {
			vector<vector<int> > newLine;
			for(int j=0;j<width;j++) {
				vector<int> item;
				if(list.at(i*width+j)==0) {
					for(int k=1;k<=maximumNumber;k++) {
						item.push_back(k);
					}
				}
				else if(list.at(i*width+j)>0) {
					item.push_back(list.at(i*width+j));
					vector<int> givensLocation;
					givensLocation.push_back(i); //height
					givensLocation.push_back(j); //width
					givens.push_back(givensLocation);
				}
				newLine.push_back(item);
			}
			gridContainer.push_back(newLine);
		}
		//Now push the last line:
		int lastLineContent = (int) list.size() - height*width;
		if(lastLineContent > 0) {
			vector<vector<int> > lastLine;
			for(int i=0;i<lastLineContent;i++) {
				vector<int> item;
				if(list.at(height*width+i)==0) {
					for(int k=1;k<=maximumNumber;k++) {
						item.push_back(k);
					}
				}
				else if(list.at(height*width+i)>0) {
					item.push_back(list.at(height*width+i));
					vector<int> givensLocation;
					givensLocation.push_back(height); //height
					givensLocation.push_back(i); //width
					givens.push_back(givensLocation);
				}
				lastLine.push_back(item);
			}
			gridContainer.push_back(lastLine);
		}
		std::sort(Sudoku::SudokuGrid::givens.begin(), \
		Sudoku::SudokuGrid::givens.end(), \
		Sudoku::givenCompare);
}

int Sudoku::SudokuGrid::addGiven(int vertical, int horizontal, int value) {
	/*if(horizontal>=width) {
		throw std::out_of_range("horizontal>=sudoku-width");
	}
	//Eerst door lijst met givens lopen, en kijken of die er al in zit
	int height = (int) gridContainer.size();
	if(height == 0) {
		height = horizontal+1;
	}
	else {

	}
	return 0;*/
	std::cout << "addGiven: STUB" << std::endl;
	return 0;
}

int Sudoku::SudokuGrid::addSquare(int vertical, int horizontal) {
	std::cout << "addSquare: STUB" << std::endl;
	return 0;
}

int Sudoku::SudokuGrid::addGroup(std::vector<std::vector<int> >& group) {
	std::cout << "addGroup: STUB" << std::endl;
	return 0;
}

int Sudoku::SudokuGrid::closeSquaresAccess() {
	Sudoku::SudokuGrid::squaresAddable = false;
	return 0;
}

bool Sudoku::SudokuGrid::isGiven(int vertical, int horizontal) {
	cout << "STUB" << endl;
	return true;
}

int Sudoku::SudokuGrid::getValue(int vertical, int horizontal) \
throw(std::out_of_range) {
	if(vertical<0 || horizontal<0 \
	|| vertical >= (int) Sudoku::SudokuGrid::gridContainer.size() \
	|| horizontal >= (int) Sudoku::SudokuGrid::gridContainer.at(0).size()) {
		throw std::out_of_range("vertical or horizontal out of range");
	}
	cout << "STUB" << endl;
	return 0;
}
