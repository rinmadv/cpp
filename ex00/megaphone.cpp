#include <iostream>
#include <sstream>
#include <string.h>

void ft_ToUpperCase(char* str)
{
	for (int i = 0; i < (int)strlen(str); i++)
		str[i] = std::toupper(str[i]);
	
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i = 1;
		while (argv[i])
		{
			ft_ToUpperCase(argv[i]);
			std::cout << argv[i];
				i++;
		}
		std::cout <<  "\n";
	}
	return (0);
}

//il faut encore splitter les argv
// puis trouver fonction qui met en majuscule
//cree convert to uppercase