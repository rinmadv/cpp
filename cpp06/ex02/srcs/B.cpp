#include "../includes/B.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

B::B() : Base(){
	if (DEBUG)
		std::cout << "Class B created" << std::endl;
}
B::~B(){}
