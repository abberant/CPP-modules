#include "ScavTrap.hpp"

int	main(void)
{	
	ScavTrap a("Scavs");

	a.takeDamage(10);
	a.beRepaired(10);
	
	a.attack("some other enemy");
	a.guardGate();

	ScavTrap b = a;
	b.attack("another enemy");
	
	ScavTrap c(b);
	c.attack("one more enemy");

	return (0);	
}
