#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {std::cout << "Scav Trap default constructor get called" << std::endl;}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Scav Trap constructor get called for " << name << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
}
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

void	ScavTrap::guardGate() const
{
	std::cout << "Scav trap "<< this->_name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesnt have enough energy points to attack " << target << std::endl;
		this->_attackWorked = false;
	}
	else if (this->_hit == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesnt have enough hit points to attack " << target << std::endl;
		this->_attackWorked = false;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energy--;
		this->_attackWorked = true;
	}
}