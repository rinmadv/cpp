#ifndef DEF_Intern
#define DEF_Intern

#include <iostream>
#include "Format.hpp"
#include "AForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		~Intern();

		Intern & operator=(Intern const & rhs);

		AForm *makeForm(std::string const & name, std::string const & target);
	private:
		std::string levels[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

};


#endif
