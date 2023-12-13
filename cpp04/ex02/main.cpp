#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Cat* kitten = new Cat();
	std::cout << std::endl;

	const Dog* puppy = new Dog();
	std::cout << std::endl;

	kitten->makeSound();
	puppy->makeSound();
	std::cout << std::endl;

	Cat* copy_cat = new Cat(*((Cat*)kitten));
	std::cout << std::endl;
	Dog* copy_dog = new Dog(*((Dog*)puppy));
	std::cout << std::endl;

	delete copy_cat;
	std::cout << std::endl;
	delete copy_dog;
	std::cout << std::endl;
	
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