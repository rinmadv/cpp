#include "../includes/../includes/Zombie.hpp"
#include <limits.h>

#define HORDE_SIZE 5

int	main(int argc, char **argv)
{
	Zombie* horde;
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return(1);
	}
	try
	{
		horde = zombieHorde(INT_MAX, argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	for (int i = 0; i < INT_MAX; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
