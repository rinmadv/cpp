#include "../includes/PhoneBook.hpp"
#include <iostream>

void	PhoneBook::welcome()
{	
	std::string choice ;

	std::cout << "Welcome to your phonebook !" << std::endl;
	this->m_index = 0;
	while (1)
	{
		displayMenu();
		getline(std::cin, choice);
		std::cout << std::endl;
		if (choice == "ADD")
			add();
		else if (choice == "SEARCH")
			search();
		else if (choice == "EXIT")
		{
			goodBye();
			return ;
		}
		else
			error();
	}
}

void	PhoneBook::add()
{
	Contact	newContact;
	std::cout << &newContact << std::endl;
	m_List[this->m_index] = newContact;
	std::cout << &newContact << std::endl;
	newContact.add();
	this->m_index = (this->m_index + 1) % 8;
}

void	PhoneBook::displayMenu() const
{	
	std::cout <<"What would you like to do ? ?" << std::endl;
	std::cout <<"	[ADD] Add a new contact" << std::endl;
	std::cout <<"	[SEARCH] Display contacts list" << std::endl;
	std::cout <<"	[EXIT] Exit phonebook " << std::endl;
	std::cout <<"Your choice : ";
}

int	PhoneBook::goodBye() const
{	
	std::cout <<"See you soon !" << std::endl;
	return (0);
}

void	PhoneBook::error() const
{	
	std::cout <<"Invalid entry, please try again" << std::endl << std::endl;
}


void	PhoneBook::search() const
{
	Contact contact;

	std::cout <<"Here is the list of your contacts" << std::endl;
	std::cout << "     Index |  Firstname |   Lastname |   Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contact = this->m_List[i];
		std::cout << std::right << std::setw(10) << i << " | ";
		contact.displayOneShort();
	}
}
