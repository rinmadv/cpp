#include "../includes/Dog.hpp"

Dog::Dog(){std::cout << "Dog default constructor get called" << std::endl;}
Dog::Dog(std::string type) : _type(type) {std::cout << "Dog constructor get called with type " << type << std::endl;}
Dog::Dog(Dog const & src)
{
	*this = src;
	std::cout << "Dog copy constructor get called" << std::endl;
}
Dog::~Dog(){std::cout << "Dog destructor get called" << std::endl;}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignation operator get called" << std::endl;
	return (*this);
}