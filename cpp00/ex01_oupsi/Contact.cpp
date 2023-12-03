#include "Contact.hpp"
#include <iostream>

	//add constructeur
	//add destructeur
	
void	Contact::add()
{
	std::cout <<"Firstname : ";
	std::cin >> m_firstname;
		std::cout <<"Lasttname : ";
	std::cin >> m_lasttname;
	std::cout <<"Adress : ";
	std::cin >> m_adress;
	std::cout <<"Postcode : ";
	std::cin >> m_postcode;
	std::cout <<"Town : ";
	std::cin >> m_town;
	std::cout <<"Country : ";
	std::cin >> m_country;
}

void	Contact::displayOneLong() const
{
	std::cout << "Détail du contact" << std::endl;
	std::cout << m_firstname << " " << m_lasttname << std::endl;
	std::cout << m_phonenumber << std::endl;
	std::cout << m_adress << " " << m_postcode << std::endl;
	std::cout << m_town << " " << m_country << std::endl;
	std::cout << std::endl;
}

void	Contact::displayOneShort() const
{
	std::cout << m_firstname << " " << m_lasttname << std::endl;
}