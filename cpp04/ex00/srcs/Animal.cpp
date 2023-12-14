#include "../includes/Animal.hpp"

Animal::Animal(){std::cout << "Animal default constructor get called" << std::endl;}
Animal::Animal(std::string type) : _type(type) {std::cout << "Animal constructor get called with type " << type << std::endl;}
Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Animal copy constructor get called" << std::endl;
}
Animal::~Animal(){std::cout << "Animal destructor get called" << std::endl;}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignation operator get called" << std::endl;
	return (*this);
}