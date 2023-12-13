#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
	std::cout << "Cat copy constructed" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << _type << " says: \"Meow\"" << std::endl;
}
