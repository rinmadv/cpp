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
	void	clear();
	void	addField(std::string field, const std::string out);

	//supprimer un contact

	private:
	std::string m_firstName;
	std::string m_lasttName;
	std::string m_nickName;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;
};

#endif
