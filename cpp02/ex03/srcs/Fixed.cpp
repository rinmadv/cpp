#include "../includes/Fixed.hpp"

float static _floatBits = (float)(1 << FIXED_BITS);

/***************** CONSTRUCTEURS / DESTRUCTEURS ******************/

Fixed::Fixed(void) : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _value(src._value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const val) : _value(val << FIXED_BITS)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val) : _value((int)roundf(_floatBits * val))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}




/***************** OPERATORS ******************/

	/***************** ASSIGNATION ******************/

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

	/***************** COMPARISION ******************/

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_value > rhs._value ? true : false);
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_value >= rhs._value ? true : false);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_value < rhs._value ? true : false);
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_value <= rhs._value ? true : false);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_value == rhs._value ? true : false);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_value != rhs._value ? true : false);
}

	/***************** ARITHMETIC ******************/

Fixed	Fixed::operator+(Fixed const & rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

	/******* INCREMENTATION / DECREMENTATION ********/

Fixed	Fixed::operator++()
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;
	return (temp);
}

Fixed	Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value--;
	return (temp);
}

/***************** GETTERS/SETTERS ******************/

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n" << std::endl;
	this->_value = raw;
}

/***************** MIN & MAX ******************/

Fixed&	Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed & a, const Fixed & b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed & a, const Fixed & b)
{
	return (a > b ? a : b);
}


/***************** CONVERSIONS ******************/

float	Fixed::toFloat( void ) const
{
	return (this->_value / _floatBits);
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_bits);
}


/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, Fixed const & rhs)
{
	os << rhs.toFloat();
	return (os);
}