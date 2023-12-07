#include "../includes/Harl.hpp"

std::string Harl::levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl()
{
}

void	Harl::complain(std::string level)
{
	int j = 4;
	static void		(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
		{
			j = i;
			break;
		}
	}
	switch (j)
	{
	case 0:
		(this->*functions[0])();
	case 1:
		(this->*functions[1])();
	case 2:
		(this->*functions[2])();
	case 3:
		(this->*functions[3])();
		break;
	default:
		std::cerr << "Invalid complain level" << std::endl;
	}
}

void	Harl::debug( void )
{
	std::cout << DEBUG << std::endl;
}

void	Harl::info( void )
{
	std::cout <<  INFO << std::endl;

}

void	Harl::warning( void )
{
	std::cout <<  WARNING << std::endl;

}

void	Harl::error( void )
{
	std::cout <<  ERROR << std::endl;
}
