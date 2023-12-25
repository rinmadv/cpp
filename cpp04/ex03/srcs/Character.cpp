#include "../includes/Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Default constructor called for character :" << name << std::endl;
	for (int i = 0; i < INVENTORYSIZE; i++)
		this->_inventory[i] = NULL;
}
Character::Character(Character const & src)
{
	std::cout << "Character copy constructor get called" << std::endl;
	*this = src;
}
Character & Character::operator=(Character const & rhs)
{
	std::cout << "Character affectation operator get called" << std::endl;
	this->_name = rhs._name;
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		delete this->_inventory[i];
		if (this->_inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character(){std::cout << "Character destructor called" << std::endl;}

/*********** GETTER ***********/

std::string const & Character::getName()const
{
	return (this->_name);
}

/*********** MEMBER FUNCTION ***********/

void Character::equip(AMateria* m)
{
	//je dois verifier si elles sont uniques ?
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (!this->_inventory[i])
		{
			std::cout << this->_name << " equiped with " << m->getType() << std::endl;
			this->_inventory[i] = m;
			return;
		}
	}
	//mettre m au floor
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORYSIZE && this->_inventory[idx])
	{
		std::cout << this->_name << " removed " << this->_inventory[idx]->getType() << " from equipment" << std::endl;
		// mettre au floor
		this->_inventory[idx] = NULL;
		return;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORYSIZE && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
