#include "../includes/span.hpp"

Span::Span(){_numbers = std::vector<int>(0);}
Span::Span(unsigned int n){_numbers = std::vector<int>(n);}
Span::Span(Span const & src){*this = src;}
Span::~Span(){};

Span & Span::operator=(Span const & rhs){
	if (this->_numbers != rhs._numbers)
		_numbers = rhs._numbers;
	return *this;
}

void	Span::addNumber(int n){
	if (_numbers.size() >= _numbers.capacity())
		throw std::out_of_range("Span is full");
	_numbers.push_back(n);
}

int		Span::shortestSpan() const{
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

int		Span::longestSpan() const{
	if (_numbers.size() <= 1)
		throw std::logic_error("No distance found");
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}