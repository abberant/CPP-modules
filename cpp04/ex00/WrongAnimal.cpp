#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unlabeled")
{
	std::cout << "Default WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal of type " << _type << " constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "WrongAnimal " << _type << " copy constructed" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " destructed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << _type << " made a sound" << std::endl;
}

