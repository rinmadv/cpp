#ifndef DEF_DIAMONDTRAP
#define DEF_DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define DIAMONDTRAP 3

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap();

		DiamondTrap & operator=(DiamondTrap const & rhs);
		
	private:

};


#endif