#ifndef DEF_AFORM
#define DEF_AFORM

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int requiredGradeSign, int requiredGradeExec);
		AForm(AForm const & src);
		virtual ~AForm();

		AForm & operator=(AForm const & rhs);

		std::string const & getName() const;
		int			const & getRequiredGradeSign() const;
		int			const & getRequiredGradeExec() const;
		bool		const & getSignedBool() const;
		virtual void execute(Bureaucrat const & executor ) const = 0;

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

std::ostream & operator<<( std::ostream & os, AForm const & rhs);

#endif
