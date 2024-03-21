#include "../includes/Bureaucrat.hpp"
#include <limits.h>


int	main()
{
	std::cout << std::endl << _BOLD _BLINK "************************ WELCOME TO BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

	std::cout << _BOLD _PINK "Creation of the bureaucrats" _END << std::endl << std::endl;
	try
	{
		Bureaucrat Frank("Frank", 156);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat JeanLouis("JL", 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat JeanMichel("Jean-Michel", 1);
	Bureaucrat Josiane("Josiane", 147);
	Bureaucrat Claude("Claude");
	Bureaucrat Karen("Karen");
	Bureaucrat MarieJo("Marie-Jo");
	Bureaucrat Robert("Robert");
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Setters and exception tests" _END << std::endl << std::endl;
	std::cout << JeanMichel << std::endl;
	try
	{
		JeanMichel.setGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << JeanMichel << std::endl;
	std::cout << std::endl;

	std::cout << Claude << std::endl;
	try
	{
		Claude.setGrade(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Claude << std::endl;
	std::cout << std::endl;
	
	std::cout << Karen << std::endl;
	try
	{
		Karen.setGrade(151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Karen << std::endl;
	std::cout << std::endl;

	std::cout << MarieJo << std::endl;
	try
	{
		MarieJo.setGrade(-10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << MarieJo << std::endl;
	std::cout << std::endl;

	std::cout << Robert << std::endl;
	try
	{
		Robert.setGrade(INT_MAX);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Robert << std::endl;
	std::cout << std::endl;

		std::cout << Robert << std::endl;
	try
	{
		Robert.setGrade((int)'d');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Robert << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _PINK "Getters" _END << std::endl << std::endl;
	std::cout << JeanMichel << std::endl;
	std::cout << Josiane << std::endl;
	std::cout << Claude << std::endl;
	std::cout << Karen << std::endl;
	std::cout << MarieJo << std::endl;
	std::cout << Robert << std::endl;
	std::cout << std::endl;
	
	std::cout << _BOLD _PINK "Incrementation and decrementations tests" _END << std::endl << std::endl;
	try
	{
		JeanMichel.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << JeanMichel << std::endl;
	try
	{
		Josiane.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Josiane.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Josiane << std::endl;
	try
	{
		Karen.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Karen << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _BLINK "************************ THANKS FOR VISITING BUREAUCRATCORP ************************"  _END << std::endl << std::endl;

}
