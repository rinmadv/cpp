#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(): _hit(10), _energy(10), _attackDamage(0) {std::cout << "Clap trap default constructor get called" << std::endl;}
ClapTrap::ClapTrap(std::string name):  _name(name), _hit(10), _energy(10), _attackDamage(0) {std::cout << "Clap trap constructor get called for " << name << std::endl;}
ClapTrap::ClapTrap(std::string name, unsigned int type):  _name(name)
{
	if (type == 1)
	{
		_hit = 100;
		_energy = 50;
		_attackDamage = 20;
		std::cout << "Clap trap constructor get called for " << name << std::endl;
	}
}
ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	std::cout << "Clap trap copy constructor get called" << std::endl;
}
ClapTrap::~ClapTrap(){std::cout << "Clap trap destructor get called" << std::endl;}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Clap trap assignation operator get called" << std::endl;
	this->_attackDamage = rhs._attackDamage;
	this->_energy = rhs._energy;
	this->_hit = rhs._hit;
	this->_name = rhs._name;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy == 0 || this->_hit == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesnt have enough energy points to attack " << target << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " gets attacked and loses " << amount << " hit points!" << std::endl;
	if (amount >= this->_hit)
		this->_hit = 0;
	else
		this->_hit = this->_hit - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesnt have enough energy points to get repaired " << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " gets repaired " << amount << " hit points!" << ", and loses 1 energy point" << std::endl;
	this->_energy--;
	if ((unsigned long int)(this->_hit + amount) > UINT_MAX)
		this->_hit = UINT_MAX;
	else
		this->_hit += amount;
}

unsigned int	ClapTrap::getAttackDamageval()
{
	return (this->_attackDamage);
}
