#ifndef DEF_ARRAY
#define DEF_ARRAY

#include <iostream>
#include "Format.hpp"

template <typename T>

class Array {

	public:

		Array() {_elements = NULL; _size = 0; std::cout<<_BLUE"basic constructor called\n"_END;}

		Array(unsigned int n)
		{
			try
			{
				_elements = new T[n]; _size = n;
			}
			catch(const std::exception& e)
			{
        		throw std::runtime_error("Cannot allocate array");
			}
			
			for (size_t i = 0 ; i < _size ; i++){
				this->_elements[i] = T();
			}
		}
		
		Array(Array const &src) : _elements(NULL), _size(0) {*this = src;};

		~Array(){
			if (_elements)
			{
				delete[] _elements;
				_elements = NULL;		
			}
		}

		Array & operator=(Array const &src)
		{
			if (this == &src)
				return (*this);
			try
			{
				delete[] _elements;
				_elements = NULL;
			}
			catch(const std::exception& e)
			{
			}
			this->_size = src.size();
			if (!_size)
				return (*this) ;
			this->_elements = new T[this->_size];
			
			for (size_t i = 0; i < _size; i++)
				this->_elements[i] = src._elements[i];
			return (*this);
		}

		T &operator[](unsigned int index) {
			if (index >= _size)
			{
				throw OutBoundIndexException();
			}
			return _elements[index];
		}

		size_t const & size() const {return (_size);}

		class OutBoundIndexException: public std::exception {
			public:
				virtual const char* what() const throw()
				{return _RED "Out of bound index" _END;} };
		 
	private:
		T		*_elements;
		size_t	_size;

};

template <typename T>
std::ostream & operator<<( std::ostream & os, Array<T> & rhs)
{
	os << "[ ";
	for (size_t i = 0; i < rhs.size(); ++i) {
		os << (rhs[i]) << " ";
	}
	os << "]";
	return os;
}

#endif