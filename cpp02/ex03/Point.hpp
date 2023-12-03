#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &other);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;


	private:
		Fixed const	_x;
		Fixed const	_y;
};

Fixed	computeArea(const Point &a, const Point &b, const Point &c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &o, const Point &point);

#endif