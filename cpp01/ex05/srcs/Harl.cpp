#include "../includes/Harl.hpp"

std::string Harl::levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl()
{
}

void	Harl::complain(std::string level)
{
	static void		(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
			return ((this->*functions[i])());
	}
	std::cerr << "Invalid complain level" << std::endl;
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
