#include "../includes/MateriaSource.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	std::cout << "___________________________" << std::endl;
// 	me->equip(tmp);
// 	std::cout << "___________________________" << std::endl;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("zebre");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	tmp = src->createMateria("cure");
// 	bob->equip(tmp);
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int	main()
{
	Character	joe("Joe");
	Character	marvin("Marvin");
	AMateria	*snowspell = new Ice;
	AMateria	*curespell = new Cure;

	joe.equip(snowspell);
	joe.use(0, marvin);
	joe.use(1, marvin);
	joe.equip(curespell);
	joe.use(1, marvin);
	marvin.use(0, joe);
	marvin.unequip(0);
	joe.use(0, marvin);
	joe.use(1, marvin);
	joe.unequip(0);
	joe.unequip(1);
	joe = marvin;
	for (size_t i(0); i < INVENTORYSIZE; ++i)
	{
		joe.unequip(i);
		marvin.unequip(i);
	}
	// delete snowspell;
	// delete curespell;
	return (0);
}