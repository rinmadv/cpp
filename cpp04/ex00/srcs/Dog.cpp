#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {std::cout << "Dog default constructor get called" << std::endl;}
Dog::Dog(Dog const & src)
{
	*this = src;
	std::cout << "Dog copy constructor get called" << std::endl;
}
Dog::~Dog(){std::cout << "Dog destructor get called" << std::endl;}

Dog & Dog::operator=(Dog const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Dog assignation operator get called" << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << "Wouuaf" << std::endl;
}