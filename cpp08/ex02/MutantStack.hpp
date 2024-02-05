#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <vector>
#include <list>

#define RESET		"\e[m"
#define RED			"\e[31m"
#define YELLOW		"\e[33m"
#define GREEN		"\e[32m"

template <typename T>
class MutantStack : public std::stack<T> {
	public :
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {}
		virtual ~MutantStack(void) {}

		MutantStack &operator=(MutantStack const &obj) {
			if (this != &obj)
				std::stack<T>::operator=(obj);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {
			return (std::stack<T>::c.begin());
		}
		iterator end(void) {
			return (std::stack<T>::c.end());
		}
};