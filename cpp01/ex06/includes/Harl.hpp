#ifndef DEF_HARL
#define DEF_HARL

#include <iostream>

#define DEBUG "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n"
#define INFO "[INFO]\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n"
#define WARNING "[WARNING]\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month.\n"
#define ERROR "[ERROR]\nThis is unacceptable ! I want to speak to the manager now."

class Harl
{
	public:
		Harl();
		void	complain(std::string level); //creer des pointeurs sur fonctions

	private:
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
		typedef void (Harl::*func)(void);
		static std::string	levels[];
};

#endif
