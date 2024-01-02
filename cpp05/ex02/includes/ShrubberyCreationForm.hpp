#ifndef DEF_SHRUBBERYCREATIONFORM
#define DEF_SHRUBBERYCREATIONFORM

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : Public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(std::string name, int requiredGradeSign, int requiredGradeExec);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		virtual std::string const & getName() const = 0;
		virtual int			const & getRequiredGradeSign() const = 0;
		virtual int			const & getRequiredGradeExec() const = 0;
		virtual bool		const & getSignedBool() const = 0;

		virtual void beSigned(Bureaucrat const &employee) = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ Grade to high" _END);
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ Grade to low" _END);
				}
		};

	private:
		std::string const	_name;
		int					_requiredGradeSign;
		int					_requiredGradeExec;
		bool				_signed;

};

std::ostream & operator<<( std::ostream & os, ShrubberyCreationForm const & rhs);

#endif
