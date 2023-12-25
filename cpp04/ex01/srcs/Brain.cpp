#include "../includes/Brain.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Brain::Brain()
{
	std::cout << "Brain default constructor get called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	for (int i = 0; i < IDEASSIZE; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain copy constructor get called" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructor get called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	for (int i = 0; i < IDEASSIZE; i++)
		this->_ideas[i] = rhs._ideas[i];
	std::cout << "Brain assignation operator get called" << std::endl;
	return (*this);
}

/*********** SETTER / GETTER ***********/

std::string const& Brain::getIdea(const int id) const
{
	return (this->_ideas[id]);
}

void Brain::setIdea(const int id, const std::string& idea)
{
	this->_ideas[id] = idea;
}
