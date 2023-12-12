#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name, DIAMONDTRAP) {std::cout << "Diamond Trap constructor get called for " << name << std::endl;}
DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	*this = src;
	std::cout << "Diamond trap copy constructor get called" << std::endl;
}

DiamondTrap::~DiamondTrap(){std::cout << "Diamond trap destructor get called" << std::endl;};

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Diamond trap assignation operator get called" << std::endl;
	this->_attackDamage = rhs._attackDamage;
	this->_energy = rhs._energy;
	this->_hit = rhs._hit;
	this->_name = rhs._name;
	return (*this);
}
