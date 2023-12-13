#ifndef DEF_FIXED
#define DEF_FIXED

#include <iostream>

#define FIXED_BITS 8

class Fixed
{

public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int	_value;
	int const static _bits = FIXED_BITS;
};

#endif
