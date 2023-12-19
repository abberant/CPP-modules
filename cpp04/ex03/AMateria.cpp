#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "Default AMateria constructed!" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria type " << type << " constructed!" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	std::cout << "AMateria type " << _type << " constructed!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructed!" << std::endl;

}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << GREEN << "* " << _type << " uses its powers at " << target.getName() << " *" << RESET << std::endl;
}