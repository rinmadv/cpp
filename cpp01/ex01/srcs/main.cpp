#include "../includes/../includes/Zombie.hpp"

#define HORDE_SIZE -10

int	main(int argc, char **argv)
{
	Zombie* horde;

	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return(1);
	}
	horde = zombieHorde(HORDE_SIZE, argv[1]);
	if (!horde)
		return 1;
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
