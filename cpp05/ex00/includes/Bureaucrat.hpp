#ifndef DEF_BUREAUCRAT
#define DEF_BUREAUCRAT

#include <iostream>
#include "Format.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const & getName() const;
		int const & getGrade() const;
		void setGrade(const int& grade);

		void incrementGrade();
		void decrementGrade();
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ ABORT : The grade you are trying to assign is too high ! Please enter a value in range 1 - 150." _END);
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return(_BOLD _YELLOW "⚠️ ABORT : The grade you are trying to assign is too low ! Please enter a value in range 1 - 150." _END);
				}
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream & operator<<( std::ostream & os, Bureaucrat const & rhs);

#endif
