#ifndef DEF_ZOMBIE
#define DEF_ZOMBIE

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>

class Zombie
{
	public:
		void announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
