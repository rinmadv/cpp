#include "../includes/Zombie.hpp"

Zombie::Zombie(){std::cout << "Noname: created" << std::endl;}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " deleted" << std::endl;
}

void Zombie::setName(std::string const & name)
{
	this->name = name;
}


void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}