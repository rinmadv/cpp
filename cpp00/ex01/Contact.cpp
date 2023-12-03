#include "Contact.hpp"
#include <iostream>

	//add constructeur
	//add destructeur

void	Contact::clear()
{
	if (this->m_firstName[0])
		this->m_firstName.clear();
	if (this->m_lasttName[0])
		this->m_lasttName.clear();
	if (this->m_nickName[0])
		this->m_nickName.clear();
	if (this->m_phoneNumber[0])
		this->m_phoneNumber.clear();
	if (this->m_darkestSecret[0])
		this->m_darkestSecret.clear();
}

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
	this->addField(m_firstName, "first name : ");
	this->addField(m_lasttName, "last name : ");
	this->addField(m_nickName, "nickname : ");
	this->addField(m_phoneNumber, "phone number : ");
	this->addField(m_darkestSecret, "darkest secret : ");
}

void	Contact::displayOneLong() const
{
	std::cout << "Détail du contact" << std::endl;
	std::cout << m_firstName << " " << m_lasttName << std::endl;
	std::cout << m_phoneNumber << std::endl;
	std::cout << std::endl;
}

void	Contact::displayOneShort() const
{
	std::cout << m_firstName << " " << m_lasttName << std::endl;
}