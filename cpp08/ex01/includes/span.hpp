#ifndef DEF_SPAN
#define DEF_SPAN

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../includes/Format.hpp"

#define DEBUG true

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & rhs);

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

		int		shortestSpan();
		int		longestSpan();

		void	displaySpan() const;
	private:
		std::vector<int>	_numbers;
};

std::ostream & operator<<( std::ostream & os, Span const & rhs);

#endif