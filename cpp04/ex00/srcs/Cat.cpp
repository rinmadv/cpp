#include "../includes/Cat.hpp"

Cat::Cat(){std::cout << "Cat default constructor get called" << std::endl;}
Cat::Cat(std::string type) : _type(type) {std::cout << "Cat constructor get called with type " << type << std::endl;}
Cat::Cat(Cat const & src)
{
	*this = src;
	std::cout << "Cat copy constructor get called" << std::endl;
}
Cat::~Cat(){std::cout << "Cat destructor get called" << std::endl;}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignation operator get called" << std::endl;
	return (*this);
}