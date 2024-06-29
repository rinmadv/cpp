#include "../includes/Span.hpp"
#include "../includes/Format.hpp"

#include <vector>
#include <limits.h>

static void displayTitle1(std::string str)
{
	std::cout << std::endl << _BOLD _AQUAMARINE << "⏳ " << str << "... ⌛" << _END << std::endl;
}

static void displayTitle2(std::string str)
{
	std::cout << std::endl << _ITALIC _MAGENTA << "✨ " << str << "... ✨" << _END << std::endl;
}

int main()
{
	displayTitle1("TESTS ON SMALL CONTAINORS");
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

	displayTitle1("TESTS WITH NO SPAN");
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

	displayTitle1("TESTS WITH ITERATORS");

	int size = 100000;
	std::vector<int> numbers;
	for (int i = 0; i < size; i++)
		numbers.push_back(i);

	displayTitle2("TEST WITH ENOUGH CAPACITY");

	Span spannnn = Span(size);
	if (DEBUG)
	{
		try
		{
			spannnn.displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}

	try
	{
		spannnn.addNumbers(numbers.begin(), numbers.end() - 99900);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (DEBUG)
	{
		try
		{
			spannnn.displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}

	displayTitle2("TEST WITH NOT ENOUGH CAPACITY");
	size = 2;
	Span spannnnn = Span(size);
	if (DEBUG)
	{
		try
		{
			spannnnn.displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}
	try
	{
		spannnnn.addNumbers(numbers.begin(), numbers.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (DEBUG)
	{
		try
		{
			spannnnn.displaySpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		} 
	}

displayTitle1("TEST WITH RANDOM NUMBERS");
    std::srand(std::time(nullptr));
    Span randomSpan = Span(10000);
    for (int i = 0; i < 10000; ++i)
    {
        randomSpan.addNumber(std::rand() % 100000);
    }
    std::cout << "Shortest span: " << randomSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << randomSpan.longestSpan() << std::endl;

    displayTitle1("TEST WITH MIXED NUMBERS");
    Span mixedSpan = Span(6);
    mixedSpan.addNumber(-10);
    mixedSpan.addNumber(-5);
    mixedSpan.addNumber(0);
    mixedSpan.addNumber(5);
    mixedSpan.addNumber(10);
    mixedSpan.addNumber(15);
    std::cout << "Shortest span: " << mixedSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << mixedSpan.longestSpan() << std::endl;

    displayTitle1("TEST WITH EXTREME VALUES");
    Span extremeSpan = Span(3);
    extremeSpan.addNumber(INT_MIN);
    extremeSpan.addNumber(0);
    extremeSpan.addNumber(INT_MAX);
    std::cout << "Shortest span: " << extremeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << extremeSpan.longestSpan() << std::endl;


	displayTitle1("CALLING DESTRUCTORS");
	return 0;
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }