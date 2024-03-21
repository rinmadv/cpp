#include "../includes/PresidentialPardonForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/
PresidentialPardonForm::PresidentialPardonForm() :  AForm("PresidentialPardonForm", 25, 5) {std::cout << "📋 PresidentialPardonForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :  AForm("PresidentialPardonForm", 25, 5), _target(target) {std::cout << "📋 PresidentialPardonForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}



PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "🚮 PresidentialPardonForm " << this->getName() << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}



/*********** MEMBER FUNCTION ***********/

void PresidentialPardonForm::execute(Bureaucrat const & executor ) const
{
	std::cout << "📋 Form "  << this->getName() << " tries to get executed by " << executor.getName() << std::endl;
	if (!this->getSignedBool())
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > this->getRequiredGradeExec())
		throw PresidentialPardonForm::ExecGradeTooLowException();
	std::cout << "📋 Execution" << std::endl;
	std::cout << _BOLD _FOREST_GREEN _BLINK << _target << " has been pardoned by Zaphod Beeblebrox. 👑" _END << std::endl; 
}

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, PresidentialPardonForm const & rhs)
{
	os << _CYAN _BOLD "ℹ️  PresidentialPardonForm Informations : " _END;
	os << "\n\tName : " << rhs.getName();
	os << "\n\tGrade required to sign : " << rhs.getRequiredGradeSign();
	os << "\n\tGrade required to execute : " << rhs.getRequiredGradeExec();
	os << "\n\tPresidentialPardonForm Signed : " << rhs.getSignedBool() << std::endl; //normalement je peux changer un truc pour traduire le bool
	return (os);
}
