#include "../includes/Cat.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

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

/*********** SETTER / GETTER ***********/

std::string const & Cat::getIdea(const int id) const
{
	return (this->_brain->getIdea(id));
}

void Cat::setIdea(const int id, const std::string& idea)
{
	this->_brain->setIdea(id, idea);
}

/*********** MEMBER FUNCTION ***********/

void	Cat::makeSound(void) const
{
	std::cout << this->_type <<  ": \"Meowwwwwwwww\"" << std::endl;
}
