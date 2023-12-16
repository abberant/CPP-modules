#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Character constructed!" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " constructed!" << std::endl;
}

Character::Character(Character const &other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	std::cout << "Character " << _name << " copy-constructed!" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete _inventory[i];
	std::cout << "Character " << _name << " destructed!" << std::endl;
}

Character &Character::operator=(Character const &rhs)
{
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 4; i++)
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
	std::cout << "Character " << _name << " assigned!" << std::endl;
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}