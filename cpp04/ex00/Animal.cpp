#include "Animal.hpp"

Animal::Animal() : _type("unlabeled")
{
	std::cout << "Default Animal constructed" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal of type " << _type << " constructed" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal " << _type << " copy constructed" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " destructed" << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal ";
	if (_type != "")
		std::cout << _type << " ";
	std::cout << "says: \"...\"" << std::endl;
}