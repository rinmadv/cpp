#include "../includes/Form.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Form::Form() : _name("Untitled"), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 Form " << this->_name << " gets created"  << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}
Form::Form(std::string name) : _name(name), _requiredGradeSign(1), _requiredGradeExec(1), _signed(false) {std::cout << "📋 Form " << this->_name << " gets created " << _GREY _BOLD _ITALIC " (Parametric constructor, name but default grades)" _END << std::endl;}
Form::Form(std::string name, int requiredGradeSign, int requiredGradeExec) : _name(name)
{
	std::cout << "📋 Form "  << this->_name << " tries to get created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
	if (requiredGradeSign > 150 || requiredGradeExec > 150)
		throw Form::GradeTooLowException();
	else if (requiredGradeSign < 1 || requiredGradeExec < 1)
		throw Form::GradeTooHighException();
	this->_requiredGradeSign = requiredGradeSign;
	this->_requiredGradeExec = requiredGradeExec;
	std::cout << "📋 Form "  << this->_name << " gets created with required signing grade " << requiredGradeSign << " and " << requiredGradeExec << _GREY _BOLD _ITALIC " (Parametric constructor)" _END  << std::endl;
}

Form::Form(Form const & src) : _name(src._name)
{
	std::cout << _GREY _BOLD _ITALIC "Form copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}

Form::~Form(){std::cout << "🚮 Form " << this->_name << " got deleted oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

Form & Form::operator=(Form const & rhs)
{
	this->_requiredGradeSign = rhs._requiredGradeSign;
	this->_requiredGradeExec = rhs._requiredGradeExec;
	this->_signed = rhs._signed;
	std::cout << "📋 Form "  << this->_name << " gets created with required signing grade " << _requiredGradeSign << " and " << _requiredGradeExec << _GREY _BOLD _ITALIC " (Assignation operator)" _END  << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const & Form::getName() const
{
	return(this->_name);
}

int const & Form::getRequiredGradeSign() const
{
	return(this->_requiredGradeSign);
}

int const & Form::getRequiredGradeExec() const
{
	return(this->_requiredGradeExec);
}

bool const & Form::getSignedBool() const
{
	return(this->_signed);
}

/*********** MEMBER FUNCTION ***********/

void Form::beSigned(Bureaucrat const &employee)
{
	std::cout << "✍️ " << employee.getName() << " tries to sign form " << this->_name << std::endl;
	if (employee.getGrade() > this->getRequiredGradeSign())
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << "✅ Form" << this->_name << " signed by " << employee.getName() << std::endl;
}

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, Form const & rhs)
{
	os << _CYAN _BOLD "ℹ️  Form Informations : " _END;
	os << "\n\tName : " << rhs.getName();
	os << "\n\tGrade required to sign : " << rhs.getRequiredGradeSign();
	os << "\n\tGrade required to execute : " << rhs.getRequiredGradeExec();
	os << "\n\tForm Signed : " << rhs.getSignedBool() << std::endl; //normalement je peux changer un truc pour traduire le bool
	return (os);
}
