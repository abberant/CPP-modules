#pragma once

#include "Brain.hpp"

class Animal
{
	protected:

		std::string	_type;

	public:

		Animal();
		Animal(std::string animalType);
		Animal(const Animal& src);
		virtual ~Animal();

		Animal	&operator=(const Animal &other);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
};