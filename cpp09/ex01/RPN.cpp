#include "RPN.hpp"

RPNEvaluator::RPNEvaluator(void) {
	return ;
}

RPNEvaluator::RPNEvaluator(RPNEvaluator const &src) {
	*this = src;
	return ;
}

RPNEvaluator::~RPNEvaluator(void) {
	return ;
}

RPNEvaluator &RPNEvaluator::operator=(RPNEvaluator const &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

double RPNEvaluator::evaluate(std::string expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (_isOperand(token))
			_operands.push(std::strtod(token.c_str(), NULL));
		else if (_isOperator(token))
			try {
				_doOperation(token.begin()[0]);
			}
			catch (std::exception &e) {
				throw EvaluateErrorException(e.what());
			}
		else
			throw EvaluateErrorException("Error");
	}
	if (_operands.size() != 1)
		throw EvaluateErrorException("Error");
	return (_operands.top());
}

bool RPNEvaluator::_isOperator(std::string token) {
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (true);
	return (false);
}

bool RPNEvaluator::_isOperand(std::string token) {
	int nb;

	for (std::string::iterator it = token.begin(); it != token.end(); it++)
		if (!std::isdigit(*it))
			return (false);
	nb = std::atoi(token.c_str());
	if (nb < 0 || nb > 9)
		return (false);
	return (true);
}

void RPNEvaluator::_doOperation(char op) {
	double oper1 = 0, oper2 = 0, result = 0;

	if (_operands.size() < 2)
		throw EvaluateErrorException("Error");
	oper2 = _operands.top();
	_operands.pop();
	oper1 = _operands.top();
	_operands.pop();
	switch (op) {
		case '+':
			result = oper1 + oper2;
			break;
		case '-':
			result = oper1 - oper2;
			break;
		case '*':
			result = oper1 * oper2;
			break;
		case '/':
			if (oper2 == 0)
				throw EvaluateErrorException("Error");
			result = oper1 / oper2;
			break;
		default:
			throw EvaluateErrorException("Error");
			return ;
	}
	_operands.push(result);
}

RPNEvaluator::EvaluateErrorException::EvaluateErrorException(const std::string& message) : _message(message) {
	return ;
}

const char *RPNEvaluator::EvaluateErrorException::what() const throw() {
	return _message.c_str();
}