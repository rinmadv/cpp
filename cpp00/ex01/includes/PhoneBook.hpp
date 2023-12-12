#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include "Contact.hpp"

#define SIZE 8
#define STARSLINE "*****************************************************************"
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
	// void	displayContact(std::string choice);
	int		getIndex(std::string choice);

private:
	int		_index;
	Contact	_List[8];
	std::string _name;
};

#endif
