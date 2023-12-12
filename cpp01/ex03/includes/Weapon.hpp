#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <iostream>

class Weapon
{
	public:
	Weapon();
	Weapon(std::string type);
	std::string const& getType() const;
	void setType(std::string type);

	private:
	std::string type;
};

#endif
