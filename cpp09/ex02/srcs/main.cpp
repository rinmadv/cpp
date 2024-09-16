#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#include <vector>
#include <deque>
#include <set>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

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


/************************************************  DISPLAY ************************************************/

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

/************************************************  PARSING ************************************************/

bool	isNumber(const std::string &arg)
{
	size_t size = arg.size();
	for (size_t i = 0; i < size; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
	}
	return (true);
}

bool hasDuplicates(const std::vector<int> &vec)
{
    std::set<int> uniqueElements(vec.begin(), vec.end());
    return (uniqueElements.size() != vec.size());
}

void	parsing(std::vector<int> & vec, int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isNumber(argv[i]))
		{
			throw (std::runtime_error("Error: Wrong argument (non numerical caractere in input)"));
		}
		if (atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
		{
			throw (std::runtime_error("Error: Wrong argument (number > to INTMAX or < to INTMIN in input)"));
		}
		vec.push_back(atoi(argv[i]));
	}
	if (hasDuplicates(vec))
	{
		throw (std::runtime_error("Error: Wrong argument (duplicate in input)"));
	}
}
/************************************************ UTILS MATHS ************************************************/

size_t powerTwo(int exponent)
{
    size_t result = 1;
    for (int i = 0; i < exponent; ++i)
        result *= 2;
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
		if (start + groupsize > mainChain.end())
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

	if (leftoversInsertionsNb)
	{
		mainChain.insert(mainChain.end(), bChain.begin(), bChain.end());
		bChain.erase(bChain.begin(), bChain.end());
	}
}

void	ford_johnson(std::vector<int> &vec, int exp)
{
	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = vec.size();
		
	if (nextStep > size)
		return;
	swapPairs(vec, step, nextStep);
	ford_johnson(vec, exp + 1);

	std::vector<int> bChain;
	removeB(vec, bChain, step);
	if (!bChain.empty())
		removeLeftovers(vec, bChain, step);
	if (!bChain.empty())
		insertBChain(vec, bChain, step);
}

/*************************************************** MAIN ****************************************************/

int main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"), EXIT_FAILURE);

	std::vector<int> vec;
	try
	{
		parsing(vec, argc, argv);
	}
	catch(const std::exception& e)
	{
		return (std::cerr << e.what() << '\n', EXIT_FAILURE);
	}
	ford_johnson(vec, 0);
	displayVector(vec);
	if (DEBUG)
		std::cout << _CYAN << "NB comp merge: " << comp_merge << " NB comp insert: " << comp_insert  << _END << std::endl;
	return (EXIT_SUCCESS);
}