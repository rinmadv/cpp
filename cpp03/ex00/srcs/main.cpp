#include "../includes/ClapTrap.hpp"

int	main()
{
	ClapTrap David("David");
	ClapTrap Goliath("Goliath");

	David.attack("Goliath");
	if (David.getAttackWorked() == true)
		Goliath.takeDamage(David.getAttackDamageval());
	Goliath.beRepaired(1000);
	Goliath.beRepaired(2);
	for (int i = 0; i < 20; i++)
	{
		David.attack("Goliath");
		if (David.getAttackWorked() == true)
			Goliath.takeDamage(David.getAttackDamageval());
	}
	return 0;
}
