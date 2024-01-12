#include "Intern.hpp"

int main(void) {
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Slender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Slender");
		std::cout << *ppf << std::endl;
		delete ppf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Slender");
		std::cout << *scf << std::endl;
		delete scf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("any form", "Slender");
		std::cout << *scf << std::endl;
		delete scf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}