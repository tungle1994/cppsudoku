/*
 * main.cc
 * Copyright (C) Mathias De Maré 2007 <mathias.demare@gmail.com>
 * 
 * main.cc is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License, not any later version.
 * 
 * main.cc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with main.cc.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

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
