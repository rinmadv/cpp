#ifndef DEF_Intern
#define DEF_Intern

#include <iostream>
#include "Format.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const & src)  throw();

		Intern & operator=(Intern const & rhs);

		class UnknownForm : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ Error : The form you are trying to create does not exist" _END);
				}
		};
	
		static AForm	*makeShrubberyForm(std::string const & target);
		static AForm	*makeRobotomyForm(std::string const & target);
		static AForm	*makePresidentialForm(std::string const & target);

		AForm	*makeForm(std::string const & name, std::string const & target) throw(UnknownForm);
	private:
};


#endif
