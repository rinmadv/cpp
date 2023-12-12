#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : _index(0){}
PhoneBook::PhoneBook(std::string name) : _index(0), _name(name) {}
PhoneBook::~PhoneBook(){}

void	PhoneBook::welcome()
{	
	std::string choice ;

	std::cout << STARSLINE << std::endl << std::endl;
	std::cout << "Welcome to your phonebook " << this->_name << "!" << std::endl;
	this->_index = 0;
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
	this->_List[this->_index].add();
	this->_index = (this->_index + 1) % SIZE;
}

void	PhoneBook::displayMenu() const
{	
	std::cout << std::endl;
	std::cout <<"What would you like to do ?" << std::endl;
	std::cout <<"	[ADD] Add a new contact" << std::endl;
	std::cout <<"	[SEARCH] Display contacts list" << std::endl;
	std::cout <<"	[EXIT] Exit phonebook " << std::endl;
	std::cout <<"Your choice : ";
}

void	PhoneBook::goodBye() const
{	
	std::cout << "See you soon " << this->_name << "!" << std::endl;
	std::cout << std::endl << STARSLINE << std::endl;
	return;
}

void	PhoneBook::error() const
{	
	std::cout <<"Invalid entry, please try again" << std::endl << std::endl;
}

int	PhoneBook::getIndex(std::string choice)
{
	std::string tab[SIZE] = {"0", "1", "2", "3", "4", "5", "6", "7"};
	for (int i = 0; i < SIZE; i++)
	{
		if (!choice.compare(tab[i]))
			return (i);
	}
	return (-1);
}

void	PhoneBook::search()
{
	Contact *contact;
	std::string choice;
	std::cout <<"Here is the list of your contacts" << std::endl;
	std::cout << "     Index |  Firstname |   Lastname |   Nickname" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		contact = &this->_List[i];
		std::cout << std::right << std::setw(10) << i << " | ";
		contact->displayOneShort();
	}
	std::cout << "Which contact do you want to display (Press X to go back to menu): " ;
	std::getline(std::cin, choice);
	if (std::cin.eof())
		std::cout << std::endl;
	else if (choice == "X")
		return ;
	else
	{
		int i = this->getIndex(choice);
		if (i < 0)
		{
			std::cout << "Wrong index" << std::endl;
			return;
		}
		contact = &this->_List[i];
		contact->display();
	}
		
}
