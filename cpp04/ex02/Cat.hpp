#pragma once

#include "AbstractAnimal.hpp"

class Cat : public AAnimal
{
	private:

		Brain	*_brain;

	public:

		Cat();
		Cat(const Cat& src);
		virtual ~Cat();

		Cat	&operator=(const Cat &other);

		virtual void	makeSound(void) const;
};