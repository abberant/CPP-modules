#include "MutantStack.hpp"

int main(void) {

	std::cout << std::endl << YELLOW "Trying to iterate through a stack:" RESET << std::endl;
	std::stack<int> s;
	for (int i = 1; i < 5; i++)
		s.push(i);
	std::cout << "\tStack: ";
	for (std::stack<int> dump = s; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";
	std::cout << std::endl;

	std::cout << std::endl << YELLOW "Trying to iterate through a MutantStack:" RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(4);
	mstack.push(13);
	std::cout <<  GREEN "Last element: " RESET;
	std::cout << mstack.top() << std::endl;
	std::cout <<  YELLOW "<Popping last element>" RESET << std::endl;
	mstack.pop();
	std::cout <<  GREEN "Size (after popping last element): " RESET;
	std::cout << mstack.size() << std::endl;
	mstack.push(9);
	mstack.push(5);
	mstack.push(34);
	mstack.push(284);
	MutantStack<int>::iterator it_b = mstack.begin();
	MutantStack<int>::iterator it_e = mstack.end();
	while (it_b != it_e) {
		std::cout << *it_b << std::endl;
		++it_b;
	}

	return 0;
}