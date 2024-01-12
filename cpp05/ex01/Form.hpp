#pragma once

#include <iostream>

#define RESET		"\e[m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"

class Bureaucrat;

class Form
{
	private:
		static int const	_max_grade = 1;
		static int const	_min_grade = 150;
		std::string const	_name;
		bool				_signed;
		int const			_grade_to_sign;
		int const			_grade_to_execute;

	public:
		Form(void);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form &source);
		~Form(void);

		Form	&operator=(const Form &other);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &form);