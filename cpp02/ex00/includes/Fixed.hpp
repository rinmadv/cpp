#ifndef DEF_FIXED
#define DEF_FIXED

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>

class Fixed
{

public:
	Fixed(void); //constructeur par défaut
	Fixed(Fixed const & src); //constructeur de copie
	~Fixed(void); //constructeur de copie

	Fixed &	operator=(Fixed const & rhs);//Surcharge de l'opérateur d'affectation
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int	_value;
	int const static _bits = 8;
};

#endif
