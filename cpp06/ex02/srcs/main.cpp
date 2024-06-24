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
	
}

int	main(void)
{
	Base cc;
	generate();
}
