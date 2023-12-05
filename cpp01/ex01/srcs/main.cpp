#include "../includes/../includes/Zombie.hpp"
#include <iostream>
#include <string>
#define HORDE_SIZE 5

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return(EXIT_FAILURE);
	}
	Zombie* horde = zombieHorde(HORDE_SIZE, argv[1]);
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	delete [] horde;
	return (EXIT_SUCCESS);
}
