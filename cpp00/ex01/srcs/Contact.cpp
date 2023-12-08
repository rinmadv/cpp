#include "../includes/Contact.hpp"

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


void	Contact::displayOneShort()
{
	std::cout << std::right << std::setw(10) << m_firstName << " | ";
	std::cout << std::right << std::setw(10) << m_lasttName << " | ";
	std::cout << std::right << std::setw(10) << m_nickName<< " | "  << std::endl;
}