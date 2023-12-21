#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor get called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor get called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor get called" << std::endl;
	delete this->_brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignation operator get called" << std::endl;
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type <<  ": \"Wouuaf\"" << std::endl;
}

std::string const & Dog::getIdea(const int id) const
{
	return (this->_brain->getIdea(id));
}

void Dog::setIdea(const int id, const std::string& idea)
{
	this->_brain->setIdea(id, idea);
}
