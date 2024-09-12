#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#include <vector>
#include <deque>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

#define DEBUG true
#define FIRST_GROUP_TO_BE_INSERTED 3
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

void	swapPairs(std::vector<int> & vec, const size_t & step, const size_t & nextStep)
{
	std::vector<int>::iterator left = vec.begin() + step - 1;
	std::vector<int>::iterator right = vec.begin() + nextStep - 1;

	while (left < vec.end() && right < vec.end())
	{
		std::vector<int>::iterator tempLeft = left;
		std::vector<int>::iterator tempRight = right;
		if (*left > *right)
		{
			for (size_t i = 0; i < step; i++)
			{
				std::swap(*left, *right);
				left--;
				right--;
			}
			comp_merge++;
		}
		left = tempLeft  + nextStep;
		right = tempRight  + nextStep;
	}
}

void	removeB(std::vector<int> &vec, std::vector<int> &bChain, size_t size, size_t groupsize)
{
	(void) vec;
	(void) bChain;
	(void) size;
	size_t offset = FIRST_GROUP_TO_BE_INSERTED * groupsize;
	// if (offset > size - 1)
	// 	return;
	std::vector<int>::iterator start = vec.begin() + offset;
	if (start + groupsize + 1 > vec.end())
		return;
	std::cout << "premiere val a remove = " << *start << std::endl;
	// std::cout << *start << std::endl;
	(void) start;
	//verif
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
	std::cout << _BOLD _CYAN "Recursion level " << exp << std::endl << _END;
	swapPairs(vec, step, nextStep);
	displayVector(vec);
	ford_johnson(vec, exp + 1);
	std::vector<int> bChain;
	std::cout << _BOLD _CYAN "Back to recursion level " << exp << std::endl << _END;
	displayVector(vec);
	removeB(vec, bChain, size, step);
	//removeLeftovers

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

	if (DEBUG)
		std::cout << _CYAN << "NB comp merge: " << comp_merge << " NB comp insert: " << comp_insert  << _END << std::endl;
	return (0);
}