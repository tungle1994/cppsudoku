/*
 * SudokuGrid.h
 * Copyright (C) Mathias De Maré 2007 <mathias.demare@gmail.com>
 * 
 * SudokuGrid.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License, not any later version.
 * 
 * SudokuGrid.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with SudokuGrid.h.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#ifndef H_SUDOGRID
#define H_SUDOGRID

#include <vector>
#include <stdexcept>
#include <iostream>


namespace Sudoku {
class SudokuGrid {
	public:
		/**
		* Constructor throws out_of_range exception when maximumNumber <= 0.
		*/
		SudokuGrid(int maximumNumber) throw(std::out_of_range) {
			if(maximumNumber<=0) {
				throw std::out_of_range("maximumNumber <= 0");
			}
			maxNumber = maximumNumber;
			squaresAddable = true;
		}
		/**
		* The list contains (starting top left and going to the right,
		* then down) either '0' or a given.
		*/
		SudokuGrid(int maxNumber, std::vector<int>& list, int width) \
		throw(std::out_of_range);
		~SudokuGrid() {
			std::cout << "SudokuGrid destructor call" << std::endl;
		}
		int addGiven(int vertical, int horizontal);
		int addSquare(int vertical, int horizontal);
		/**
		* Makes it impossible to add more squares by calling addGiven(),
		* addSquare() or addGroup().
		*/
		int closeSquaresAccess();
		/// Returns true if the square is given, false otherwise.
		bool isGiven(int vertical, int horizontal);
		/**
		* Returns a value if there's only 1, zero otherwise.
		*/
		int getValue(int vertical, int horizontal);
		int setValue(int vertical, int horizontal, int value);
		std::vector<int>& getValues(int vertical, int horizontal);
		int removeValue(int vertical, int horizontal, int value);
		int addGroup(std::vector<std::vector<int> >& group);
		std::vector<std::vector<std::vector<int> > >& getGroups(int vertical, \
															  int horizontal);
	private:
		int maxNumber; //Numbers go from 1 to maxNumber.
		bool squaresAddable; //Is it still allowed to add a given?
		/*
		* Grid containing a vector of ints (the possible values)
		* If the square is not an element of the sudoku, it contains '-1'.
		*/
		std::vector<std::vector<std::vector<int> > > gridContainer;
		//Vector that contains pairs of ints (horizontal and vertical)
		std::vector<std::vector<int> > givens;
		//Vector containing a group of pairs of ints
		std::vector<std::vector<std::vector<int> > > groupsList;
};

}
#endif
