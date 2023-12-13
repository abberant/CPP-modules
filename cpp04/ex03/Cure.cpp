#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructed!" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure copy-constructed!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructed!" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}