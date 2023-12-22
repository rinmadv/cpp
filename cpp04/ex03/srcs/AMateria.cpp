#include "../includes/AMateria.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

AMateria::AMateria() {std::cout << "AMateria default constructor get called with no type " << std::endl;}
AMateria::AMateria(std::string const & type) : _type(type) {std::cout << "AMateria default constructor get called for type " << this->_type << std::endl;}
AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria copy constructor get called" << std::endl;
	*this = src;
}
AMateria::~AMateria() {std::cout << "AMateria destructor get called" << std::endl;}
AMateria & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignation operator get called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

/*********** GETTER ***********/

std::string const & AMateria::getType() const {return(this->_type);}

/*********** MEMBER FUNCTION ***********/

void AMateria::use(ICharacter& target) {(void) target;}
