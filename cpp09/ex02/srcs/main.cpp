#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#include <vector>
#include <deque>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

#define DEBUG true
#define FIRST_GROUP_TO_BE_INSERTED 2
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

void	removeB(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	for (size_t i = 0; i >= 0; i += groupsize)
	{
		size_t offset = FIRST_GROUP_TO_BE_INSERTED * groupsize;
		std::vector<int>::iterator start = mainChain.begin() + offset + i;
		if (start + groupsize> mainChain.end())//pas sure du +1 
			return;
		std::vector<int>::iterator end = start + groupsize;
		bChain.insert(bChain.begin() + bChain.size() , start, end);
		mainChain.erase(start, end);
	}
}

void	removeLeftovers(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	size_t offset = mainChain.size() % groupsize;
	if (!offset)
		return;
	std::vector<int>::iterator start = mainChain.end() - offset;
	std::vector<int>::iterator end = mainChain.end();
	bChain.insert(bChain.begin() + bChain.size() , start, end);
	mainChain.erase(start, end);
}

int	binarySearch(std::vector<int> & vec, int toFind)
{
    int gauche = 0;
    int droite = vec.size();

    while (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (vec[milieu] < toFind)
            gauche = milieu + 1;
		else
            droite = milieu;
		comp_insert++;
    }
    return gauche;
}

void	insertBChain(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	size_t leftoversInsertionsNb = bChain.size() % groupsize;
	
	std::vector<int>::iterator bChainSart = bChain.begin();
	std::vector<int>::iterator bChainEnd = bChainSart + groupsize;
	
	size_t insertionCount = 2;
	size_t nbGroupInMain = 2;
	std::vector<int>::iterator mainChainStart = mainChain.begin() + groupsize - 1;
	std::vector<int>::iterator mainChainEnd;

	while (bChainEnd <= bChain.end())
	{
		mainChainEnd = mainChainStart + (groupsize * nbGroupInMain);		
		std::vector<int> compared;
		for (std::vector<int>::iterator it = mainChainStart ; *it != *mainChainEnd; it += groupsize)
			compared.push_back(*it);
		int insertAt = binarySearch(compared, *(bChainEnd-1));
		std::vector<int>::iterator placeToInsert = mainChain.begin() + insertAt * groupsize;

		mainChain.insert(placeToInsert, bChainSart, bChainEnd);
		bChain.erase(bChainSart, bChainEnd);
		insertionCount += 1;
		nbGroupInMain += 2;
	}
	
	if (leftoversInsertionsNb)//attention si cest level 0 (mais normalement en level 0 yaura plus de reste)
	{
		mainChain.insert(mainChain.end(), bChain.begin(), bChain.end());
		bChain.erase(bChain.begin(), bChain.end()); //maybe je peux utiliser clear, maisa a voir ce que fait la fonction
	}
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
	// std::cout << _BOLD _CYAN "Recursion level " << exp << std::endl << _END;
	swapPairs(vec, step, nextStep);
	// displayVector(vec);
	ford_johnson(vec, exp + 1);
	std::vector<int> bChain;
	
	removeB(vec, bChain, step);
	if (!bChain.empty())
		removeLeftovers(vec, bChain, step);
	if (!bChain.empty())
		insertBChain(vec, bChain, step);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"), EXIT_FAILURE);

	//Parsing, mettre les arg dans un vecteur (a mettre dans une fonction + faire les verif doublons)
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
	}
	ford_johnson(vec, 0);
	displayVector(vec);
	if (DEBUG)
		std::cout << _CYAN << "NB comp merge: " << comp_merge << " NB comp insert: " << comp_insert  << _END << std::endl;
	return (0);
}