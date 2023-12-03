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
	void	welcome();
	void	display() const;
	int		goodBye() const;
	void	error() const;
	void	displayMenu() const;
	void	search() const;
	void	searchMore() const;
	void	displayOneLong(std::string index) const;
	void	add();
	void	remove();

	private:
	int		m_index;
	Contact	m_List[8];
};

#endif
