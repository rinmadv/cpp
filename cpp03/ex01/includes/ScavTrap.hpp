#ifndef DEF_SCAVTRAP
#define DEF_SCAVTRAP

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include "ClapTrap.hpp"

#define SCAVTRAP 1

class ScavTrap : public ClapTrap
{
	public:
		// ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & rhs);
		
		void	guardGate();

	private:

};


#endif