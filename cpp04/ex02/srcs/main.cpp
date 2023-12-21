#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "******** TESTS WITH VIRTUAL ********" << std::endl << std::endl;
	// const Animal* animal = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type j : " << j->getType() << " " << std::endl;
	std::cout << "Type i : " << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;
	delete (j);
	delete (i);
}
