#include "FragTrap.hpp"

int	main(void)
{	
	FragTrap a("Fraggs");
	std::cout << std::endl;

	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << std::endl;
	
	a.attack("some other enemy");
	std::cout << std::endl;

	FragTrap b = a;
	b.attack("another enemy");
	std::cout << std::endl;
	
	FragTrap c(b);
	c.attack("one more enemy");
	std::cout << std::endl;

	a.highFivesGuys();
	std::cout << std::endl;
	
	return (0);	
}