#pragma once

#include <iostream>
#include <string>
#include <exception>

#define RESET		"\033[0m"
#define RED		"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"

template <typename T>
class Array
{
	private:
		T*		_array;
		int		_size;

	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const& src) {
			this->_array = new T[src._size];
			this->_size = src._size;
			for (int i = 0; i < src._size; i++)
				this->_array[i] = src._array[i];
		}
		~Array(void) { delete [] this->_array; }

		Array& operator=(Array const& src) {
			if (this != &src) {
				delete [] this->_array;
				this->_array = new T[src._size];
				this->_size = src._size;
				for (int i = 0; i < src._size; i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}
		T& operator[](int index) {
			if (index < 0 || index >= this->_size)
				throw OutOfBoundsException();
			return (this->_array[index]);
		}

		int size(void) const { return (this->_size); }

		class OutOfBoundsException : public std::exception {
			virtual const char* what() const throw() {
				return (RED "Index out of bounds." RESET);
			}
		};
};