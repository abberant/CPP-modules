#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamond");
	
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "ClapTrapName: " << diamond.getClapName() << std::endl;
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;
	
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.attack("enemy");
	diamond.takeDamage(10);
	diamond.beRepaired(10);

	diamond.whoAmI();
	
	return (0);
}