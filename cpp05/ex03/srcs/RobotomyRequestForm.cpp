#include "../includes/RobotomyRequestForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

RobotomyRequestForm::RobotomyRequestForm() :  AForm("RobotomyRequestForm", 72, 45) {std::cout << "📋 RobotomyRequestForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :  AForm("RobotomyRequestForm", 72, 45), _target(target) {std::cout << "📋 RobotomyRequestForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}

RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "🚮 RobotomyRequestForm " << this->getName() << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}



/*********** MEMBER FUNCTION ***********/

void RobotomyRequestForm::execute(Bureaucrat const & executor ) const
{
	std::cout << "📋 Form "  << this->getName() << " tries to get executed by " << executor.getName() << std::endl;
	if (!this->getSignedBool())
		throw RobotomyRequestForm::FormNotSignedException();
	
	if (executor.getGrade() > this->getRequiredGradeExec())
		throw RobotomyRequestForm::ExecGradeTooLowException();
	std::cout << "📋 Execution" << std::endl;
	std::cout << "Bzzzz zZZZZZZZZzzz BzzBZZZZZZZZZZZZZZ ... " << std::endl;
	
	std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random_number = std::rand();
	bool success = random_number & 1;
	if (success)
		std::cout << _BOLD _FOREST_GREEN  << _target << " has been robotomized sucessfully 🤖"_END << std::endl;
	else
		std::cout << _BOLD _RED << _target << " has not been robotomized sucessfully ❌" _END << std::endl; 

}

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, RobotomyRequestForm const & rhs)
{
	os << _CYAN _BOLD "ℹ️  RobotomyRequestForm Informations : " _END;
	os << "\n\tName : " << rhs.getName();
	os << "\n\tGrade required to sign : " << rhs.getRequiredGradeSign();
	os << "\n\tGrade required to execute : " << rhs.getRequiredGradeExec();
	os << "\n\tRobotomyRequestForm Signed : " << rhs.getSignedBool() << std::endl; //normalement je peux changer un truc pour traduire le bool
	return (os);
}
