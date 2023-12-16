#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat& src) : AAnimal(src)
{
	if (this == &src)
		return ;
	_type = src._type;
	_brain = new Brain(*src._brain);
	std::cout << "Cat copy-constructed!" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructed!" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	if (_brain)
		delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says: \"Meow!\"" << std::endl;
}
