#include "../includes/Intern.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Intern::Intern() {std::cout << "☕ Random intern gets hired but no one cares at Bureaucorp" << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}


Intern::Intern(Intern const & src)  throw()
{
	std::cout << _GREY _BOLD _ITALIC "Intern copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}
Intern::~Intern(){std::cout << "🤷‍♂️ " << "Random intern that no one cared at Bureaucorp got fired " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

Intern & Intern::operator=(Intern const & rhs)
{
	(void) rhs;
	std::cout << "☕ Random intern gets hired but no one cares at Bureaucorp " << _GREY _BOLD _ITALIC " (Assignation operator)" _END << std::endl;
	return (*this);
}

/*********** MEMBER FUNCTION ***********/

AForm	*Intern::makeShrubberyForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm		*Intern::makeRobotomyForm(std::string const & target)
{ 
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialForm(std::string const & target)
{ 
	return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(std::string const & name, std::string const & target) throw(UnknownForm)
{
	std::string type[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(*functions[3])(std::string const &) = { &Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm };

	for (int i = 0; i < 3; i++)
		if (name == type[i])
		{
			std::cout << "🖨️  Intern creates " << name << std::endl;
			return (functions[i](target));
		}
	throw UnknownForm();
}

/***************** NON MEMBERS ******************/

