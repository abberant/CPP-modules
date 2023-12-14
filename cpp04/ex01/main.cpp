#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *pets[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			pets[i] = new Cat();
		else
			pets[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		delete pets[i];
	}
	std::cout << std::endl;

	Animal* kitten = new Cat();
	std::cout << std::endl;

	Animal* puppy = new Dog();
	std::cout << std::endl;

	kitten->makeSound();
	puppy->makeSound();
	std::cout << std::endl;

	Animal* copy_cat = new Cat(*((Cat*)kitten));
	std::cout << std::endl;
	Animal* copy_dog = new Dog(*((Dog*)puppy));
	std::cout << std::endl;

	delete copy_cat;
	std::cout << std::endl;
	delete copy_dog;
	std::cout << std::endl;
	
	copy_cat = (Cat*)kitten;
	copy_dog = (Dog*)puppy;

	copy_dog->makeSound();
	copy_cat->makeSound();

	std::cout << std::endl;
	delete kitten;
	std::cout << std::endl;
	delete puppy;
	
	return 0;
}