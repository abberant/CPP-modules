#pragma once

#include <iostream>
#include <string>

# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

template <typename T>
void	iter(T *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	print(T const &i) {
	std::cout << i << std::endl;
}