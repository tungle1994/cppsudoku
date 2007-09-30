#include <vector>
#include "SudokuGrid.h"

using namespace std;
Sudoku::SudokuGrid::SudokuGrid(int maximumNumber, std::vector<int>& list, \
							   int width) throw(std::out_of_range) {
		Sudoku::SudokuGrid::squaresAddable = true;
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
}

int Sudoku::SudokuGrid::addGiven(int vertical, int horizontal, int value) {
	//Eerst door lijst met givens lopen, en kijken of die er al in zit

	int height = (int) gridContainer.size();
	if(height == 0) {

		this(maxNumber, 
	}
	else {

	}
	return 0;
}
