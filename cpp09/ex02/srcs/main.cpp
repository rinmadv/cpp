#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#include <vector>
#include <deque>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

#define DEBUG true
int comp_merge = 0;
int comp_insert = 0;

//vector
//deque

//check arguments : pas encore faite : ex 800e (a faire plus tard) + only UI
//check si sort ou pas
//error
//time
// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort


void    displayMessage(const std::string & message)
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

	// std::cout << "espace entre deux chiffres compares : " << step << std::endl;
	// std::cout << "incrementation entre deux series: " << nextStep << std::endl;

	(void) size;
	(void) vec;
	(void) step;
	(void) nextStep;

	std::vector<int>::iterator left = vec.begin() + step - 1;
	std::vector<int>::iterator right = vec.begin() + nextStep - 1;
	// size_t indice_a;
	// size_t indice_b;

	std::cout << _BOLD _CYAN " Recursion level " << step / 2 << std::endl << _END;

	while (left < vec.end() && right < vec.end())
	{
		std::cout << *left << " vs " << *right << " " << std::endl;
		if (*left > *right)
		{
			std::cout << "on swap !" << std::endl;
			for (size_t i = 0; i < nextStep - 1; i++)
			{
				std::swap(*left, *right);
				left--;
				right--;
			}
			comp_merge++;
		}
		left += nextStep;
		right += nextStep;
	}
	
	// for (size_t i = 0; i < size; i += nextStep)
	// {
	// 	indice_a = i + step - 1;
	// 	indice_b = i + nextStep - 1;

	// 	if (indice_b < size && vec[indice_a] > vec[indice_b])
	// 	{
	// 		for (size_t k = 0; k < step; k++)
	// 			std::swap(vec[indice_a - k], vec[indice_b - k]);
	// 	}
	// 	comp_merge++;
	// }
}

void	ford_johnson(std::vector<int> &vec, int exp)
{
	//check si pas deja trie : en gros si dans le niveau 0 de la recursion on na fait aucun swap; on quite la fonction

	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = vec.size();
		
	/*If we only have one element, comparisirion is not possible and thus, this element is considered as sorted and recursion stops*/
	if (nextStep > size)
		return;
	swapPairs(vec, size, step, nextStep);
	displayVector(vec);
	ford_johnson(vec, exp + 1);


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

	// std::cout << _BOLD _CYAN "Before sorting" << _END << std::endl;
	// displayVector(vec);

	ford_johnson(vec, 0);

	// std::cout << _BOLD _CYAN "After sorting" << _END << std::endl;
	displayVector(vec);

	// if (DEBUG)
	// 	std::cout << _CYAN << "NB comp merge: " << comp_merge << " NB comp insert: " << comp_insert  << _END << std::endl;
	return (0);
}