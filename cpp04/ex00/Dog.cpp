#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copy constructed" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << _type << " says: \"Woof\"" << std::endl;
}