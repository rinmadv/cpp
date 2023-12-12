#ifndef DEF_CLAPTRAP
#define DEF_CLAPTRAP

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int type);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int	getAttackDamageval();

	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attackDamage;
};

#endif
