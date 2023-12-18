#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main()
{
	ClapTrap David("David");
	ClapTrap Goliath("Goliath");
	ScavTrap Getta("Getta");
	FragTrap Fred("Fred");

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
	for (int i = 0; i <= 100; i++)
	{
		Fred.attack("Goliath");
		if (Fred.getAttackWorked() == true)
		{
			Goliath.takeDamage(Fred.getAttackDamageval());
			Goliath.beRepaired(Fred.getAttackDamageval());
		}
	}
	Fred.highFivesGuys();
	Getta.guardGate();
	return 0;
}
