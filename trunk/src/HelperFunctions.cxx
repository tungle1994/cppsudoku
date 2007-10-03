#include "HelperFunctions.h"

bool givenCompare(std::vector<int>& a, std::vector<int>& b) {
	if(((int) a.size() != 2) || ((int) b.size() != 2)) {
		std::cout << "Throw some exception! STUB" << std::endl;
		return false;
	}
	else {
		if(a.at(0) != b.at(0)) {
			return (a.at(0) < b.at(0));
		}
		else
			return (a.at(1) < b.at(1));
	}
}