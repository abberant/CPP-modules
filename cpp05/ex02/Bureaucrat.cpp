#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name) {
	*this = source;
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source) {
	if (this == &source)
		return (*this);
	_grade = source._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int			Bureaucrat::getGrade(void) const {
	return (_grade);
}

void		Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void		Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void		Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << " signs " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because the " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << GREEN << _name << " executes " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << _name << " couldn't execute " << form.getName() << " because the " << e.what() << RESET << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low!" RESET);
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << YELLOW << bureaucrat.getName() << RESET << ", bureaucrat grade " << YELLOW << bureaucrat.getGrade() << RESET << "." << std::endl;
	return (os);
}