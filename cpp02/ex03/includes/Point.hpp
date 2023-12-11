#ifndef DEF_POINT
#define DEF_POINT

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{

public:
	Point(void);//
	Point(float const x, float const y);//
	Point(Point const & src);//
	~Point(void);//

	Point &	operator=(Point const & rhs);//
	
	bool	operator==(Point const & rhs) const;
	bool	operator!=(Point const & rhs) const;

	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
	//autre
};

std::ostream & operator<<( std::ostream & os, Point const & rhs);

#endif
