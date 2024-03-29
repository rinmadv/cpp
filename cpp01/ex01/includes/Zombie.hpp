#ifndef DEF_ZOMBIE
#define DEF_ZOMBIE

#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce(void);
		void setName(std::string const & name);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
