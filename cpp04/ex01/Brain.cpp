#include "Brain.hpp"

Brain::Brain()
{
	std::stringstream	ss;
	for (int i = 0; i < 100; i++) {
		ss << "Idea #" << i + 1;
		_ideas[i] = ss.str();
		ss.str("");
	}
	std::cout << "Brain constructed!" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Brain copy-constructed!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructed!" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

std::string *Brain::getIdeas(void)
{
	return (_ideas);
}