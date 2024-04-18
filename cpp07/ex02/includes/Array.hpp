#ifndef DEF_ARRAY
#define DEF_ARRAY

#include <iostream>
#include "Format.hpp"

template <typename T>
class Array {

	public:
		Array() {_elements = NULL; _size = 0;}

		Array(unsigned int n) {_elements = new T[n]; _size = n;}
		
		Array(Array const &src) {*this = src;};

		~Array(){
			if (_elements)
				delete[] _elements;
		}

		Array & operator=(Array const &src)
		{
			Array copy(src.size());
			for (size_t i = 0; i < src.size(); i ++)
				copy._elements[i] = src._elements[i];
			return (copy);
		}

		T &operator[](unsigned int index) {
			if (index >= _size)
				throw OutBoundIndexException();
			return _elements[index];
		}

		size_t const & size() const {return (_size);}
		
		T		*_elements;
	
	private:
		size_t	_size;


	class OutBoundIndexException: public std::exception {
		public:
			virtual const char* what() const throw()
			{return _RED "Out of bound index" _END;} };

};

template <typename T>
std::ostream & operator<<( std::ostream & os, Array<T> const & rhs)
{
	os << "[ ";
	for (size_t i = 0; i < rhs.size(); ++i) {
		os << rhs._elements[i] << " ";
	}
	os << "]";
	return os;
}


/*
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
[x]Construction with no parameter: Creates an empty array.
[x]Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
[x]Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
[x]You MUST use the operator new[] to allocate memory. Preventive allocation (al-
locating memory in advance) is forbidden. Your program must never access non-
allocated memory.
[]Elements can be accessed through the subscript operator: [ ].
[x]When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
[x]A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.

As usual, ensure everything works as expected and turn in a main.cpp file that con-
tains your tests.
*/

#endif