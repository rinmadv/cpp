#include "../includes/C.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

C::C() : Base(){
	if (DEBUG)
		std::cout << "Class C created" << std::endl;
}
C::~C(){}
