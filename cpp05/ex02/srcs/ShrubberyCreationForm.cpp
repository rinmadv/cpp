#include "../includes/ShrubberyCreationForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("Untitled", 145, 137) {std::cout << "📋 ShrubberyCreationForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 1, 1) {std::cout << "📋 ShrubberyCreationForm " << this->getName() << " gets created " << _GREY _BOLD _ITALIC " (Parametric constructor, name but default grades)" _END << std::endl;}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int requiredGradeSign, int requiredGradeExec) : AForm(name, requiredGradeSign, requiredGradeExec)
{
	std::cout << "📋 ShrubberyCreationForm "  << this->getName() << " tries to get created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
	std::cout << "📋 ShrubberyCreationForm "  << this->getName() << " gets created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm()
{
	std::cout << _GREY _BOLD _ITALIC "ShrubberyCreationForm copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "🚮 ShrubberyCreationForm " << this->getName() << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void) rhs;
	std::cout << "📋 ShrubberyCreationForm "  << this->getName() << " gets created with required signing grade " << this->getRequiredGradeSign() << " and " << this->getRequiredGradeExec() << _GREY _BOLD _ITALIC " (Assignation operator)" _END  << std::endl;
	return (*this);
}


/*********** MEMBER FUNCTION ***********/

// void ShrubberyCreationForm::beSigned(Bureaucrat const &employee)
// {
// 	std::cout << "✍️ " << employee.getName() << " tries to sign ShrubberyCreationForm " << this->_name << std::endl;
// 	if (employee.getGrade() > this->getRequiredGradeSign())
// 		throw GradeTooLowException();
// 	this->_signed = true;
// 	std::cout << "✅ ShrubberyCreationForm" << this->_name << " signed by " << employee.getName() << std::endl;
// }

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
