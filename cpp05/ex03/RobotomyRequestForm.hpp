#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &source);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &source);

		std::string getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
};