#include "../includes/../includes/Zombie.hpp"


int	main()
{
	Zombie stack("Stack");
	stack.announce();

	Zombie* heap = newZombie("Heap");
	heap->announce();
	
	randomChump("NotAllocated");

	delete heap;
	return 0;
}
