#include "../includes/ShrubberyCreationForm.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("Untitled", 145, 137) {std::cout << "📋 ShrubberyCreationForm " << this->getName() << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}


ShrubberyCreationForm::ShrubberyCreationForm() :  name("Untitled"), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 ShrubberyCreationForm " << this->_name << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : _name(name), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 ShrubberyCreationForm " << this->_name << " gets created " << _GREY _BOLD _ITALIC " (Parametric constructor, name but default grades)" _END << std::endl;}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int requiredGradeSign, int requiredGradeExec) : _name(name)
{
	std::cout << "📋 ShrubberyCreationForm "  << this->_name << " tries to get created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
	if (requiredGradeSign > 150 || requiredGradeExec > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (requiredGradeSign < 1 || requiredGradeExec < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	this->_requiredGradeSign = requiredGradeSign;
	this->_requiredGradeExec = requiredGradeExec;
	std::cout << "📋 ShrubberyCreationForm "  << this->_name << " gets created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : _name(src._name)
{
	std::cout << _GREY _BOLD _ITALIC "ShrubberyCreationForm copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "🚮 ShrubberyCreationForm " << this->_name << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	this->_requiredGradeSign = rhs._requiredGradeSign;
	this->_requiredGradeExec = rhs._requiredGradeExec;
	this->_signed = rhs._signed;
	std::cout << "📋 ShrubberyCreationForm "  << this->_name << " gets created with required signing grade " << _requiredGradeSign << " and " << _requiredGradeExec << _GREY _BOLD _ITALIC " (Assignation operator)" _END  << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

// std::string const & ShrubberyCreationForm::getName() const
// {
// 	return(this->_name);
// }

// int const & ShrubberyCreationForm::getRequiredGradeSign() const
// {
// 	return(this->_requiredGradeSign);
// }

// int const & ShrubberyCreationForm::getRequiredGradeExec() const
// {
// 	return(this->_requiredGradeExec);
// }

// bool const & ShrubberyCreationForm::getSignedBool() const
// {
// 	return(this->_signed);
// }

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
