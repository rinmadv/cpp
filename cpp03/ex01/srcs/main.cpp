#include "../includes/ScavTrap.hpp"

int	main()
{
	ClapTrap David("David");
	ClapTrap Goliath("Goliath");
	ScavTrap Getta("Getta");

	David.attack("Goliath");
	if (David.getAttackWorked() == true)
		Goliath.takeDamage(David.getAttackDamageval());
	Goliath.beRepaired(1000);
	Goliath.beRepaired(2);
	Getta.attack("David");
	if (Getta.getAttackWorked() == true)
		David.takeDamage(Getta.getAttackDamageval());
	David.beRepaired(UINT_MAX);
	for (int i = 0; i <= 50; i++)
		David.beRepaired(1);
	Getta.guardGate();
	return 0;
}
