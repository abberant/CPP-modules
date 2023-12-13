#pragma once

#include "Brain.hpp"

class AAnimal
{
	protected:

		std::string	_type;

		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& other);

	public:

		std::string		getType() const;

		virtual void	makeSound() const = 0;
};