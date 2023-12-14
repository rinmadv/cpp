#ifndef DEF_CLAPTRAP
#define DEF_CLAPTRAP

#include <iostream>
#include <limits.h>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const std::string& name, unsigned int type);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);
		
		void attack(const std::string& target);
		void takeDamage(const unsigned int amount); 
		void beRepaired(const unsigned int amount); 

		unsigned int	getAttackDamageval() const;

	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attackDamage;
};

#endif
