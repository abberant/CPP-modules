#include "Animal.hpp"

Animal::Animal() : _type("Unlabeled")
{
	std::cout << "Animal constructed!" << std::endl;
}

Animal::Animal(std::string animalType) : _type(animalType)
{
	std::cout << "Animal of type: " << _type << " constructed!" << std::endl;
}

Animal::Animal(const Animal& src)
{
	*this = src;
	std::cout << "Animal of type: " << _type << " copy-constructed!" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "Animal of type: " << _type << " destructed!" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal of type: " << _type << " says: \"...\"" << std::endl;
}