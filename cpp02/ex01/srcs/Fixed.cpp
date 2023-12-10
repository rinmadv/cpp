#include "../includes/Fixed.hpp"

float static _floatBits = (float)(1 << FIXED_BITS);

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _value(src._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const val) : _value(val << FIXED_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val) : _value((int)roundf(_floatBits * val))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return (this->_value / _floatBits);
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_bits);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n" << std::endl;
	this->_value = raw;
}

std::ostream & operator<<( std::ostream & os, Fixed const & rhs)
{
	os << rhs.toFloat();
	return (os);
}