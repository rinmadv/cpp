#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, FRAGTRAP) {std::cout << "Frag Trap constructor get called for " << name << std::endl;}
FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	std::cout << "Frag trap copy constructor get called" << std::endl;
}

FragTrap::~FragTrap(){std::cout << "Frag trap destructor get called" << std::endl;};

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Frag trap assignation operator get called" << std::endl;
	this->_attackDamage = rhs._attackDamage;
	this->_energy = rhs._energy;
	this->_hit = rhs._hit;
	this->_name = rhs._name;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Scav trap "<< this->_name << " is requesting positive feedback		Fred.attack("Goliath");
" << std::endl;
}
