#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

static void	test_schrubbery(void) {
	std::cout << std::endl;
	try {
		ShrubberyCreationForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
		try {
		ShrubberyCreationForm form("Nicole");
		Bureaucrat bureaucrat("Nick", 140);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		ShrubberyCreationForm form("Carla");
		Bureaucrat bureaucrat("Steve", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	test_robotomy(void) {
	std::cout << std::endl;
	try {
		RobotomyRequestForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		RobotomyRequestForm form("Nicole");
		Bureaucrat bureaucrat("Nick", 60);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		RobotomyRequestForm form("Carla");
		Bureaucrat bureaucrat("Steve", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	test_presidential(void) {
	std::cout << std::endl;
	try {
		PresidentialPardonForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm form("Nicole");
		Bureaucrat bureaucrat("Nick", 15);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm form("Carla");
		Bureaucrat bureaucrat("Steve", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	test_schrubbery();
	test_robotomy();
	test_presidential();
	return 0;
}