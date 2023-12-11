#include "../includes/Point.hpp"

static double	crossProduct(Point const& first, Point const& second, Point const& point)
{
	double xfirst = first.getX().getRawBits();
	double yfirst = first.getY().getRawBits();
	double xsecond = second.getX().getRawBits();
	double ysecond = second.getY().getRawBits();
	double xpoint = point.getX().getRawBits();
	double ypoint = point.getY().getRawBits();
	return ((xsecond - xfirst) * (ypoint - yfirst) - (xpoint - xfirst) * (ysecond - yfirst));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double cross_product_1 = crossProduct(a, b, point);
	double cross_product_2 = crossProduct(b, c, point);
	double cross_product_3 = crossProduct(c, a, point);

	bool on_edge = cross_product_1 == 0 || cross_product_2 == 0 || cross_product_3 == 0 ;
	bool inside = (cross_product_1 > 0 && cross_product_2 > 0 && cross_product_3 > 0)
			|| (cross_product_1 < 0 && cross_product_2 < 0 && cross_product_3 < 0);
	
	return (!on_edge && inside);
}

