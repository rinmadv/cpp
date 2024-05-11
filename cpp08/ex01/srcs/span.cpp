#include "../includes/Span.hpp"

// Constructors and destructor
Span::Span()
{
	if (DEBUG)
		std::cout << "Default constructor called\n"; 
	_numbers.reserve(0);
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
	if (DEBUG)
	{
		try
		{
			displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
	if (DEBUG)
	{
		try
		{
			displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}
}

//Span
int		Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw std::logic_error("No distance found");

	std::sort(_numbers.begin(), _numbers.end());

	int shortest = std::abs(_numbers[1] - _numbers[0]);
	for (size_t i = 1; i < _numbers.size() - 1; ++i) {
		int span = std::abs(_numbers[i + 1] - _numbers[i]);
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

int		Span::longestSpan() 
{
	if (_numbers.size() <= 1)
		throw std::logic_error("No distance found");
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

//DEBUG

void	Span::displaySpan() const
{
	if (_numbers.empty())
		throw std::out_of_range("Nothing to display");
	for (unsigned int i = 0; i < _numbers.size(); i++)
		std::cout << "[" << i << "] : " << _numbers[i] << std::endl;
}