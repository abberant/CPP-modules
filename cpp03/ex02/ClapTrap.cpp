#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	std::cout << "ClapTrap " << _name << " constructed by copy!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

int			ClapTrap::getHitPoints(void)
{
	return (_hitPoints);
}

int		ClapTrap::getEnergyPoints(void)
{
	return (_energyPoints);
}

int		ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " can't attack " << target << " because he's dead!" << std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "ClapTrap " << _name << " can't attack " << target << " because he's out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " can't take damage because he's dead!" << std::endl;
		return ;
	}
	if (amount >= _hitPoints) {
		std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
		_hitPoints = 0;
	}
	else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _name << " can't be repaired because he's dead!" << std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "ClapTrap " << _name << " can't be repaired because he's out of energy!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	if (_hitPoints > 10)
		_hitPoints = 10;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
	_energyPoints--;
}