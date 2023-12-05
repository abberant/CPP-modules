#include "FragTrap.hpp"

int	main(void)
{	
	FragTrap a("Fraggs");

	a.takeDamage(10);
	a.beRepaired(10);
	
	a.attack("some other enemy");
	a.highFivesGuys();

	FragTrap b = a;
	b.attack("another enemy");
	
	FragTrap c(b);
	c.attack("one more enemy");
	
	return (0);	
}