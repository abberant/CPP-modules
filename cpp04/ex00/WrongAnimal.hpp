#pragma once

#include <iostream>

class WrongAnimal
{
	protected:

		std::string _type;

	public:

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal& other);

		std::string getType() const;
	
		void makeSound() const;
};