#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog constructed!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& src) : AAnimal(src)
{
	if (this == &src)
		return ;
	_type = src._type;
	_brain = new Brain(*src._brain);
	std::cout << "Dog copy-constructed!" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructed!" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	if (_brain)
		delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog says: \"Woof!\"" << std::endl;
}