#include "../includes/ShrubberyCreationForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :  AForm("Untitled", 145, 137), _target(target) {std::cout << "📋 ShrubberyCreationForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}



ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "🚮 ShrubberyCreationForm " << this->getName() << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}



/*********** MEMBER FUNCTION ***********/

void ShrubberyCreationForm::execute(Bureaucrat const & executor ) const
{
	std::cout << "📋 Form "  << this->getName() << " tries to get executed by " << executor.getName() << std::endl;
	if (!this->getSignedBool())
		throw ShrubberyCreationForm::FormNotSignedException();
	
	if (executor.getGrade() > this->getRequiredGradeExec())
		throw ShrubberyCreationForm::ExecGradeTooLowException();
	std::cout << "📋 Execution" << std::endl;
	std::string outfileName = _target + "_shrubbery";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open())
		std::cerr << "Error : cannot open or create " << outfileName << std::endl;
	outfile << "               ,@@@@@@@," << std::endl << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88/'" << std::endl << "   %&&%&%&/%&&%@@/@@/ /@@@88888\\88888'" << std::endl << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl << "   `&%\\ ` /%&'    |.|        \\ '|8\'" << std::endl << "       |o|        | |         | |" << std::endl << "       |.|        | |         | |" << std::endl << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, ShrubberyCreationForm const & rhs)
{
	os << _CYAN _BOLD "ℹ️  ShrubberyCreationForm InShrubberyCreationFormations : " _END;
	os << "\n\tName : " << rhs.getName();
	os << "\n\tGrade required to sign : " << rhs.getRequiredGradeSign();
	os << "\n\tGrade required to execute : " << rhs.getRequiredGradeExec();
	os << "\n\tShrubberyCreationForm Signed : " << rhs.getSignedBool() << std::endl; //normalement je peux changer un truc pour traduire le bool
	return (os);
}
