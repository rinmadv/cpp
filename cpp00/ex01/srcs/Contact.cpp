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
	if (!addField(_firstName, "first name : ")
		|| !addField(_lasttName, "last name : ")
		|| !addField(_nickName, "nickname : ")
		|| !addField(_phoneNumber, "phone number : ")
		|| !addField(_darkestSecret, "darkest secret : "))
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
	if (this->_firstName.empty())
	{
		std::cout << std::left << std::setw(10) << " Empty" << " | ";
		std::cout << std::left << std::setw(10) << " " << " | ";
		std::cout << std::left << std::setw(10) << " "  << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << getShort(_firstName)  << " | ";
	std::cout << std::right << std::setw(10) << getShort(_lasttName) << " | ";
	std::cout << std::right << std::setw(10) << getShort(_nickName)  << std::endl;
}

void	Contact::display()
{
	if (this->_firstName.empty())
	{
		std::cout << "This contact is empty" << std::endl << std::endl;
		return ;
	}
	std::cout << "Firstname : " << _firstName << std::endl;
	std::cout << "Lastname : " << _lasttName << std::endl;
	std::cout << "Nickname : " << _nickName << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Darkest secret : " << _darkestSecret << std::endl << std::endl;
}
