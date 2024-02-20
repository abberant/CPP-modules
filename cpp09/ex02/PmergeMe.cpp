#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
	return ;
}

PmergeMe::~PmergeMe(void) {
	return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void PmergeMe::sort(std::vector<int> &vector) {
	if (vector.size() <= 1)
		return ;
	int straggler = -1;
	if (vector.size() % 2 != 0) {
		straggler = vector.back();
		vector.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vector.size(); i += 2) {
		if (vector[i] < vector[i + 1])
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
		else
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
	}
	_sort_pairs(pairs, pairs.size());
	std::vector<int> sorted;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++) {
		sorted.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (straggler != -1)
		pend.push_back(straggler);
	sorted.insert(sorted.begin(), pend[0]);
	std::vector<int> insertion_order = generate_insertion_sequence<std::vector<int> >(pend.size() - 1);
	if (insertion_order.size() != 0) {
		for (size_t i = 0; i < pend.size() - 1; i++) {
			int element;
			if (insertion_order[i] < static_cast<int>(pend.size()))
				element = pend[insertion_order[i]];
			else
				continue;
			if (element < sorted[0])
				sorted.insert(sorted.begin(), element);
			else {
				for (size_t j = 0; j < sorted.size(); j++) {
					if (element > sorted[j] && (element < sorted[j + 1] || j == sorted.size() - 1)) {
						sorted.insert(sorted.begin() + j + 1, element);
						break ;
					}
				}
			}
		}
	}
	vector = sorted;
}

void PmergeMe::_sort_pairs(std::vector<std::pair<int, int> > &vector, size_t size) {
	if (size <= 1)
		return ;
	size_t mid = size / 2;
	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;
	for (size_t i = 0; i < mid; i++)
		left.push_back(vector[i]);
	for (size_t i = mid; i < size; i++)
		right.push_back(vector[i]);
	_sort_pairs(left, left.size());
	_sort_pairs(right, right.size());
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].first < right[j].first)
			vector[k++] = left[i++];
		else
			vector[k++] = right[j++];
	}
	while (i < left.size())
		vector[k++] = left[i++];
	while (j < right.size())
		vector[k++] = right[j++];
}

void PmergeMe::sort(std::list<int> &list) {
	if (list.size() <= 1)
		return ;
	int straggler = -1;
	if (list.size() % 2 != 0) {
		straggler = list.back();
		list.pop_back();
	}
	std::list<std::pair<int, int> > pairs;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		int first = *it++;
		int second = *it;
		if (first < second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}
	_sort_pairs(pairs, pairs.size());
	std::list<int> sorted;
	std::list<int> pend;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		sorted.push_back(it->first);
		pend.push_back(it->second);
	}
	if (straggler != -1)
		pend.push_back(straggler);
	sorted.push_front(pend.front());
	std::list<int> insertion_order = generate_insertion_sequence<std::list<int> >(pend.size() - 1);
	if (insertion_order.size() != 0) {
		for (std::list<int>::iterator it = insertion_order.begin(); it != insertion_order.end(); it++) {
			int element_index = *it;
			std::list<int>::iterator itp = pend.begin();
			std::advance(itp, element_index);
			int element = *itp;
			if (element < sorted.front())
				sorted.push_front(element);
			else {
				std::list<int>::iterator current;
				std::list<int>::iterator next;
				for (std::list<int>::iterator its = sorted.begin(); its != sorted.end(); its++) {
					current = its++;
					next = its;
					if (element > *current && (element < *next || its == sorted.end()))
						break ;
					its = current;
				}
				sorted.insert(next, element);
			}
		}
	}
	list = sorted;
}

void PmergeMe::_sort_pairs(std::list<std::pair<int, int> > &list, size_t size) {
	if (size <= 1)
		return ;
	std::list<std::pair<int, int> > left;
	std::list<std::pair<int, int> > right;
	std::list<std::pair<int, int> >::iterator it = list.begin();
	for (size_t i = 0; i < size / 2; i++)
		left.push_back(*it++);
	for (size_t i = size / 2; i < size; i++)
		right.push_back(*it++);
	list.clear();
	_sort_pairs(left, left.size());
	_sort_pairs(right, right.size());
	while (right.size() && left.size()) {
		if (left.front().first < right.front().first) {
			list.push_back(left.front());
			left.pop_front();
		}
		else {
			list.push_back(right.front());
			right.pop_front();
		}
	}
	while (left.size()) {
		list.push_back(left.front());
		left.pop_front();
	}
	while (right.size()) {
		list.push_back(right.front());
		right.pop_front();
	}
}

bool validate_sequence(std::string sequence) {
	std::istringstream ss(sequence);
	std::string token;
	std::vector<int> seenNumbers;
	while (ss >> token) {
		if (token.find_first_not_of("0123456789") != std::string::npos) {
			std::cerr << "Error: Only positive digits are allowed." << std::endl;
			return false;
		}
		int num = std::stoi(token.c_str());
		for (size_t i = 0; i < seenNumbers.size(); i++) {
			if (seenNumbers[i] == num) {
				std::cerr << "Error: Only unique numbers are allowed." << std::endl;
				return false;
			}
		}
		seenNumbers.push_back(num);
	}
	return true;
}

int	jacobsthal(int n) {
	if (n <= 1)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}