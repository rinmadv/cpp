#include "../includes/Point.hpp"

/***************** CONSTRUCTEURS / DESTRUCTEURS ******************/

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

/***************** GETTERS/SETTERS ******************/

Fixed	Point::getX(void) const
{
	return(this->_x);
}

Fixed	Point::getY(void) const
{
	return(this->_y);
}

	
/***************** OPERATORS ******************/

	/***************** ASSIGNATION ******************/

Point &	Point::operator=(Point const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->_x) = rhs._x;
		const_cast<Fixed&>(this->_y) = rhs._y;
	}
	return (*this);
}

	/***************** COMPARISION ******************/

bool	Point::operator==(Point const & rhs) const
{
	return ((rhs._x == this->_x) && (rhs._y == this->_y) ? true : false);
}

bool	Point::operator!=(Point const & rhs) const
{
	return ((rhs._x != this->_x) || (rhs._y != this->_y) ? false : true);
}

std::ostream & operator<<( std::ostream & os, Point const & rhs)
{
	os << "(" << rhs.getX() << ";" << rhs.getY() << ")";
	return (os);
}