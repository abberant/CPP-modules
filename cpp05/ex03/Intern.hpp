#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

#define RESET		"\e[m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"

enum FormType {
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	SHRUBBERY_CREATION
};

class Intern
{
	private:
		std::string		_form_types[3];
	
	public:
		Intern();
		~Intern();

		AForm* makeForm(std::string name, std::string target);

		class FormNotFoundException : public std::exception {
			virtual const char* what() const throw();
		};
};