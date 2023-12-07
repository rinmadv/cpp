#include "../includes/Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::addField(std::string &field, const std::string out)
{
	std::cout << out;
	
	getline(std::cin, field);//a proteger
	while (field.empty())
	{
		std::cout <<"Contact info cannot be empty" << std::endl;
		std::cout << out;
		getline(std::cin, field);
	}
}

void	Contact::add()
{
	addField(m_firstName, "first name : ");
	addField(m_lasttName, "last name : ");  
	addField(m_nickName, "nickname : ");
	addField(m_phoneNumber, "phone number : ");
	addField(m_darkestSecret, "darkest secret : ");
}


void	Contact::displayOneShort()
{
	std::cout << std::right << std::setw(10) << m_firstName << " | ";
	std::cout << std::right << std::setw(10) << m_lasttName << " | ";
	std::cout << std::right << std::setw(10) << m_nickName<< " | "  << std::endl;
}