#ifndef DEF_CONTACT
#define DEF_CONTACT

#include <string>
#include <iostream>
#include <deque>
#include <iomanip>
#include <iostream>

class Contact
{
	public:

	void	displayOneShort() const;
	void	addField(std::string field, const std::string out);
	void	add();
	void	display();

	private:
	std::string m_firstName;
	std::string m_lasttName;
	std::string m_nickName;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;
};

#endif
