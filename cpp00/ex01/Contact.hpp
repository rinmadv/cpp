#ifndef DEF_CONTACT
#define DEF_CONTACT

#include <string>

class Contact
{
	public:

	//add constructeur
	//add destructeur
	void	displayOneLong() const;
	void	displayOneShort() const;
	void	add();

	//supprimer un contact

	private:
	std::string m_firstname;
	std::string m_lasttname;
	std::string m_nickname;
	std::string	m_phonenumber;
	std::string	m_adress;
	std::string	m_postcode;
	std::string	m_town;
	std::string m_country;
};

#endif
