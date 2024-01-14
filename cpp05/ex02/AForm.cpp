#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
	return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &source) : _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {
	*this = source;
}

AForm::~AForm(void) {
	return ;
}

AForm	&AForm::operator=(const AForm &source) {
	if (this == &source)
		return (*this);
	_signed = source._signed;
	return (*this);
}

std::string AForm::getName(void) const {
	return (_name);
}

bool		AForm::getSigned(void) const {
	return (_signed);
}

int			AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int			AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high!" RESET);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low!" RESET);
}

const char *AForm::FormNotSignedException::what() const throw() {
	return (RED "Form not signed!" RESET);
}

std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os << "Form name: " << form.getName() << " is";
	if (!form.getSigned())
		os << " not";
	os << " signed." << std::endl;
	os << " and requires a grade of " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (os);
}