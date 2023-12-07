#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	welcome();
	void	display() const;
	int		goodBye() const;
	void	error() const;
	void	displayMenu() const;
	void	search();
	void	add();

private:
	int		m_index;
	Contact	m_List[8];
};

#endif
