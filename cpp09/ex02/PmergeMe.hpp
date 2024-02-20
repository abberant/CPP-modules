#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"


class PmergeMe {
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &rhs);

		static void _sort_pairs(std::vector<std::pair<int, int> > &vector, size_t size);
		static void _sort_pairs(std::list<std::pair<int, int> > &list, size_t size);
	
	public:
		static void sort(std::vector<int> &vector);
		static void sort(std::list<int> &list);
};

bool validate_sequence(std::string sequence);

template <typename T>
T parse_sequence(std::string sequence) {
	T container;
	std::stringstream ss(sequence);
	int num;
	while (ss >> num)
		container.push_back(num);
	return (container);
}

template <typename T>
void print_sequence(T container) {
	typename T::iterator itb = container.begin();
	typename T::iterator ite = container.end();
	while (itb != ite) {
		std::cout << *itb;
		if (++itb != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_pairs(T container) {
	typename T::iterator itb = container.begin();
	typename T::iterator ite = container.end();
	while (itb != ite) {
		std::cout << "(" << itb->first << ", " << itb->second << ")";
		if (++itb != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int	jacobsthal(int n);

template <typename T>
T	generate_insertion_sequence(size_t size) {
	T sequence;
	if (size < 1)
		return (sequence);
	int jacobsthal_iterator = 2;
	int next = jacobsthal(jacobsthal_iterator++);
	sequence.push_back(next);
	while (sequence.size() < size) {
		next = jacobsthal(jacobsthal_iterator++);
		if (next >= static_cast<int>(size))
			next = size;
		while (sequence.size() < size && next > 0) {
			sequence.push_back(next);
			if (std::find(sequence.begin(), sequence.end(), next - 1) != sequence.end())
				break;
			next--;
		}
	}
	return (sequence);
}