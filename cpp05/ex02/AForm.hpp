#pragma once

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		static int const	_maxGrade = 1;
		static int const	_minGrade = 150;
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &source);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &other);

		std::string getName(void) const;	
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(Bureaucrat &bureaucrat);

		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);