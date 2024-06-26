#include <iostream>
#include "../includes/Array.hpp"
#include "../includes/Format.hpp"
#include <cstdlib>


void	displayTitle0(std::string text)
{
		std::cout << _BOLD _SALMON "******************************" << std::endl;
		std::cout <<  text << std::endl;
		std::cout <<  "******************************" _END << std::endl;
		std::cout << std::endl;

}

void	displayTitle1(std::string text)
{
		std::cout << _CYAN _UNDER << text +_END << std::endl;
		std::cout << std::endl;
}

void	displayTitle2(std::string text)
{
		std::cout << _ITALIC _GREY << text +_END << std::endl;
		std::cout << std::endl;
}

int main( void )
{
	displayTitle0("\tTest with ints");

		displayTitle1("Test with empty array");
		Array<int> test;
		std::cout << test << std::endl << std::endl;

		displayTitle1("Test with full array");
		Array<int> essai(4);

		displayTitle2("Displaying array (essai) with default values");
		std::cout << essai << std::endl << std::endl;
		
		displayTitle2("Displaying array (essai) with assigned values");
		essai[1] = 1;
		essai[2] = 2;
		essai[3] = 3;
		for (size_t i = 0; i < essai.size(); i++)
		{
			std::cout << "[" << "i" << "] " << essai[i] << std::endl;
		}
		std::cout << std::endl;

		displayTitle2("Displaying new array (copy)");
		Array<int> copy;
		copy = essai;
		for (size_t i = 0; i < copy.size(); i++)
		{
			std::cout << "[" << "i" << "] " << copy[i] << std::endl;
		}
		std::cout << std::endl;

		displayTitle2("Displaying copy with modified values:\t");
		copy[0] = 12;
		for (size_t i = 0; i < copy.size(); i++)
		{
			std::cout << "[" << "i" << "] " << copy[i] << std::endl;
		}
		std::cout << std::endl;
	
		displayTitle2("Displaying essai to make sure its value stay unchanged:\t");
		for (size_t i = 0; i < essai.size(); i++)
		{
			std::cout << "[" << "i" << "] " << essai[i] << std::endl;
		}
		std::cout << std::endl;

		displayTitle2("Assigning value to out of bound index:\t");
		try
		{
			copy[12] = 12;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	
	std::cout << std::endl;	
	displayTitle0("\tTest with chars:\t");

		try
		{
			displayTitle1("Creating char array with default values");
			Array<char> truc(26);
			std::cout << truc << std::endl << std::endl;
			
			displayTitle1("Filling char array with new values");
			for (size_t i = 0; i < 26; i++)
				truc[i] = 'a' + i;
			std::cout << truc << std::endl << std::endl;
			
			displayTitle1("Trying to display in and out of bound value");
			std::cout << "In bound : " << truc[25] << std::endl;
			std::cout << "Out of bound : " << truc[26] << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << "!\n";
		}

	return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }