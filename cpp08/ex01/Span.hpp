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

class Span {
	private:
		unsigned int		_n;
		std::vector<int>	_vec;
	
	public:
	Span(unsigned int n);
	Span(const Span &source);
	~Span();

	Span &operator=(const Span &source);

	void	addNumber(int n);
	int		shortestSpan(void);
	int		longestSpan(void);

	template <typename T>
	void	addRange(T begin, T end) {
		if (this->_vec.size() + std::distance(begin, end) > this->_n)
			throw FullContainerException();
		this->_vec.insert(this->_vec.end(), begin, end);
		return ;
	}

	unsigned int		getN(void) const;
	std::vector<int>	getVec(void) const;

	class FullContainerException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughElementsException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};
