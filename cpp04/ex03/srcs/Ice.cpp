#include "../includes/Ice.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Ice::Ice()
{
	_type = "ice";
	std::cout << "Ice default constructor get called" << std::endl;
}

Ice::Ice(Ice const & src)
{
	*this = src;
	std::cout << "Ice copy constructor get called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Ice assignation operator get called" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor get called" << std::endl;
}

/*********** MEMBER FUNCTIONS ***********/

void Ice::use(ICharacter& target)
{
	std::cout << "* shouts an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone() const
{
	Ice *newClone = new Ice(*this);
	std::cout << "Ice cloned" << std::endl;
	return (newClone);
}