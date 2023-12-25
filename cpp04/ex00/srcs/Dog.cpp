#include "../includes/Dog.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Dog::Dog() : Animal("Dog") {std::cout << "Dog default constructor get called" << std::endl;}
Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor get called" << std::endl;
	*this = src;
}
Dog::~Dog(){std::cout << "Dog destructor get called" << std::endl;}

Dog & Dog::operator=(Dog const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Dog assignation operator get called" << std::endl;
	return (*this);
}

/*********** MEMBER FUNCTION ***********/

void	Dog::makeSound(void) const
{
	std::cout << this->_type <<  ": \"Wouuaf\"" << std::endl;
}