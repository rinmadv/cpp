#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {std::cout << "Cat default constructor get called" << std::endl;}
Cat::Cat(Cat const & src)
{
	*this = src;
	std::cout << "Cat copy constructor get called" << std::endl;
}
Cat::~Cat(){std::cout << "Cat destructor get called" << std::endl;}

Cat & Cat::operator=(Cat const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Cat assignation operator get called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type <<  ": \"Meowwwwwwwww\"" << std::endl;
}
