#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	private:

		Brain	*_brain;

	public:

		Dog();
		Dog(const Dog& src);
		virtual ~Dog();

		Dog	&operator=(const Dog &other);

		virtual void	makeSound(void) const;
};