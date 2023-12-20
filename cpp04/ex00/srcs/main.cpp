#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "******** TESTS WITH VIRTUAL ********" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type meta : " << meta->getType() << " " << std::endl;
	std::cout << "Type j : " << j->getType() << " " << std::endl;
	std::cout << "Type i : " << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete (meta);
	delete (j);
	delete (i);

	std::cout << std::endl;
	std::cout << "******** TESTS WITHOUT VIRTUAL ********" << std::endl << std::endl;
	const WrongAnimal* beta = new WrongAnimal();
	const Animal* k = new Dog();
	const WrongAnimal* l = new WrongCat();
	const WrongCat* m = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type beta : " << beta->getType() << " " << std::endl;
	std::cout << "Type k : " << k->getType() << " " << std::endl;
	std::cout << "Type l : " << l->getType() << " " << std::endl;
	std::cout << "Type m : " << m->getType() << " " << std::endl;

	std::cout << std::endl;
	beta->makeSound();
	l->makeSound();
	k->makeSound();
	m->makeSound();

	std::cout << std::endl;
	delete (beta);
	delete (k);
	delete (l);
	delete (m);
}
