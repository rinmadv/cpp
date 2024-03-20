#include "../includes/Bureaucrat.hpp"
#include "../includes/Format.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <limits.h>
#include <iostream>
#include <string>

// int main(void)
// {
	

	// std::cout << _TREE;
// 	return 0;
// }

int	main()
{
	std::cout << std::endl << _BOLD _BLINK "************************ WELCOME TO BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

	std::cout << _BOLD _PINK "Creation of the bureaucrats" _END << std::endl << std::endl;
	Bureaucrat JeanMichel("Jean-Michel", 1);
	Bureaucrat Josiane("Josiane", 5);
	
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Creation of forms" _END << std::endl << std::endl;
	try
	{
		ShrubberyCreationForm Cerfa612F("kk");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm Cerfa612F("kk");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm Cerfa612F("ptdr");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ShrubberyCreationForm Cerfa123A("CERFA 123A");
	RobotomyRequestForm Cerfa126A("ohhhh");
	PresidentialPardonForm Cerfa127C("Josie");
	ShrubberyCreationForm Template("Template");
	std::cout << std::endl;
	
	try
	{
		Cerfa126A.execute(JeanMichel);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Cerfa127C.beSigned(Josiane);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		Cerfa127C.execute(Josiane);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat Michelle("Michelle", 2);
	Michelle.executeForm(Cerfa127C);
	std::cout << _BOLD _PINK "Getters" _END << std::endl << std::endl;
	std::cout << Cerfa123A << std::endl;
	std::cout << Template << std::endl;
	std::cout << std::endl;

	// std::cout << _BOLD _PINK "Signing form tests" _END << std::endl << std::endl;
	// try
	// {
	// 	JeanMichel.signForm(&Cerfa126A);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	Josiane.signForm(&Cerfa123A);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Getters (agaiiin)" _END << std::endl << std::endl;
	std::cout << Cerfa123A << std::endl;
	std::cout << Template << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _BLINK "************************ THANKS FOR VISITING BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

}
