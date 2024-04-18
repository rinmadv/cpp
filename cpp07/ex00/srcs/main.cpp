#include <iostream>
#include "../includes/Whatever.hpp"
#include "../includes/Format.hpp"

int main( void )
{
	std::cout << _PINK _BOLD  "********** TEST WITH INT **********" _END << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	
	std::cout << _PINK _BOLD  "********** TEST WITH STRING **********" _END << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;
	
	std::cout << _PINK _BOLD  "********** TEST WITH CHAR **********" _END << std::endl;

	char truc = 'e';
	char much = 'f';
	::swap(truc, much);
	std::cout << "truc = " << truc << ", much = " << much << std::endl;
	std::cout << "min( e, f ) = " << ::min( truc, much ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( truc, much ) << std::endl << std::endl;
	
	return 0;
}