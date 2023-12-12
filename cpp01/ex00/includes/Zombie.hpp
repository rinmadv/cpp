#ifndef DEF_ZOMBIE
#define DEF_ZOMBIE

#include <iostream>

class Zombie
{
	public:
		void announce(void);
		Zombie(std::string name);
		~Zombie();

	private:
		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

#endif
