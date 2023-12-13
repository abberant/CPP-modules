#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* kitten = new Cat();
	std::cout << std::endl;

	const Animal* puppy = new Dog();
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