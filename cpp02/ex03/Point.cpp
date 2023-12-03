#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point::~Point(void)
{
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

std::ostream &operator<<(std::ostream &o, const Point &point)
{
	o << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (o);
}