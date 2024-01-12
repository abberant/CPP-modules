#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &source);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &source);

		std::string getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
		// Exception classes
		class FileNotOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};