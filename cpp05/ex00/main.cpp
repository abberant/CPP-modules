#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat b1("John", 1);
		std::cout << b1 << "--Decrementing grade..." << std::endl;
		b1.decrementGrade();
		std::cout << b1 << "--Incrementing grade..." << std::endl;
		b1.incrementGrade();
		std::cout << b1 << "--Incrementing grade again..." << std::endl;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("John", 150);
		std::cout << b2 << "--Incrementing grade..." << std::endl;
		b2.incrementGrade();
		std::cout << b2 << "--Decrementing grade..." << std::endl;
		b2.decrementGrade();
		std::cout << b2 << "--Decrementing grade again..." << std::endl;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("John", 0);
		std::cout << b3;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("John", 151);
		std::cout << b4;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}