#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap hero("Hero");
	ClapTrap villain("Villain");

	std::cout << std::endl;
	std::cout << villain.getName() << " wants to attack." << std::endl;
	villain.attack(hero.getName());
	std::cout << hero.getName() << " now attacks" << std::endl;
	hero.attack(villain.getName());
	std::cout << "None of them have any attack damage points! This will be a never ending fight!" << std::endl;
	villain.takeDamage(hero.getAttackDamage());
	std::cout << "In anger, " << villain.getName() << " attacked 9 times in a row!" << std::endl;
	for (int i = 0; i < 9; i++)
		villain.attack(hero.getName());
	std::cout << hero.getName() << " didn't feel even an itch." << std::endl;
	std::cout << villain.getName() << " is so tired, they can't attack anymore." << std::endl;
	villain.attack(hero.getName());
	std::cout << hero.getName() << " won!" << std::endl;
	return (0);	
}