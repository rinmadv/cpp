#ifndef DEF_FRAGTRAP
#define DEF_FRAGTRAP

#include "ClapTrap.hpp"

#define FRAGTRAP 2

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap & operator=(FragTrap const & rhs);
		
		void	highFivesGuys(void) const;
		
	private:

};


#endif