#ifndef DEF_PresidentialPardonForm
#define DEF_PresidentialPardonForm

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor ) const;

		class ExecGradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ Executor grade is to low to execute form" _END);
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ Form cannot be executed as it is not signed" _END);
				}
		};
	private:
		std::string _target;
};

std::ostream & operator<<( std::ostream & os, PresidentialPardonForm const & rhs);

#endif
