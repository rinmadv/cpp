#ifndef DEF_FIXED
#define DEF_FIXED

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include <cmath>

#define FIXED_BITS 8

class Fixed
{

public:
	Fixed(void); //constructeur par défaut
	Fixed(int const val); //constructeur parametric int
	Fixed(float const val); //constructeur parametric int
	Fixed(Fixed const & src); //constructeur de copie
	~Fixed(void); //constructeur de copie

	Fixed &	operator=(Fixed const & rhs);//Surcharge de l'opérateur d'affectation
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int	_value;
	int const static _bits = FIXED_BITS;
};

std::ostream & operator<<( std::ostream & os, Fixed const & rhs);


#endif
