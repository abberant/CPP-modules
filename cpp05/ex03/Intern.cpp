#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	_form_types[ROBOTOMY_REQUEST] = "robotomy request";
	_form_types[PRESIDENTIAL_PARDON] = "presidential pardon";
	_form_types[SHRUBBERY_CREATION] = "shrubbery creation";
	return ;
}

Intern::~Intern(void) {
	return ;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	AForm*	form = NULL;
	int		form_type = -1;

	while (++form_type < 3)
		if (name == _form_types[form_type])
			break ;

	switch (form_type) {
		case ROBOTOMY_REQUEST:
			form = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL_PARDON:
			form = new PresidentialPardonForm(target);
			break;
		case SHRUBBERY_CREATION:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::FormNotFoundException();
			return (NULL);
	}
	std::cout << YELLOW << "Intern" << RESET << " creates " << GREEN << form->getName() << RESET << std::endl;
	return (form);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return (RED "Form not found" RESET);
}