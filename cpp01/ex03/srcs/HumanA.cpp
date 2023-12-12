#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon){}

void HumanA::attack()const
{
	std::string const& weapon = this->weapon.getType();
	std::cout << this->name << " attacks with their " << weapon << std::endl;
}