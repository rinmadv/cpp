#include "../includes/Class0.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Class0::Class0() : _type("Basic Class0") {std::cout << "Class0 default constructor get called" << std::endl;}
Class0::Class0(std::string type) : _type(type) {std::cout << "Class0 constructor get called with type " << type << std::endl;}
Class0::Class0(Class0 const & src)
{
	*this = src;
	std::cout << "Class0 copy constructor get called" << std::endl;
}
Class0::~Class0(){std::cout << "Class0 destructor get called" << std::endl;}

Class0 & Class0::operator=(Class0 const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Class0 assignation operator get called" << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const & Class0::getType() const
{
	return(this->_type);
}

void Class0::setType(const std::string& type)
{
	this->_type = type;
}

/*********** MEMBER FUNCTION ***********/


