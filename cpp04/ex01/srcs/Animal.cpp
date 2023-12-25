#include "../includes/Animal.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Animal::Animal() : _type("Basic Animal") {std::cout << "Animal default constructor get called" << std::endl;}
Animal::Animal(std::string type) : _type(type) {std::cout << "Animal constructor get called with type " << type << std::endl;}
Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Animal copy constructor get called" << std::endl;
}
Animal::~Animal(){std::cout << "Animal destructor get called" << std::endl;}

Animal & Animal::operator=(Animal const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Animal assignation operator get called" << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const & Animal::getType() const
{
	return(this->_type);
}

/*********** MEMBER FUNCTION ***********/

void Animal::makeSound() const
{
	std::cout << this->_type <<  ": \"?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿\"" << std::endl;

}
