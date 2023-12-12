#include "../includes/Contact.hpp"
#include <string>

Contact::Contact(){}

Contact::~Contact(){}

bool	strisprint(std::string const field)
{
	size_t len = field.length();
	for (size_t i = 0; i < len; i++)
	{
		if (!isprint(field[i]))
			return (false);
	}
	return (true);
}

bool	Contact::addField(std::string &field, const std::string out)
{
	std::cout << out;
	
	getline(std::cin, field);
	while (field.empty() || !strisprint(field))
	{
		if (std::cin.eof())
			return (false);
		std::cout <<"Contact info cannot be empty nor contain any printable characters" << std::endl;
		std::cout << out;
		getline(std::cin, field);
	}
	return (true);
}

bool	Contact::add()
{
	if (!addField(m_firstName, "first name : ")
		|| !addField(m_lasttName, "last name : ")
		|| !addField(m_nickName, "nickname : ")
		|| !addField(m_phoneNumber, "phone number : ")
		|| !addField(m_darkestSecret, "darkest secret : "))
			return (std::cout << std::endl, false);
	return (true);
}

std::string getShort(std::string const & field)
{
	std::string shorten;

	if (field.size() <= 10)
		return (field);
	shorten = field.substr();
	shorten.resize(9);
	shorten.resize(10, '.');
	return (shorten);
}
void	Contact::displayOneShort()
{
	if (this->m_firstName.empty())
	{
		std::cout << std::left << std::setw(10) << " Empty" << " | ";
		std::cout << std::left << std::setw(10) << " " << " | ";
		std::cout << std::left << std::setw(10) << " "  << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << getShort(m_firstName)  << " | ";
	std::cout << std::right << std::setw(10) << getShort(m_lasttName) << " | ";
	std::cout << std::right << std::setw(10) << getShort(m_nickName)  << std::endl;
}

void	Contact::display()
{
	if (this->m_firstName.empty())
	{
		std::cout << "This contact is empty" << std::endl << std::endl;
		return ;
	}
	std::cout << "Firstname : " << m_firstName << std::endl;
	std::cout << "Lastname : " << m_lasttName << std::endl;
	std::cout << "Nickname : " << m_nickName << std::endl;
	std::cout << "Phone number : " << m_phoneNumber << std::endl;
	std::cout << "Darkest secret : " << m_darkestSecret << std::endl << std::endl;
}
