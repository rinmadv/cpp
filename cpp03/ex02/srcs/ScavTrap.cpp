#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, SCAVTRAP) {std::cout << "Scav Trap constructor get called for " << name << std::endl;}
ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	std::cout << "Scav trap copy constructor get called" << std::endl;
}

ScavTrap::~ScavTrap(){std::cout << "Scav trap destructor get called" << std::endl;};

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Scav trap assignation operator get called" << std::endl;
	this->_attackDamage = rhs._attackDamage;
	this->_energy = rhs._energy;
	this->_hit = rhs._hit;
	this->_name = rhs._name;
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "Scav trap "<< this->_name << " is now in Gate keeper mode" << std::endl;
}
