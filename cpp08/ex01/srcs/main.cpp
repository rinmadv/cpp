#include "../includes/Span.hpp"
#include "../includes/Format.hpp"

#include <vector>
#include <limits.h>

static void displayTitle(std::string str)
{
	std::cout << std::endl << _BOLD _AQUAMARINE << "⏳ " << str << "... ⌛" << _END << std::endl;
}

int main()
{
	displayTitle("TESTS ON SMALL CONTAINORS");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	displayTitle("TESTS WITH NO SPAN");
	Span spa = Span(0);
	try
	{
		std::cout << spa.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span span = Span(1);
	span.addNumber(6);
	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Span spann = Span(3);
	spann.addNumber(6);
	spann.addNumber(3);
	try
	{
		std::cout << spann.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span spannn = Span(3);
	try
	{
		std::cout << spannn.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	displayTitle("TESTS WITH ITERATORS");
	int size = 100000;

	std::vector<int> numbers;
	for (int i = 0; i < size; i++)
		numbers.push_back(i);

	Span spannnn = Span(size);
	spannnn.addNumbers(numbers.begin(), numbers.end() - 99900);

	return 0;
}