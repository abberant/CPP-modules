#pragma once

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <limits>
#include <cfloat>
#include <string.h>

#define RESET		"\e[m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define CYAN		"\e[36m"

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

const std::string _pseudo_literals[] = {"nan", "inf"};

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &source);
		~ScalarConverter(void);

		ScalarConverter &operator=(const ScalarConverter &source);

		static int _getType(const std::string &literal);

		static bool _isChar(const std::string &literal);
		static bool _isInt(const std::string &literal);
		static bool _isFloat(const std::string &literal);
		static bool _isDouble(const std::string &literal);

		static void _toChar(const std::string &literal);
		static void _toInt(const std::string &literal);
		static void _toFloat(const std::string &literal);
		static void _toDouble(const std::string &literal);
	
	public:
		static void convert(const std::string &literal);

		class InvalidLiteralException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NonDisplayableException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};