#include "../includes/Bureaucrat.hpp"
#include "../includes/Format.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <limits.h>
#include <iostream>
#include <string>

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
		ShrubberyCreationForm Cerfa612F("Cerfa612F");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm Cerfa615F("Cerfa615F");
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
	ShrubberyCreationForm Mdr = Template;
	std::cout << Mdr << std::endl;
	std::cout << Template << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Signing & execution tests" _END << std::endl << std::endl;
	try
	{
		JeanMichel.signForm(&Cerfa126A);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Josiane.signForm(&Cerfa123A);
		Cerfa123A.beSigned(Josiane);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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
	try
	{
		Template.beSigned(Josiane);
		Template.execute(Josiane);
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
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Getters (agaiiin)" _END << std::endl << std::endl;
	std::cout << Cerfa123A << std::endl;
	std::cout << Template << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _BLINK "************************ THANKS FOR VISITING BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

}
