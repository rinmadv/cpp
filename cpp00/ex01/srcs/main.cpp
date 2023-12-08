#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string name;

	if (argc != 1)
		name = argv[1];
	else
		name = "";
	PhoneBook book(name);
	book.welcome();
	return 0;
}
