#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor get called" << std::endl;
	this->_brain = new Brain();
}
Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor get called" << std::endl;
	*this = src;
	this->_brain = new Brain();
}
Cat::~Cat()
{
	std::cout << "Cat destructor get called" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignation operator get called" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain(*this->_brain);		
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type <<  ": \"Meowwwwwwwww\"" << std::endl;
}
