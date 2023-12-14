#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << std::endl;
	Animal* mammal = new Animal();
	Animal* kitten = new Cat();
	Animal* puppy = new Dog();
	
	std::cout << std::endl;
	std::cout << "A " << kitten->getType() << " was created" << std::endl;
	std::cout << "A" << puppy->getType() << " was created" << std::endl;
	kitten->makeSound();
	puppy->makeSound();
	mammal->makeSound();

	std::cout << std::endl;
	delete mammal;
	delete kitten;
	delete puppy;

	std::cout << std::endl;
	WrongAnimal* amphibian = new WrongAnimal();
	WrongAnimal* frog = new WrongCat();

	std::cout << std::endl;
	std::cout << "Animal of type " << frog->getType() << " created" << std::endl;
	amphibian->makeSound();
	frog->makeSound();

	std::cout << std::endl;

	delete amphibian;
	delete frog;
	return (0);
}
