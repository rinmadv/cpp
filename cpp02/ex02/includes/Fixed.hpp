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
	
	bool	operator>(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	Fixed	operator+(Fixed const & rhs);
	Fixed	operator-(Fixed const & rhs);
	Fixed	operator*(Fixed const & rhs);
	Fixed	operator/(Fixed const & rhs);

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	static Fixed&	min(Fixed & a, Fixed & b);
	const static Fixed&	min(const Fixed & a, const Fixed & b);
	static Fixed&	max(Fixed & a, Fixed & b);
	const static Fixed&	max(const Fixed & a, const Fixed & b);

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int	_value;
	int const static _bits = FIXED_BITS;
};

std::ostream & operator<<( std::ostream & os, Fixed const & rhs);


#endif
