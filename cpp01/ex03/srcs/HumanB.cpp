#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack()const
{
	if (!this->weapon)
		return ;
	std::string const& weapon = this->weapon->getType();
	std::cout << this->name << " attacks with their " << weapon << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
