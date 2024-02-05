#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>

#define RESET		"\e[m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"

class NotFoundException : public std::exception {
public:
	virtual const char *what() const throw() {
		return (RED "Element not found in container." RESET);
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}