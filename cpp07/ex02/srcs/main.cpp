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

	std::cout << "Displaying essai:\t" << std::endl;
	for (size_t i = 0; i < essai.getSize(); i++)
	{
		std::cout << "[" << "i" << "] " << essai[i] << std::endl;
	}

	Array<int> copy;
	copy = essai;
	std::cout << "Displaying copy:\t" << std::endl;
	for (size_t i = 0; i < copy.getSize(); i++)
	{
		std::cout << "[" << "i" << "] " << copy[i] << std::endl;
	}

	std::cout << "Displaying copy with modified values:\t" << std::endl;
	copy._elements[0] = 12;

	std::cout << "Displaying essai:\t" << std::endl;
	for (size_t i = 0; i < essai.getSize(); i++)
	{
		std::cout << "[" << "i" << "] " << essai[i] << std::endl;
	}
	try
	{
		copy[12] = 12;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

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