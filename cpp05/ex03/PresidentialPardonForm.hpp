#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &source);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &source);

		std::string getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
};