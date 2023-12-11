#include "../includes/ClapTrap.hpp"
#include <iostream>
#include <string>

int	main()
{
	ClapTrap David("David");
	ClapTrap Goliath("Goliath");

	David.attack("Goliath");
	Goliath.takeDamage(David.getAttackDamageval());
	Goliath.beRepaired(1000);
	Goliath.beRepaired(2);
	return 0;
}
