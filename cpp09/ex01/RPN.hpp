#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stack>

#define RED "\033[1;31m"
#define RESET "\033[0m"

class RPNEvaluator
{
	private:
		std::stack<double> _operands;
		bool _isOperator(std::string token);
		bool _isOperand(std::string token);
		void _doOperation(char op);

	public:
		RPNEvaluator();
		RPNEvaluator(RPNEvaluator const &src);
		~RPNEvaluator();
		RPNEvaluator &operator=(RPNEvaluator const &src);
		double evaluate(std::string expression);

		class EvaluateErrorException : public std::exception {
			public:
				EvaluateErrorException(const std::string& message);
				virtual ~EvaluateErrorException() throw() {};
				virtual const char *what() const throw();
			private:
				std::string _message;
		};
};