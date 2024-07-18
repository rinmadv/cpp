#include "../includes/span.hpp"
#include <limits>

// Constructors and destructor
Span::Span() : _numbers(0)
{
	if (DEBUG)
		std::cout << "Default constructor called\n"; 
}

Span::Span(unsigned int n)
{
	if (DEBUG)
		std::cout << "Parametrical constructor called\n";
	_numbers.reserve(n);
}

Span::Span(Span const & src)
{
	if (DEBUG)
		std::cout << "Copy constructor called\n"; 
	*this = src;
}

Span::~Span()
{
	if (DEBUG)
		std::cout << "Destructor called\n"; 
}

//Operator=
Span & Span::operator=(Span const & rhs)
{
	if (DEBUG)
		std::cout << "Operator = called\n" ; 
	if (this->_numbers != rhs._numbers)
		_numbers = rhs._numbers;
	return *this;
}

//Insertion
void	Span::addNumber(int n)
{
	if (_numbers.size() >= _numbers.capacity())
		throw std::out_of_range("Span is full");
	_numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	size_t distance = std::distance(begin, end);
	if (distance > (_numbers.capacity() - _numbers.size()))
		throw std::out_of_range("Not enough capacity to fill span with the entire given span");
	if (DEBUG)
		std::cout << _GREY << "Trying to fill span..." << _END << std::endl;
	_numbers.insert(_numbers.end(), begin, end);
}

//Span
int		Span::shortestSpan()
{
	if (DEBUG)
		std::cout << _GREY << "Trying to compute shortest span..." << _END << std::endl;
	if (_numbers.size() <= 1)
		throw std::logic_error("No distance found");

	std::sort(_numbers.begin(), _numbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 0; i < _numbers.size() - 1; ++i) {
        int span = std::abs(_numbers[i + 1] - _numbers[i]);
        if (span < shortest) {
            shortest = span;
        }
    }
	return shortest;
}

int		Span::longestSpan() 
{
	if (DEBUG)
		std::cout << _GREY << "Trying to compute longest span..." << _END << std::endl;
	if (_numbers.size() <= 1)
		throw std::logic_error("No distance found");
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

//DEBUG

void	Span::displaySpan() const
{
	if (DEBUG)
		std::cout << _GREY << "Trying to display span..." << _END << std::endl;
	if (_numbers.empty())
		throw std::out_of_range("Nothing to display");
	for (unsigned int i = 0; i < _numbers.size(); i++)
		std::cout << "[" << i << "] : " << _numbers[i] << std::endl;
}

std::ostream & operator<<(std::ostream & os, Span const & rhs)
{
    rhs.displaySpan();
    return os;
}