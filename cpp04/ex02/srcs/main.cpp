#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

#define FARMSIZE 4
#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"

// static void display_title(std::string title) {
// 	std::cout << BOLDBLUE << "--- " << title << " ---\n" << RESET;
// }

// int main() {
// 	display_title("PURE ANIMAL");
// 	// Animal* animal = new Animal();
// 	// delete animal;
// 	display_title("DEFAULT CONSTRUCTORS");
// 	Animal* animals[FARMSIZE] = {new Dog(), new Dog(), new Cat(), new Cat()};
// 	display_title("ANIMAL INFO");
// 	for (int i = 0; i < FARMSIZE; ++i) {
// 		std::cout << "i: " << i << " type: " << animals[i]->getType() << " sound: ";
// 		animals[i]->makeSound();
// 	}
// 	display_title("DEEP COPY");
// 	Dog dog1;
// 	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
// 	dog1.setIdea(0, "Qui vole un oeuf vole un boeuf.");
// 	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
// 	Dog dog2(dog1);
// 	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
// 	dog2.setIdea(0, "Pas de bras, pas de chocolat.");
// 	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
// 	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
// 	dog2 = dog1;
// 	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
// 	dog2.setIdea(0, "Le temps est l'image mobile de la realite immobile.");
// 	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
// 	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
// 	display_title("DESTRUCTORS");
// 	for (int i = 0; i < FARMSIZE; ++i)
// 		delete animals[i];
// }

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
