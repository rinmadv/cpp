#ifndef DEF_Character
#define DEF_Character

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[INVENTORYSIZE];

	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character();

		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
