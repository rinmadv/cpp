#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
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

	std::cout << _BOLD _PINK "Creation of the bureaucrats and the intern" _END << std::endl << std::endl;
	Bureaucrat	JeanMichel("Jean-Michel", 1);
	Bureaucrat	Josiane("Josiane", 5);
	Intern		Steve;
	Intern		Mike;

	std::cout << std::endl;

	std::cout << _BOLD _PINK "Intern tries to create forms" _END << std::endl << std::endl;
	try
	{
		AForm *SCF;
		SCF = Steve.makeForm("ShrubberyCreationForm", "target");
		std::cout << *SCF << std::endl;
		std::cout << std::endl;
		
		AForm *RRF;
		RRF = Steve.makeForm("RobotomyRequestForm", "home");
		std::cout << *RRF << std::endl;
		std::cout << std::endl;

		PresidentialPardonForm *PPF;
		PPF = (PresidentialPardonForm*)Steve.makeForm("PresidentialPardonForm", "Jon");
		std::cout << *PPF << std::endl;
		std::cout << std::endl;
		
		AForm *INVALID;
		INVALID = Steve.makeForm("kldsgnlz", "random_target");
		std::cout << *INVALID << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	PresidentialPardonForm *newPPF;
	newPPF = (PresidentialPardonForm*)Steve.makeForm("PresidentialPardonForm", "No one");
	std::cout << *newPPF << std::endl;
	newPPF->beSigned(Josiane);
	newPPF->execute(Josiane);
	std::cout << std::endl;

	AForm *newSCF;
	newSCF = (ShrubberyCreationForm*)Steve.makeForm("ShrubberyCreationForm", "Place");
	std::cout << *newSCF << std::endl;
	newSCF->beSigned(Josiane);
	newSCF->execute(Josiane);
	std::cout << std::endl;

	AForm *newRRF;
	newRRF = (RobotomyRequestForm*)Steve.makeForm("RobotomyRequestForm", "Karen");
	std::cout << *newRRF << std::endl;
	newRRF->beSigned(Josiane);
	newRRF->execute(Josiane);
	std::cout << std::endl;

	std::cout << _BOLD _BLINK "************************ THANKS FOR VISITING BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

}
