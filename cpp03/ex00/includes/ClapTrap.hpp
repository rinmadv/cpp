#ifndef DEF_CLAPTRAP
#define DEF_CLAPTRAP

#include <iostream>
#include <limits.h>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string const& name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);
		
		void attack(const std::string& target);
		void takeDamage(const unsigned int amount);
		void beRepaired(const unsigned int amount);

		unsigned int	getAttackDamageval() const;
		unsigned int	getEnergy() const;
		bool			getAttackWorked() const;

	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attackDamage;
		bool			_attackWorked;
};

#endif
