#ifndef DEF_CONTACT
#define DEF_CONTACT

#include <iostream>
#include <iomanip>

class Contact
{
public:
	Contact();
	~Contact();

	bool	addField(std::string &field, const std::string out);
	bool	add();
	void	displayOneShort();
	void	display();


private:
	std::string _firstName;
	std::string _lasttName;
	std::string _nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};


#endif
