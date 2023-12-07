#include <iostream>
#include <sstream>
#include <string.h>


//truc de local d'abdel

static std::string toUpperStr(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]); //utiliser le toupper de locale
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

//changer, mettre argv[x] en string et utiliser la methode