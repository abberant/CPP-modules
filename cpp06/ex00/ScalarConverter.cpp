#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &source) {
	*this = source;
	return ;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
	if (this == &source)
		return (*this);
	*this = source;
	return (*this);
}

void ScalarConverter::convert(const std::string &literal) {
	try {
		int type = _getType(literal);
		switch (type)
		{
			case CHAR:
				_toChar(literal);
				break;
			case INT:
				_toInt(literal);
				break;
			case FLOAT:
				_toFloat(literal);
				break;
			case DOUBLE:
				_toDouble(literal);
				break;
			default:
				throw InvalidLiteralException();
				break;
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;	
}

int ScalarConverter::_getType(const std::string &literal) {
	if (_isChar(literal))
		return (CHAR);
	if (_isInt(literal))
		return (INT);
	if (_isFloat(literal))
		return (FLOAT);
	if (_isDouble(literal))
		return (DOUBLE);
	throw InvalidLiteralException();
}

bool ScalarConverter::_isChar(const std::string &literal) {
	size_t  len = literal.length();
	if (literal[0] == '\'' && literal[len - 1] == '\'') {
		if (len == 3 && (literal[1] > 31 && literal[1] < 127))
			return (true);
		if (len == 4 && literal[1] == '\\')
			if (literal[2] == 'n' || literal[2] == 't' || literal[2] == 'v' || literal[2] == 'b' || literal[2] == 'r' || literal[2] == 'f' || literal[2] == 'a' || literal[2] == '\\' || literal[2] == '0' || literal[2] == 'e')
				return (true);
		if (len > 4 && literal[1] == '\\') {
			for (size_t i = 2; i < len - 1; i++)
				if (literal[i] != 'x' && !std::isxdigit(literal[i]))
					return (false);
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::_isInt(const std::string &literal) {
	size_t	len = literal.length();
	long	nb;

	if (len == 1 && !std::isdigit(literal[0]))
		return (true);
	for (size_t i = 0; i < len; i++) {
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			i++;
		if (!std::isdigit(literal[i]))
			return (false);
	}
	nb = std::strtol(literal.c_str(), NULL, 10);
	if (nb < INT_MIN || nb > INT_MAX)
		return (false);
	return (true);
}

bool ScalarConverter::_isFloat(const std::string &literal) {
	size_t	len = literal.length();
	bool	dot = false;
	size_t	i = 0;
	double	nb;

	if (literal.substr(i, len) == "nanf")
		return (true);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (literal.substr(i, len) == "inff")
		return (true);
	if (literal[len - 1] != 'f')
		return (false);
	for (; i < len - 1; i++) {
		if (literal[i] == '.' && !dot)
			dot = true;
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	if (!dot)
		return (false);
	nb = std::strtod(literal.c_str(), NULL);
	if (nb > FLT_MAX || nb < -FLT_MAX)
		return (false);
	return (true);
}

bool ScalarConverter::_isDouble(const std::string &literal) {
	size_t	len = literal.length();
	size_t	i = 0;
	bool	dot = false;
	double	nb;

	if (literal.substr(i, len) == "nan")
		return (true);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (literal.substr(i, len) == "inf")
		return (true);
	for (; i < len; i++) {
		if (literal[i] == '.' && !dot)
			dot = true;
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	if (!dot)
		return (false);
	nb = std::strtod(literal.c_str(), NULL);
	if (nb > DBL_MAX || nb < -DBL_MAX)
		return (false);
	return (true);
}

void ScalarConverter::_toChar(const std::string &literal) {
	size_t	len = literal.length();

	std::cout << "Char: ";
	try {
		if (len > 3 || literal[1] == 32)
			throw NonDisplayableException();
		std::cout << "'" << static_cast<char>(literal[1]) << "'" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::_toInt(const std::string &literal) {
	int	nb;

	std::cout << "Int: ";
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		nb = static_cast<int>(literal[0]);
	else
		nb = std::atoi(literal.c_str());
	std::cout << nb << std::endl;
	return ; 
}

void	ScalarConverter::_toFloat(const std::string &literal) {
	float	nb;
	int		len = literal.length();
	int		i = 0;
	int		sign = 1;

	if (literal.substr(i, len) == "nanf")
		nb = std::numeric_limits<float>::quiet_NaN();
	else {
		if (literal[i] == '-' || literal[i] == '+') {
			if (literal[i] == '-')
				sign *= -1;
			i++;
		}
		if (literal.substr(i, len) == "inff")
			nb = std::numeric_limits<float>::infinity() * sign;
		else
			nb = std::atof(literal.c_str());
	}
	std::cout << "Float: " << nb << "f" << std::endl;
	return ;
}

void	ScalarConverter::_toDouble(const std::string &literal) {
	double	nb;
	int		len = literal.length();
	int		i = 0;
	int		sign = 1;

	if (literal.substr(i, len) == "nan")
		nb = std::numeric_limits<double>::quiet_NaN();
	else {
		if (literal[i] == '-' || literal[i] == '+') {
			if (literal[i] == '-')
				sign *= -1;
			i++;
		}
		if (literal.substr(i, len) == "inf")
			nb = std::numeric_limits<double>::infinity() * sign;
		else
			nb = std::strtod(literal.c_str(), NULL);
	}
	std::cout << "Double: " << nb << std::endl;
	return ;
}

const char *ScalarConverter::InvalidLiteralException::what() const throw() {
	return (RED "Invalid literal" RESET);
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return (RED "Non displayable" RESET);
}