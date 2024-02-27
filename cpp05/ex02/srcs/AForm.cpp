#include "../includes/AForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

AForm::AForm() : _name("Untitled"), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 AForm " << this->_name << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}
AForm::AForm(std::string name) : _name(name), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 AForm " << this->_name << " gets created " << _GREY _BOLD _ITALIC " (Parametric constructor, name but default grades)" _END << std::endl;}
AForm::AForm(std::string name, int requiredGradeSign, int requiredGradeExec) : _name(name)
{
	std::cout << "📋 AForm "  << this->_name << " tries to get created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
	if (requiredGradeSign > 150 || requiredGradeExec > 150)
		throw AForm::GradeTooLowException();
	else if (requiredGradeSign < 1 || requiredGradeExec < 1)
		throw AForm::GradeTooHighException();
	this->_requiredGradeSign = requiredGradeSign;
	this->_requiredGradeExec = requiredGradeExec;
	std::cout << "📋 AForm "  << this->_name << " gets created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name)
{
	std::cout << _GREY _BOLD _ITALIC "AForm copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}

AForm::~AForm(){std::cout << "🚮 AForm " << this->_name << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

AForm & AForm::operator=(AForm const & rhs)
{
	this->_requiredGradeSign = rhs._requiredGradeSign;
	this->_requiredGradeExec = rhs._requiredGradeExec;
	this->_signed = rhs._signed;
	std::cout << "📋 AForm "  << this->_name << " gets created with required signing grade " << _requiredGradeSign << " and " << _requiredGradeExec << _GREY _BOLD _ITALIC " (Assignation operator)" _END  << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const & AForm::getName() const
{
	return(this->_name);
}

int const & AForm::getRequiredGradeSign() const
{
	return(this->_requiredGradeSign);
}

int const & AForm::getRequiredGradeExec() const
{
	return(this->_requiredGradeExec);
}

bool const & AForm::getSignedBool() const
{
	return(this->_signed);
}

/*********** MEMBER FUNCTION ***********/

// void AForm::beSigned(Bureaucrat const &employee)
// {
// 	std::cout << "✍️ " << employee.getName() << " tries to sign Aform " << this->_name << std::endl;
// 	if (employee.getGrade() > this->getRequiredGradeSign())
// 		throw GradeTooLowException();
// 	this->_signed = true;
// 	std::cout << "✅ AForm" << this->_name << " signed by " << employee.getName() << std::endl;
// }

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, AForm const & rhs)
{
	os << _CYAN _BOLD "ℹ️  AForm InAformations : " _END;
	os << "\n\tName : " << rhs.getName();
	os << "\n\tGrade required to sign : " << rhs.getRequiredGradeSign();
	os << "\n\tGrade required to execute : " << rhs.getRequiredGradeExec();
	os << "\n\tAForm Signed : " << rhs.getSignedBool() << std::endl; //normalement je peux changer un truc pour traduire le bool
	return (os);
}
