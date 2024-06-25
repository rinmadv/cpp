#include "../includes/A.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

A::A() : Base(){
	if (DEBUG)
		std::cout << "Class A created" << std::endl;
}
A::~A(){}
