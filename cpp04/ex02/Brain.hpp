#pragma once

#include <iostream>
#include <sstream>

class Brain
{
	private:

		std::string	_ideas[100];

	public:

		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain	&operator=(const Brain &other);

		std::string *getIdeas(void);
};