#include <iostream>
#include "SudokuGrid.h"
#include <vector>

int main()
{
	std::cout << "Hello world!" << std::endl;
	std::vector<std::vector<int> > a;
	{
		std::vector<int> b;
		a.push_back(b);
	}
	a.at(0).push_back(5);
	std::cout << a.at(0).at(0) << std::endl;
	
	return 0;
}
