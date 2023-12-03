#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	return ;
}

Fixed::Fixed(const int n) : _value(n << _bits)
{
	return ;
}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _bits)))
{
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
	return ;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (_value >> _bits);
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	_value = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (_value != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}