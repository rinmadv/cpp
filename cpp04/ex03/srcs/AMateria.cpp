#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	_type = type;
	std::cout << "AMateria default constructor get called for type " << this->_type << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	std::cout << "AMateria copy constructor get called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor get called" << std::endl;
}


AMateria & AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs._type;
	std::cout << "AMateria assignation operator get called" << std::endl;
	return (*this);
}


std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	return;
}
