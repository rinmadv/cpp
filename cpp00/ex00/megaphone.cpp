#include <iostream>
#include <string.h>
#include <locale>

#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	std::locale loc;
	std::string str;

	if (argc == 1)
		return (std::cout << NOISE << std::endl, 0);

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << std::toupper(str.at(j), loc);
	}
	std::cout << std::endl;

	return (0);
}
