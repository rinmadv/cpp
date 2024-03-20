#include "../includes/Intern.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Intern::Intern() : {std::cout << "💼 Random intern gets hired but no one cares at Bureaucorp" << _GREY _BOLD _ITALIC " (default constructor)" _END << std::endl;}


Intern::Intern(Intern const & src)
{
	std::cout << _GREY _BOLD _ITALIC "Intern copy constructor get called, calling assignation operator" _END << std::endl;
	*this = src;
}
Intern::~Intern(){std::cout << "😭 " << "Random intern that no one cared at Bureaucorp got fired oupsi " <<  _GREY _BOLD _ITALIC "(Destructor)" _END << std::endl;}

Intern & Intern::operator=(Intern const & rhs)
{
	std::cout << "💼 Random intern gets hired but no one cares at Bureaucorp " << _GREY _BOLD _ITALIC " (Assignation operator)" _END << std::endl;
	return (*this);
}

/*********** MEMBER FUNCTION ***********/

AForm *Intern::makeForm(std::string const & name, std::string const & target)
{

}

// void	Intern::signForm(AForm *form) const
// {
// 	try
// 	{
// 		form->beSigned(*this);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << this->_name << " couldn’t sign " << form->getName() << " because " << e.what() << '\n';
// 		return ;
// 	}
// 	std::cout << this->_name << " signed " << form->getName() << '\n';
// //pas bon !!
	
// }

/***************** NON MEMBERS ******************/

