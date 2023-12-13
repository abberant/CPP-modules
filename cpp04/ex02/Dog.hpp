#pragma once

#include "AbstractAnimal.hpp"

class Dog : public AAnimal
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