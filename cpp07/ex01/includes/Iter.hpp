#ifndef DEF_ITER
#define DEF_ITER

#include <iostream>
#include "Format.hpp"

template< typename T >

void	iter(T *array, const size_t len, void (*function)(T &)){
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void hello(T & name) {
	std::cout << "Hello " << name << "!" << std::endl;
}

template <typename T>
void display(T & elem) {
	std::cout << elem << std::endl;
}

template <typename T>
void toUpper(T & c) {
		if (c >= 'a' && c <= 'z')
			c -= 32;
}

void toUpper(std::string &str) {
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

template <typename T>
void increment(T & i) {
	i += 1;
}

#endif