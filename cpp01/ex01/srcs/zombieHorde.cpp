#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;

	if (N < 0)
	{
		std::cerr << "N cannot be negative value" << std::endl;
		return NULL;
	}
	try
	{
		horde = new Zombie[N];
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}



	
	
