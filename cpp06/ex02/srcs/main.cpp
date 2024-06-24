#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <random>

class Base;
class A;
class B;
class C;

Base * generate(void)
{
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3);

    int random_number = distrib(gen);
	if (DEBUG)
    	std::cout << "Random number between 1 and 3: " << random_number << std::endl;
	if (random_number == 1)
		return (new A());
	else if (random_number == 2)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (DEBUG)
		std::cout << _BOLD _SALMON "Identification with pointer : " << _END;

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	if (DEBUG)
		std::cout << _BOLD _SALMON "Identification with reference : " << _END;

	Base	test;
	try {
		test = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try 
		{
			test = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e)
		{
			try 
			{
				test = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << _BOLD _MAGENTA "Test " << i << _END << std::endl;
		Base *mystere = generate();
		identify(mystere);
		identify(*mystere);
		std::cout << std::endl;
	}
	std::cout << _BOLD _MAGENTA "Test with unknown type" << _END << std::endl;
	identify(NULL);

	Base *base;
	identify(base);
	identify(*base);

	return (0);
}
