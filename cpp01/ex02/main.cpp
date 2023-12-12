#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Adresse de str: "  << &str << std::endl;
	std::cout << "Adresse stockée dans stringPTR: "  << stringPTR << std::endl;
	std::cout << "Adresse stockée dans stringREF: "  << &stringREF << std::endl;

	std::cout << "Valeur de str: "  << str << std::endl;
	std::cout << "Valeur pointée par stringPTR: "  << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF: "  << stringREF << std::endl;
}