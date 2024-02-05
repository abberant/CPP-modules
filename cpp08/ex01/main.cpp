#include "Span.hpp"

int main(void) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	try {
		sp.addNumber(1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span sp3 = Span(10000);
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp3.addNumber(std::rand() % 10000);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp4 = Span(100000);
	std::list<int> lst;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
		lst.push_back(std::rand() % 100000);
	sp4.addRange(lst.begin(), lst.end());
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
	
	return (0);
}