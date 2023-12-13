#pragma once

#include "Animal.hpp"

class Cat : public Animal
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