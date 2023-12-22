#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor called for MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor get called" << std::endl;
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource affectation operator get called" << std::endl;
	if (!rhs._inventory)
		this->_inventory = NULL;
	else
	{
		for (int i = 0; i < INVENTORYSIZE; i++)
		{
			// si pas empty, le delete puis
			this->_inventory[i] = rhs._inventory[i]; // non on va utiliser les setters et getters pour copier le contenu et pas juste les adresses
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){std::cout << "MateriaSource destructor called" << std::endl;}

void MateriaSource::learnMateria(AMateria*)
{
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		this->_inventory[i] = rhs._inventory[i]; // non on va utiliser les setters et getters pour copier le contenu et pas juste les adresses
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (this->_inventory[i]->getType() == type)
		{
			AMateria *newClone = this->_inventory[i]->clone();
			return (newClone);
		}
	}
	return (NULL);
}