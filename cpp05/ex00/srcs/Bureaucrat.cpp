#include "../includes/Bureaucrat.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Bureaucrat::Bureaucrat() : _name("Untitled Bureaucrat"), _grade(150) {std::cout << "💼 " << this->_name << " gets hired with grade " << this->_grade << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {std::cout << "💼 " << this->_name << " gets hired with grade " << this->_grade << _GREY _BOLD _ITALIC " (Parametric constructor, name but default grade)" _END << std::endl;}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
	std::cout << "💼 "  << this->_name << " gets hired with grade " << this->_grade << _GREY _BOLD _ITALIC " (Parameters constructor)" _END  << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
	std::cout << _GREY _BOLD _ITALIC "Copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}
Bureaucrat::~Bureaucrat(){std::cout << "😭 " << this->_name << " got fired oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs._grade;
	std::cout << "💼 "  << this->_name << " gets hired with grade " << this->_grade << _GREY _BOLD _ITALIC " (Assignation operator)" _END << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const & Bureaucrat::getName() const
{
	return(this->_name);
}

int const & Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::setGrade(const int& grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

/*********** MEMBER FUNCTION ***********/


void Bureaucrat::increment()
{
	if (this->_grade - 1 <= 0)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "📈 "  << this->_name << " grade's got incremented by 1 unit" << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->_grade + 1 >= 151)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "📉 "  << this->_name << " grade's got decremented by 1 unit" << std::endl;
}

/***************** NON MEMBERS ******************/

std::ostream & operator<<( std::ostream & os, Bureaucrat const & rhs)
{
	os << "ℹ️  " << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
