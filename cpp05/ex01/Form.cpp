#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _grade_to_sign(150), _grade_to_execute(150) {
	return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < _max_grade || grade_to_execute < _max_grade)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > _min_grade || grade_to_execute > _min_grade)
		throw Form::GradeTooLowException();
	else
		_signed = false;
}

Form::Form(const Form &source) : _name(source._name), _grade_to_sign(source._grade_to_sign), _grade_to_execute(source._grade_to_execute) {
	*this = source;
}

Form::~Form(void) {
	return ;
}

Form	&Form::operator=(const Form &other) {
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

std::string	Form::getName(void) const {
	return (_name);
}

bool		Form::getSigned(void) const {
	return (_signed);
}

int			Form::getGradeToSign(void) const {
	return (_grade_to_sign);
}

int			Form::getGradeToExecute(void) const {
	return (_grade_to_execute);
}

void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high!" RESET);
}

const char *Form::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low!" RESET);
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed, requires grade " << form.getGradeToSign() << " to sign, and grade " << form.getGradeToExecute() << " to execute." << std::endl;
	return (out);
}

