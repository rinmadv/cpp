#include "../includes/Contact.hpp"



void	Contact::addField(std::string field, const std::string out)
{
	std::cout << out;
	
	getline(std::cin, field);
	while (field.empty())
	{
		std::cout <<"Contact info cannot be empty" << std::endl;
		std::cout << out;
		getline(std::cin, field);
	}
}

void	Contact::add()
{
	std::cout << m_firstName << std::endl;
	addField(m_firstName, "first name : ");
	std::cout << m_firstName << std::endl;

	std::cout << m_lasttName << std::endl;
	addField(m_lasttName, "last name : ");  
	std::cout << m_lasttName << std::endl;

	std::cout << m_nickName << std::endl;
	addField(m_nickName, "nickname : ");
	std::cout << m_nickName << std::endl;

	std::cout << m_phoneNumber << std::endl;
	addField(m_phoneNumber, "phone number : ");
	std::cout << m_phoneNumber << std::endl;

	std::cout << m_darkestSecret << std::endl;
	addField(m_darkestSecret, "darkest secret : ");
	std::cout << m_darkestSecret << std::endl;

}


void	Contact::displayOneShort() const
{
	std::cout << std::right << std::setw(10) << m_firstName << " | ";
	std::cout << std::right << std::setw(10) << m_lasttName << " | ";
	std::cout << std::right << std::setw(10) << m_nickName<< " | "  << std::endl;
}