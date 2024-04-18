#include <iostream>
#include "../includes/Array.hpp"
#include "../includes/Format.hpp"


int main( void )
{
	Array<int> test;
	std::cout << test << std::endl;

	Array<int> essai(4);
	std::cout << essai << std::endl;
	essai[1] = 1;
	essai[2] = 2;
	essai[3] = 3;
	std::cout << essai << std::endl;

	try
	{
		Array<char> truc(26);
		std::cout << truc << std::endl;
		for (size_t i = 0; i < 26; i++)
			truc[i] = 'a' + i;
		std::cout << truc << std::endl;
		
		std::cout << "In bound : " << truc[25] << std::endl;
		std::cout << "Out of bound : " << truc[26] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "!\n";
	}

	return 0;
}