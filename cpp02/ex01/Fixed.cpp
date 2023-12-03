#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (float)(1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}