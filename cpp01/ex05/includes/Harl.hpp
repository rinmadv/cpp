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

enum Level
{
	Debug,
	Info,
	Warning, 
	Error,
};

class Harl
{
	public:
		Harl();
		void	complain(std::string level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
