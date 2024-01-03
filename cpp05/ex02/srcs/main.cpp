// #include "../includes/Bureaucrat.hpp"
#include <limits.h>
#include "../includes/Format.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << _TREE;
	return 0;
}

// int	main()
// {
// 	std::cout << std::endl << _BOLD _BLINK "************************ WELCOME TO BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

// 	std::cout << _BOLD _PINK "Creation of the bureaucrats" _END << std::endl << std::endl;
// 	Bureaucrat JeanMichel("Jean-Michel", 1);
// 	Bureaucrat Josiane("Josiane", 147);
	
// 	std::cout << std::endl;

// 	std::cout << _BOLD _PINK "Creation of forms" _END << std::endl << std::endl;
// 	try
// 	{
// 		Form Cerfa612F("CERFA 612F", 12, 2);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		Form Cerfa615G("CERFA 615G", 154, 56);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		Form Cerfa76526B("CERFA 76526B", 2, -6);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	Form Cerfa123A("CERFA 123A", 2, 16);
// 	Form Cerfa126A("CERFA 126A", 150, 150);
// 	Form Template("Template");
// 	Form Unknown;
// 	std::cout << std::endl;

// 	std::cout << _BOLD _PINK "Getters" _END << std::endl << std::endl;
// 	std::cout << Cerfa123A << std::endl;
// 	std::cout << Template << std::endl;
// 	std::cout << Unknown << std::endl;
// 	std::cout << std::endl;

// 	std::cout << _BOLD _PINK "Signing form tests" _END << std::endl << std::endl;
// 	try
// 	{
// 		JeanMichel.signForm(&Cerfa126A);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		Josiane.signForm(&Cerfa123A);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << std::endl;

// 	std::cout << _BOLD _PINK "Getters (agaiiin)" _END << std::endl << std::endl;
// 	std::cout << Cerfa123A << std::endl;
// 	std::cout << Template << std::endl;
// 	std::cout << Unknown << std::endl;
// 	std::cout << std::endl;

// 	std::cout << _BOLD _BLINK "************************ THANKS FOR VISITING BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

// }
