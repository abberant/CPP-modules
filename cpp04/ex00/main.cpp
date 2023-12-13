#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << std::endl;
	const	Animal* mammal = new Animal();
	const	Animal* kitten = new Cat();
	const	Animal* puppy = new Dog();
	
	std::cout << std::endl;
	std::cout << "Animal of type " << kitten->getType() << " created" << std::endl;
	std::cout << "Animal of type " << puppy->getType() << " created" << std::endl;
	kitten->makeSound();
	puppy->makeSound();
	mammal->makeSound();

	std::cout << std::endl;
	delete mammal;
	delete kitten;
	delete puppy;

	std::cout << std::endl;
	const	WrongAnimal* amphibian = new WrongAnimal();
	const	WrongAnimal* frog = new WrongCat();

	std::cout << std::endl;
	std::cout << "Animal of type " << frog->getType() << " created" << std::endl;
	amphibian->makeSound();
	frog->makeSound();

	std::cout << std::endl;

	delete amphibian;
	delete frog;
	return (0);
}
