#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
	//fonctions
	//add constructeur
	//add destructeur
	void	welcome() const;
	void	display() const;
	int		goodBye() const;
	void	error() const;
	void	displayMenu() const;
	void	displayList() const;
	void	displayListMore() const;
	void	displayOneLong(std::string index) const;
	void	add();
	void	remove();

	private:
	Contact	m_List[8];
};

#endif
