#include <iostream>
#include "templates.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	Templates::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Templates::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Templates::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	Templates::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Templates::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Templates::max( c, d ) << std::endl;
	return 0;
}