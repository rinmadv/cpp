#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(std::string name);
	~PhoneBook();

	void	welcome();
	void	display() const;
	void	goodBye() const;
	void	error() const;
	void	displayMenu() const;
	void	search();
	void	add();
	void	displayContact(std::string choice);

private:
	int		m_index;
	Contact	m_List[8];
	std::string _name;
};

#endif
