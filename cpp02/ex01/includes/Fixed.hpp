#ifndef DEF_FIXED
#define DEF_FIXED

#include <iostream>
#include <cmath>

#define FIXED_BITS 8

class Fixed
{

public:
	Fixed(void);
	Fixed(int const val);
	Fixed(float const val);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);
	
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
