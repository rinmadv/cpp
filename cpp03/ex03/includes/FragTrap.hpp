#ifndef DEF_FRAGTRAP
#define DEF_FRAGTRAP

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include "ClapTrap.hpp"

#define SCAVTRAP 1
#define FRAGTRAP 2

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap & operator=(FragTrap const & rhs);
		
		void	highFivesGuys(void);
		
	private:

};


#endif