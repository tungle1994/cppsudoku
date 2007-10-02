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
		SudokuGrid(int maximumNumber, int maxWidth) throw(std::out_of_range) {
			if(maximumNumber<=0) {
				throw std::out_of_range("maximumNumber <= 0");
			}
			maxNumber = maximumNumber;
			width = maxWidth;
			squaresAddable = true;
		}
		/**
		* The list contains (starting top left and going to the right,
		* then down) either '0' or a given.
		*/
		SudokuGrid(int maxNumber, std::vector<int>& list, int maxWidth) \
		throw(std::out_of_range);
		~SudokuGrid() {
			std::cout << "SudokuGrid destructor call" << std::endl;
		}
		int addGiven(int vertical, int horizontal, int value);
		int addSquare(int vertical, int horizontal);
		int addGroup(std::vector<std::vector<int> >& group);
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

		std::vector<std::vector<std::vector<int> > >& getGroups(int vertical, \
															  int horizontal);

		friend bool givenCompare();
	private:
		int maxNumber; //Numbers go from 1 to maxNumber.
		int width;
		bool squaresAddable; //Is it still allowed to add a given?
		/**
		* Grid containing a vector of ints (the possible values)
		* If the square is not an element of the sudoku, it contains '-1'.
		* gridContainer.at(i) is the i-th row
		* gridContainer.at(i).at(j) is the i-th row and the j-th column
		* gridContainer.at(i).at(j).at(k) is the i-th row, the j-th column and the k-th possible value
		*/
		std::vector<std::vector<std::vector<int> > > gridContainer;
		//Vector that contains pairs of ints (horizontal and vertical)
		std::vector<std::vector<int> > givens;
		//Vector containing a group of pairs of ints
		std::vector<std::vector<std::vector<int> > > groupsList;
};

}
#endif
