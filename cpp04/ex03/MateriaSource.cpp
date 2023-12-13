#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default MateriaSource constructed!" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
	std::cout << "MateriaSource copy-constructed!" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "MateriaSource destructed!" << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = rhs._inventory[i]->clone();
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	return (NULL);
}