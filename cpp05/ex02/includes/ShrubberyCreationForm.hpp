#ifndef DEF_SHRUBBERYCREATIONFORM
#define DEF_SHRUBBERYCREATIONFORM

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(std::string name, int requiredGradeSign, int requiredGradeExec);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	private:
};

std::ostream & operator<<( std::ostream & os, ShrubberyCreationForm const & rhs);

#endif
