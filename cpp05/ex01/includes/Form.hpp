#ifndef DEF_FORM
#define DEF_FORM

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int requiredGradeSign, int requiredGradeExec);
		Form(Form const & src);
		virtual ~Form();

		Form & operator=(Form const & rhs);

		std::string const & getName() const;
		int			const & getRequiredGradeSign() const;
		int			const & getRequiredGradeExec() const;
		bool		const & getSignedBool() const;

		void beSigned(Bureaucrat const &employee);

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

std::ostream & operator<<( std::ostream & os, Form const & rhs);

#endif
