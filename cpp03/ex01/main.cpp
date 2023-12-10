#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("Scavs");
	std::cout << std::endl;

	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << std::endl;

	a.attack("some other enemy");
	a.guardGate();
	std::cout << std::endl;

	ScavTrap b = a;
	b.attack("another enemy");
	std::cout << std::endl;
	
	ScavTrap c(b);
	c.attack("one more enemy");
	std::cout << std::endl;

	return (0);	
}
