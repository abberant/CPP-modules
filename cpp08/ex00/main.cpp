#include "easyfind.hpp"

int main(void){
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i);
	std::cout << " ---- List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::cout << YELLOW << "Looking for 2: " << RESET;
		std::cout << *easyfind(lst, 2) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW << "Looking for 5: " << RESET;
		std::cout << *easyfind(lst, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	std::cout << " ---- Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::cout << YELLOW << "Looking for 3: " << RESET;
		std::cout << *easyfind(vec, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW << "Looking for 5: " << RESET;
		std::cout << *easyfind(vec, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> deq;
	for (int i = 0; i < 5; i++)
		deq.push_back(i);
	std::cout << " ---- Deque: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::cout << YELLOW << "Looking for 4: " << RESET;
		std::cout << *easyfind(deq, 4) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW << "Looking for 5: " << RESET;
		std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}