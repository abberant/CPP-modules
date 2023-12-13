#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructed" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}