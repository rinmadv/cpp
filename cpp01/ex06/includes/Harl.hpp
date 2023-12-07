#ifndef DEF_HARL
#define DEF_HARL

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>

#define DEBUG "Debug"
#define INFO "FYI"
#define WARNING "!WOUP WOUP!"
#define ERROR "Outch"

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
		void		(Harl::*functions[4])();
		typedef void (Harl::*func)(void);
		std::string	levels[4];
};

#endif
