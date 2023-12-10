#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamond");
	std::cout << std::endl;
	
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "ClapTrapName: " << diamond.getClapName() << std::endl;
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	diamond.highFivesGuys();
	std::cout << std::endl;
	diamond.guardGate();
	std::cout << std::endl;
	diamond.attack("enemy");
	std::cout << std::endl;
	diamond.takeDamage(10);
	std::cout << std::endl;
	diamond.beRepaired(10);
	std::cout << std::endl;

	diamond.whoAmI();
	std::cout << std::endl;
	
	return (0);
}