#include <iostream>
#include <sstream>
#include <vector>
// #include <utility>

# define _CYAN "\1\033[36m"
# define _FOREST_GREEN "\1\033[32m\2"
# define _BOLD "\1\033[1m\2"
# define _END "\1\033[0m\2"
# define FIRST_GROUP_TO_BE_INSERTED 3

/*********************************************** UTILS DISPLAY ***********************************************/

void    displayMessage(std::string message)
{
	std::cout << message << _END << std::endl;
}

void	displayVector(const std::vector<int> & vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

/************************************************ UTILS MATHS ************************************************/

size_t powerTwo(int exponent)
{
	//careful overflow
    size_t result = 1;
    for (int i = 0; i < exponent; ++i)
	{
        result *= 2;
    }
    return result;
}

/*************************************************** ALGO ****************************************************/

void	swapPairs(std::vector<int> & vec, const size_t & size, const size_t & step, const size_t & nextStep)
{
	size_t indice_a;
	size_t indice_b;

	for (size_t i = 0; i < size; i += nextStep)
	{
		std::cout << "i =" << i << std::endl;
		indice_a = i + step - 1;
		indice_b = i + nextStep - 1;

		std::cout << _FOREST_GREEN << "comp a : vec[" << indice_a << "] = " << vec[indice_a] << _END << std::endl;
		if (indice_b < size)
		{
			std::cout << _FOREST_GREEN << "comp b : vec[" << indice_b << "] = " << vec[indice_b] <<_END << std::endl;
			if (vec[indice_a] > vec[indice_b])
			{
				std::cout << "On doit les swap" << std::endl;
				for (size_t k = 0; k < step; k++)
				{
					std::cout << "swap vec[" << indice_a - k << "] avec vec[" << indice_b - k << "]" << std::endl;
					std::swap(vec[indice_a - k], vec[indice_b - k]);
				}
			}

		}
	}
}


void	ford_johnson(std::vector<int> &vec, int exp)
{
	//checker si le truc nest pas deja trie

	std::cout << std::endl << _BOLD _CYAN << "Recursion level " << exp << _END << std::endl;
	
	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = vec.size();
	std::cout << "size = " << size << std::endl;
		
	/*If we only have one element, comparisirion is not possible and thus, this element is considered as sorted and recursion stops*/
	if (nextStep > size)
	{
		std::cout << "on stop la recursion" << std::endl;
		return;
	}
	swapPairs(vec, size, step, nextStep);
	ford_johnson(vec, exp + 1);

	/*Insertion*/
	std::cout << _BOLD"Back to recursion level " << exp << " (elements de taille " << step << ")" <<_END << std::endl;
	std::string color;
	for (size_t i = 0; i < size; i++)
	{
		if (i % (step) == step - 1)
			color = _BOLD _CYAN;
		else
			color = _END;
		std::cout << color << vec[i] << " " << _END;
	}
	std::cout << std::endl << _BOLD _CYAN "Rest" << _END << std::endl;



	//jojfoidngoisd
	// if (size / step == 2)
	// 		std::cout << "on laisse\n" << std::endl;
	
	const size_t groupSize = powerTwo(exp);

	std::cout << "Insertion" << std::endl;
	
	
		for (size_t index = FIRST_GROUP_TO_BE_INSERTED * groupSize - 1; index < size; index += groupSize) // a checker
		{
			std::cout << "index = " << index << ", " << vec[index] << std::endl;
			size_t groupCount = (index) / groupSize ;
			size_t begin = 0;
			while (groupCount > 0)
			{
				std::cout << "taille vec a inserer " << groupCount << std::endl;
				size_t comp2 = begin + (groupCount + 1)/ 2 * groupSize - 1;
				std::cout << "2nd comp = " << vec[comp2]  << " (index " << comp2 <<  ")" << std::endl;
				if (index - groupSize + 1 == begin - 1)
				{
					std::cout << "deja a la bonne place !" << std::endl;
					std::cout << "\t";
						for (size_t i = 0; i < size; i++)
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
				groupCount /= 2;
				if (!groupCount)
				{
					std::cout << "On insere la range " << vec[index - groupSize + 1] << " (" << "index = " << index - groupSize + 1 << ")" << " a " << vec[index] << " (" << "index = " << index << "), a partir de " << vec[begin]  << "(index = " << begin << ")" << std::endl; 
							vec.insert(vec.begin() + begin, vec.begin() + index - groupSize + 1 ,  vec.begin() + index + 1);
							vec.erase(vec.begin() + index - groupSize + 1 + groupSize,  vec.begin() + index + 1 + groupSize);					
						
						std::cout << "\t";
						for (size_t i = 0; i < size; i++)
						{
							std::cout << vec[i] << " ";
						}
						std::cout << std::endl;
					break;
				}
					
			}
			
	// 	}
	
	// if (exp == 3)
	// {
	// 	if (size / step == 2)
	// 		std::cout << "on laisse\n" << std::endl;
	// 	else
	// 	{
	// 		std::cout << "on insere " << vec[step*3-1]  << "\n" << std::endl;
	// 		if (vec[step*3-1] < vec[2*step/2-1])
	// 		{
	// 			std::cout << vec[step*3-1] << " < " << vec[2*step/2-1] << std::endl;
	// 		}
	// 		else
	// 		{//go le simplifier avec des iterateurs
	// 			std::cout << vec[step*3-1] << " > " << vec[2*step/2-1] << std::endl;
	// 			vec.insert(vec.begin() + 2*step/2, vec.begin() + step * 2,  vec.begin() + step*3);
	// 			vec.erase(vec.begin() + step * 3, vec.begin() + step * 4);
	// 		}

	// 	}

	// }
	// for (size_t i = 0; i < rest.size(); i++)
	// {
	// 	if (i % (step) == step - 1)
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
		return (displayMessage("No number"), EXIT_FAILURE);

	//Parsing, mettre les arg dans un vecteur (a mettre dans une fonction + faire les verif)
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
	}

	std::cout << _BOLD _CYAN "Before sorting" << _END << std::endl;
	displayVector(vec);

	ford_johnson(vec, 0);

	std::cout << _BOLD _CYAN "After sorting" << _END << std::endl;
	displayVector(vec);

	return (0);
}