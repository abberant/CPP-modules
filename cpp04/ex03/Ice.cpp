#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructed!" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice copy-constructed!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructed!" << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
