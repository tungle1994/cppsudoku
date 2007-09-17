/*
 * SudokuGrid.cxx
 * Copyright (C) Mathias De Maré 2007 <mathias.demare@gmail.com>
 * 
 * SudokuGrid.cxx is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License, not any later version.
 * 
 * SudokuGrid.cxx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with SudokuGrid.cxx.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

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
		int height = (list.size())/width;
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
		int lastLineContent = list.size() - height*width;
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

int addGiven(int vertical, int horizontal) {
	
}
