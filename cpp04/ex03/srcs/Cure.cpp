#include "../includes/Cure.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Cure::Cure()
{
	_type = "cure";
	std::cout << "Cure default constructor get called" << std::endl;
}

Cure::Cure(Cure const & src)
{
	*this = src;
	std::cout << "Cure copy constructor get called" << std::endl;
}


Cure & Cure::operator=(Cure const & rhs)
{
	this->_type = rhs._type;
	std::cout << "Cure assignation operator get called" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor get called" << std::endl;
}

/*********** MEMBER FUNCTIONS ***********/

void Cure::use(ICharacter& target)
{  
	std::cout << "* heals " << target.getName() << "\'s wounds *"  << std::endl;
	return;
}

Cure* Cure::clone() const
{
	Cure *newClone = new Cure(*this);
	return (newClone);
}