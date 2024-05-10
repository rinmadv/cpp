#ifndef DEF_SPAN
#define DEF_SPAN

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../includes/Format.hpp"

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & rhs);

		void	addNumber(int n);

		int		shortestSpan() const;
		int		longestSpan() const;

		class isEmpty : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "Containor is empty" _END);
				}
		};

	private:
		std::vector<int>	_numbers;
};

std::ostream & operator<<( std::ostream & os, Span const & rhs);



// template<typename T>
// typename T::const_iterator easyfind(T &container, int val)
// {
// 	typename T::const_iterator it = std::find(container.begin(), container.end(), val);
// 	if (it != container.end()){
// 		return it;
// 	} else {
// 		throw std::invalid_argument("😭 Value not found");
// 	}
// }

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const std::pair<T, int>& pair) {
//	 try {
//		 typename T::const_iterator it = easyfind(pair.first, pair.second);
//		 os << _FOREST_GREEN <<"🎯 Value found at index " << _BOLD << std::distance(pair.first.begin(), it) << _END;
//	 } catch (const std::invalid_argument &e) {
//		 os << _RED << e.what() << _END;
//	 }
//	 return os;
// }

#endif