#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main()
{
	Animal	animal;
	std::cout << "Type : " << animal.getType() << std::endl;
	std::cout << std::endl;

	Cat		cat;
	std::cout << "Type : " << cat.getType() << std::endl;
	std::cout << std::endl;
	
	Dog		dog;
	std::cout << "Type : " << dog.getType() << std::endl;
	std::cout << std::endl;

	return 0;
}
