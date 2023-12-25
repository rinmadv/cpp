#include "../includes/WrongCat.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

WrongCat::WrongCat() : WrongAnimal("WrongCat") {std::cout << "WrongCat default constructor get called" << std::endl;}
WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
	std::cout << "WrongCat copy constructor get called" << std::endl;
}
WrongCat::~WrongCat(){std::cout << "WrongCat destructor get called" << std::endl;}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongCat assignation operator get called" << std::endl;
	return (*this);
}

/*********** MEMBER FUNCTION ***********/

void WrongCat::makeSound() const
{
	std::cout << this->_type <<  ": \"Wrong miaou\"" << std::endl;
}
