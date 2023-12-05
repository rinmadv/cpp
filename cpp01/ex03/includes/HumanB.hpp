#ifndef DEF_HUMANB
#define DEF_HUMANB

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack()const;
		void	setWeapon(Weapon& weapon);

	private:
		std::string	name;
		Weapon*		weapon;
};

#endif
