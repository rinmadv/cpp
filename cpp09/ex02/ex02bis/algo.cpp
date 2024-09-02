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


size_t puissanceDeDeux(int exponent) {
    size_t result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }
    return result;
}

void	tri(std::vector<int> &vec, int exp)
{
	//checker si le truc nest pas deja trie

	std::cout << std::endl << _BOLD _CYAN << "Recursion level " << exp << _END << std::endl;
	if (puissanceDeDeux(exp + 1) > vec.size())
	{
		std::cout << "eh bah non" << std::endl;
		return;
	}
	
	std::cout << "size = " << vec.size() << std::endl;
	// std::cout << "exp = " << exp << std::endl << std::endl;
	// int pas = puissanceDeDeux(exp);
	// std::cout << "pas = " << pas << std::endl << std::endl;
	// std::vector<int> rest;
	for (size_t i = 0; i < vec.size(); i += puissanceDeDeux(exp + 1))
	{
		// if (i + puissanceDeDeux(exp + 1) -1  >= vec.size()) //a checker
		// {
		// 	while (i < vec.size())
		// 	{
		// 		std::cout << "On stock vec[" << i << "] :" << vec[i] << std::endl;
		// 		rest.push_back(vec[i]);
		// 		vec.erase(vec.begin() + i);
		// 	}
		// 	break;
		// }

		std::cout << "i =" << i << std::endl;
		size_t indice_a = i + puissanceDeDeux(exp) - 1;
		size_t indice_b = i + puissanceDeDeux(exp + 1) -1;

		std::cout << _FOREST_GREEN << "comp a : vec[" << indice_a << "] = " << vec[indice_a] << _END << std::endl;
		if (indice_b < vec.size())
		{
			std::cout << _FOREST_GREEN << "comp b : vec[" << indice_b << "] = " << vec[indice_b] <<_END << std::endl;
			if (vec[i + puissanceDeDeux(exp) -1] > vec[i + puissanceDeDeux(exp + 1) - 1])// exp bon
			{
				std::cout << "On doit les swap" << std::endl;
				for (size_t k = 0; k <= puissanceDeDeux(exp) - 1; k++)
				{
					std::cout << "swap vec[" << indice_a - k << "] avec vec[" << indice_b - k << "]" << std::endl;
					std::swap(vec[indice_a - k], vec[indice_b - k]); //attention aussi a ceux davant
				}
			}

		}
	}
	std::cout << _BOLD _CYAN "Envoye dans recursion" << _END << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// std::cout << _BOLD _CYAN "Rest" << _END << std::endl;
	// for (size_t i = 0; i < rest.size(); i++)
	// {
	// 	std::cout << rest[i] << " ";
	// }
	// std::cout << std::endl;
	//phase de recursion
	tri(vec, exp + 1);
	std::cout << _BOLD"Back to recursion level " << exp << " (elements de taille " << puissanceDeDeux(exp) << ")" <<_END << std::endl;
	std::string color;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i % (puissanceDeDeux(exp)) == puissanceDeDeux(exp) - 1)
			color = _BOLD _CYAN;
		else
			color = _END;
		std::cout << color << vec[i] << " " << _END;
	}
	std::cout << std::endl << _BOLD _CYAN "Rest" << _END << std::endl;

	// if (vec.size() / puissanceDeDeux(exp) == 2)
	// 		std::cout << "on laisse\n" << std::endl;
	std::cout << "Insertion" << std::endl;
	
	
		for (size_t index = 3 * puissanceDeDeux(exp) - 1; index < vec.size(); index += puissanceDeDeux(exp)) // a checker
		{
			std::cout << "index = " << index << ", " << vec[index] << std::endl;
			size_t size = (index) / puissanceDeDeux(exp) ;
			size_t begin = 0;
			while (size != 0)
			{
				std::cout << "taille vec a inserer " << size << std::endl;
				size_t comp2 = begin + (size +1)/ 2 * puissanceDeDeux(exp) - 1;
				std::cout << "2nd comp = " << vec[comp2]  << " (index " << comp2 <<  ")" << std::endl;
				if (index - puissanceDeDeux(exp) + 1 == begin - 1)
				{
					std::cout << "deja a la bonne place !" << std::endl;
					std::cout << "\t";
						for (size_t i = 0; i < vec.size(); i++)
						{
							std::cout << vec[i] << " ";
						}
						std::cout << std::endl;
					break;
				}
				else if (vec[index] < vec[comp2])
				{
					begin += 0;
					std::cout << vec[index] << " < " << vec[comp2] << " begin = " << begin << std::endl;
				}
				else
				{
					begin += comp2 + 1;
					std::cout << vec[index] << " > " << vec[comp2] << " begin = " << begin << std::endl;
				}
				size /= 2;
				if (!size)
				{
					std::cout << "On insere la range " << vec[index - puissanceDeDeux(exp) + 1] << " (" << "index = " << index - puissanceDeDeux(exp) + 1 << ")" << " a " << vec[index] << " (" << "index = " << index << "), a partir de " << vec[begin]  << "(index = " << begin << ")" << std::endl; 
							vec.insert(vec.begin() + begin, vec.begin() + index - puissanceDeDeux(exp) + 1 ,  vec.begin() + index + 1);
							vec.erase(vec.begin() + index - puissanceDeDeux(exp) + 1 + puissanceDeDeux(exp),  vec.begin() + index + 1 + puissanceDeDeux(exp));					
						
						std::cout << "\t";
						for (size_t i = 0; i < vec.size(); i++)
						{
							std::cout << vec[i] << " ";
						}
						std::cout << std::endl;
					break;
				}
					
			}
			
		}
	
	// if (exp == 3)
	// {
	// 	if (vec.size() / puissanceDeDeux(exp) == 2)
	// 		std::cout << "on laisse\n" << std::endl;
	// 	else
	// 	{
	// 		std::cout << "on insere " << vec[puissanceDeDeux(exp)*3-1]  << "\n" << std::endl;
	// 		if (vec[puissanceDeDeux(exp)*3-1] < vec[2*puissanceDeDeux(exp)/2-1])
	// 		{
	// 			std::cout << vec[puissanceDeDeux(exp)*3-1] << " < " << vec[2*puissanceDeDeux(exp)/2-1] << std::endl;
	// 		}
	// 		else
	// 		{//go le simplifier avec des iterateurs
	// 			std::cout << vec[puissanceDeDeux(exp)*3-1] << " > " << vec[2*puissanceDeDeux(exp)/2-1] << std::endl;
	// 			vec.insert(vec.begin() + 2*puissanceDeDeux(exp)/2, vec.begin() + puissanceDeDeux(exp) * 2,  vec.begin() + puissanceDeDeux(exp)*3);
	// 			vec.erase(vec.begin() + puissanceDeDeux(exp) * 3, vec.begin() + puissanceDeDeux(exp) * 4);
	// 		}

	// 	}
		//est ce que jai un reste ? --> size / taille == impaire
		// if ((vec.size() / puissanceDeDeux(exp)) % 2)
		// 	std::cout << "impair : reste\n" << std::endl;
		// else
		// 	std::cout << "pair : pas rest\n" << std::endl;
	// }
	// for (size_t i = 0; i < rest.size(); i++)
	// {
	// 	if (i % (puissanceDeDeux(exp)) == puissanceDeDeux(exp) - 1)
	// 		color = _BOLD _CYAN;
	// 	else
	// 		color = _END;
	// 	std::cout << color << rest[i] << " " << _END;
	// }
	// std::cout << std::endl << std::endl;

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