#include <iostream>
#include <sstream>
#include <vector>
// #include <utility>

# define _CYAN "\1\033[36m"
# define _FOREST_GREEN "\1\033[32m\2"
# define _BOLD "\1\033[1m\2"
# define _END "\1\033[0m\2"

int    displayMessage(std::string message)
{
	std::cout << message << _END << std::endl;
	return (0);
}


int puissanceDeDeux(int exponent) {
    int result = 1;
	if (exponent < 0)
	return (0);
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }
    return result;
}

void	tri(std::vector<int> &vec, int exp)
{
	if (vec.size() <= 1)
		return;
	
	std::cout << std::endl << _BOLD _CYAN << "Recursion level " << exp << _END << std::endl;
	std::cout << "size = " << vec.size() << std::endl;
	// std::cout << "exp = " << exp << std::endl << std::endl;
	// int pas = puissanceDeDeux(exp);
	// std::cout << "pas = " << pas << std::endl << std::endl;
	std::vector<int> rest;
	for (size_t i = 0; i < vec.size(); i += puissanceDeDeux(exp + 1))
	{
		if (i + puissanceDeDeux(exp) >= vec.size())
		{
			while (i < vec.size())
			{
				std::cout << "On stock vec[" << i << "] :" << vec[i] << std::endl;
				rest.push_back(vec[i]);
				vec.erase(vec.begin() + i);
			}
			break;
		}
		std::cout << "i =" << i << std::endl;
		std::cout << _FOREST_GREEN << "indice a = " << i + puissanceDeDeux(exp) - 1 << "\tvec [a] = " << vec[i + puissanceDeDeux(exp) -1] << _END << std::endl;
		if (i + exp < vec.size())
		{
			std::cout << _FOREST_GREEN << "indice b = " << i + puissanceDeDeux(exp + 1) - 1 << "\tvec [b] = " << vec[i + puissanceDeDeux(exp + 1) - 1] <<_END << std::endl;
			if (vec[puissanceDeDeux(exp - 1)] > vec[puissanceDeDeux(exp)])// exp bon
				std::swap(vec[puissanceDeDeux(exp - 1)], vec[puissanceDeDeux(exp)]); //attention aussi a ceux davant
		}
	}
	std::cout << _BOLD _CYAN "Envoye dans recursion" << _END << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _CYAN "Rest" << _END << std::endl;
	for (size_t i = 0; i < rest.size(); i++)
	{
		std::cout << rest[i] << " ";
	}
	std::cout << std::endl;
	//phase de recursion
	tri(vec, exp + 1);
	// for (size_t i = 0; i < rest.size(); i++)
	// {
	// 	vec.push_back(rest[i]);
	// }
	//ajouter la partie qui reste
		//rest.size et ensuite insertion avec la suite de jacobstal dans le vecteur
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"));

	//Parsing, mettre les arg dans un vecteur (a mettre dans une fonction + faire les verif)
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
	}

	//Affiche le vecteur avant tri
	std::cout << _BOLD _CYAN "Avant tri" << _END << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	//tri
	tri(vec, 0);

	//Affiche le vecteur apres tri
	std::cout << _BOLD _CYAN "Apres tri" << _END << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return (0);
}