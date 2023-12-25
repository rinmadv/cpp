#include "../includes/Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Default constructor called for character :" << name << std::endl;
	for (int i = 0; i < INVENTORYSIZE; i++)
		this->_inventory[i] = NULL;
	this->collector = NULL;
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

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	garbage *tmp;
	while (this->collector)
	{
		tmp = this->collector->next;
		delete this->collector->Item;
		delete this->collector;
		this->collector = tmp;
	}
	this->collector = NULL;

	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/*********** GETTER ***********/

std::string const & Character::getName()const
{
	return (this->_name);
}

/*********** MEMBER FUNCTION ***********/

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < INVENTORYSIZE; i++)
	{
		if (this->_inventory[i] && this->_inventory[i] == m)
		{
			std::cout << this->_name << " already equipied with this " << m->getType();
			return;
		}
		if (!this->_inventory[i])
		{
			std::cout << this->_name << " equiped with " << m->getType() << std::endl;
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << this->_name << " 's inventory is full" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORYSIZE && this->_inventory[idx])
	{
		std::cout << this->_name << " removed " << this->_inventory[idx]->getType() << " from equipment" << std::endl;
		if (!this->collector)
		{
			this->collector = new garbage();
			this->collector->Item = this->_inventory[idx];
			this->collector->next = NULL;
		}
		else
		{
			garbage *tmp = this->collector;
			while (this->collector->next)
				tmp = tmp->next;
			tmp = new garbage();
			tmp->Item = this->_inventory[idx];
			tmp->next = NULL;
		}
		this->_inventory[idx] = NULL;
		return;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORYSIZE && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
