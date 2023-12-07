#include "../includes/Harl.hpp"

Harl::Harl()
{
	this->functions[0] = &Harl::debug;
	this->functions[1] = &Harl::info;
	this->functions[2] = &Harl::warning; 
	this->functions[3] = &Harl::error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING"; 
	this->levels[3] = "ERROR";
}

void	Harl::complain(std::string level)
{
	int g;

	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
			g = i;
		
	}

	switch (4)
	{
	case 0:
		this->*functions[i]();
		break;
	case 1:
		g = 1;
		break;
	default:
		break;
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
