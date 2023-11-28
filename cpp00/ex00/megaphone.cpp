#include <iostream>
#include <sstream>
#include <string.h>

static std::string toUpperStr(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	return(str);
}
int	main(int argc, char **argv)
{
	int i = 1;
	std::string str;

	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			str = toUpperStr(argv[i]);
			std::cout << str;
				i++;
		}
		std::cout <<  "\n";
	}
	return (0);
}