#pragma once

# include <iostream>
# include <string>
# include <exception>

# define RESET "\e[m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"


class Bureaucrat
{
	private:
		static int const	_max_grade = 1;
		static int const	_min_grade = 150;
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &source);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &source);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);