#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor called for MateriaSource" << std::endl;
	for (int i = 0; i < INVENTORYSIZE; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor get called" << std::endl;
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource affectation operator get called" << std::endl;
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* src)
{
	if (!src)
		return;
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = src;
			std::cout << "Materia " << src->getType() << " learned" << std::endl;
			return;
		}
	}
	std::cout << "No storage left,  " << src->getType() << " deleted" << std::endl;
	delete (src);
	src = NULL;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			AMateria *newClone = this->_inventory[i]->clone();
			std::cout << "Materia " << type << " learned" << std::endl;
			return (newClone);
		}
	}
	std::cout << type << " not found, nothing has been cloned" << std::endl;
	return (NULL);
}