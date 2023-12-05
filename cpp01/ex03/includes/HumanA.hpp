#ifndef DEF_HUMANA
#define DEF_HUMANA

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack()const;

	private:
		std::string	name;
		Weapon*		weapon;
};

#endif
