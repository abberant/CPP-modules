#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(const WrongCat& other);
		virtual ~WrongCat();

		WrongCat	&operator=(const WrongCat& other);
};