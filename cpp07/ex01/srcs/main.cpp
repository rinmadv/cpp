#include <iostream>
#include "../includes/Iter.hpp"
#include "../includes/Format.hpp"


int main( void )
{
	std::cout << _PINK _BOLD  "********** TEST WITH STRINGS ARRAY **********" _END << std::endl;
	std::string dwarfs[7] = {"Doc", "Grumpy", "Happy", "Sleepy", "Bashful", "Sneezy", "Dopey"};

	iter(dwarfs, 7, hello);
	std::cout << std::endl;
	iter(dwarfs, 7, toUpper);
	iter(dwarfs, 7, hello);
	std::cout << std::endl;
	
	std::cout << _PINK _BOLD  "********** TEST WITH CHARS **********" _END << std::endl;
	char letters[7] = {'h', 'e', 'l', 'l', 'o', ' ', '!'};

	iter(letters, 7, display);
	std::cout << std::endl;
	iter(letters, 7, toUpper);
	iter(letters, 7, display);
	std::cout << std::endl;

	std::cout << _PINK _BOLD  "********** TEST WITH INTS **********" _END << std::endl;
	int integers[7] = {12, 13, INT_MAX, INT_MIN, 0, -5, -9};

	iter(integers, 7, display);
	std::cout << std::endl;
	iter(integers, 7, increment);
	iter(integers, 7, display);
	std::cout << std::endl;

	iter(letters, 7, display);
	std::cout << std::endl;
	iter(letters, 7, increment);
	iter(letters, 7, display);
	std::cout << std::endl;

	return 0;
}