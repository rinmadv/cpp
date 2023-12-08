#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : m_index(0){}
PhoneBook::PhoneBook(std::string name) : m_index(0), _name(name) {}
PhoneBook::~PhoneBook(){}

void	PhoneBook::welcome()
{	
	std::string choice ;

	std::cout << "Welcome to your phonebook " << this->_name << "!" << std::endl;
	this->m_index = 0;
	while (std::cin)
	{
		displayMenu();
		std::getline(std::cin, choice);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}	
		if (choice == "EXIT")
			break;
		else if (choice == "ADD")
			add();
		else if (choice == "SEARCH")
			search();
		else
			error();
	}
	goodBye();
}

void	PhoneBook::add()
{
	this->m_List[this->m_index].add();
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

void	PhoneBook::goodBye() const
{	
	std::cout << "See you soon " << this->_name << "!" << std::endl;
	return;
}

void	PhoneBook::error() const
{	
	std::cout <<"Invalid entry, please try again" << std::endl << std::endl;
}

void	PhoneBook::displayContact(std::string choice)
{
	int index = std::stoi(choice);
	this->m_List[index].display();
}

void	PhoneBook::search()
{
	Contact *contact;
	std::string choice;
	std::cout <<"Here is the list of your contacts" << std::endl;
	std::cout << "     Index |  Firstname |   Lastname |   Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contact = &this->m_List[i];
		std::cout << std::right << std::setw(10) << i << " | ";
		contact->displayOneShort();
	}
	std::cout << "Which contact do you want to display (Press X to go back to menu): " ;
	std::getline(std::cin, choice);
	while (std::cin)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		else if (choice == "X")
			break ;
		else if (choice == "0" || choice == "1" || choice == "2" || choice == "3"
			|| choice == "4" || choice == "5" || choice == "6" || choice == "7")
		{
			
			break;
		}
		std::cout << "Wrong index\nWhich contact do you want to display (Press X to go back to menu): ";
		std::getline(std::cin, choice);
	}
		
}
