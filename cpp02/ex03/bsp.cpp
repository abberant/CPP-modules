#include "Point.hpp"

Fixed	computeArea(const Point &a, const Point &b, const Point &c)
{
	Fixed	_area;

	_area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	if (_area < 0)
		_area = _area * Fixed(-1);
	return (_area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	_area;
	Fixed	_area1;
	Fixed	_area2;
	Fixed	_area3;

	_area = computeArea(a, b, c);
	_area1 = computeArea(point, b, c);
	_area2 = computeArea(a, point, c);
	_area3 = computeArea(a, b, point);
	if (_area == _area1 + _area2 + _area3)
		return (true);
	return (false);
}