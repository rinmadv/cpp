#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Basic wrong animal") {std::cout << "WrongAnimal default constructor get called" << std::endl;}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {std::cout << "WrongAnimal constructor get called with type " << type << std::endl;}
WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
	std::cout << "WrongAnimal copy constructor get called" << std::endl;
}
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor get called" << std::endl;}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongAnimal assignation operator get called" << std::endl;
	return (*this);
}

std::string const & WrongAnimal::getType() const
{
	return(this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->_type <<  ": \"?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿\"" << std::endl;
}
