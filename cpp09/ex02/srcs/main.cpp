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

bool	removeB(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	// std::cout << "b chain avant remove b:" << std::endl;
	// displayVector(bChain);
	for (size_t i = 0; i >= 0; i += groupsize)
	{
		size_t offset = FIRST_GROUP_TO_BE_INSERTED * groupsize;
		std::vector<int>::iterator start = mainChain.begin() + offset + i;
		if (start + groupsize + 1 > mainChain.end())//pas sure du +1 
		{
			// std::cout << "b chain apres remove b:" << std::endl;
			// displayVector(bChain);
			return (false);
		}
		std::vector<int>::iterator end = start + groupsize;
		// std::cout << "Cycle " << i/groupsize << std::endl;
		// std::cout << "	premiere val a remove = " << *start << std::endl;
		// std::cout << "	derniere val a remove = " << *end << std::endl;
		bChain.insert(bChain.begin() + bChain.size() , start, end);
		mainChain.erase(start, end);
	}
	return (true); //sinon jutilise les exceptions
}

void	removeLeftovers(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	// std::cout << "b chain : avant rest" << std::endl;
	// displayVector(bChain);
	size_t offset = mainChain.size() % groupsize;
	if (!offset)
		return;
	// std::cout << "Offset : " << offset << std::endl;
	std::vector<int>::iterator start = mainChain.end() - offset;
	std::vector<int>::iterator end = mainChain.end();

		// std::cout << "	premiere val a remove = " << *start << std::endl;
		bChain.insert(bChain.begin() + bChain.size() , start, end);
		mainChain.erase(start, end);
	std::cout << "b chain : apres rest" << std::endl;
	displayVector(bChain);
}

// std::vector<int>::iterator custom_lower_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, size_t nbGroups, size_t groupeSize)
// {
// 	std::cout << _PINK << "Premiere comp " << *first << ", seconde comp " << *last << " reference :" << value << std::endl << _END;
// 	// size_t groupNBmid;
// 	while (nbGroups != 2 && nbGroups != 0)
// 	{
// 		std::cout << _LAGOON << "On a " << nbGroups;
// 		nbGroups /= 2; 
// 		std::vector<int>::iterator mid = first + nbGroups * groupeSize;
// 		std::cout  << " et le milieu c'est " << *mid << _END << std::endl;
// 	}
	
	
// 	(void) nbGroups;
// 	(void) groupeSize;
// 	return (first); //a changer
// }

std::vector<int>::iterator	binarySearch(std::vector<int> vec, int toFind)
{
	size_t sizeVec = vec.size();

	
}

void	insertBChain(std::vector<int> &mainChain, std::vector<int> &bChain, size_t groupsize)
{
	size_t bInsertionsNb = bChain.size() / groupsize;
	size_t leftoversInsertionsNb = bChain.size() % groupsize;
	
	std::cout << _FOREST_GREEN <<  "Il y a " << bInsertionsNb << " groupes de " << groupsize << " elements a inserer et " << leftoversInsertionsNb << " elements restant a inserer a la fin" << std::endl << _END;
	std::vector<int>::iterator bChainSart = bChain.begin();
	//maybe faut checker quelque chose entre les deux 
	std::vector<int>::iterator bChainEnd = bChainSart + groupsize;
	size_t insertionCount = 2;
	size_t nbGroupInMain = 2;
	std::vector<int>::iterator mainChainStart = mainChain.begin() + groupsize - 1;
	std::vector<int>::iterator mainChainEnd;

	// std::vector<int>::iterator mainChainEnd = mainChainSart * ;
	// std::vector<int>::iterator mainChainSart = mainChain.begin() + groupsize;
	// int = 0;
	// std::lower_bound(mainChainStart, )
	while (bChainEnd <= bChain.end())
	{
		std::cout << _SALMON "On insrere b" << insertionCount  << "(" << *(bChainEnd-1) << ") dans " << nbGroupInMain << " groupes de taille " << groupsize << std::endl;
		//  *bChainSart << " a " << *bChainEnd << std::endl; //surement invalid read ici (check avec vg) mais juste sur l'affichage ecran
		

		/* Pour apres quand on aura fait l'insertion*/
		// std::cout << "On add (later supprime) de : " << *bChainSart << " a " << *(bChainEnd - 1) << std::endl << _END; //surement invalid read ici (check avec vg) mais juste sur l'affichage ecran
		mainChainEnd = mainChainStart + (groupsize * nbGroupInMain);
		// std::cout << _MAGENTA << "Premier chiffre compare: " << *mainChainStart << " vs dernier chiffre comparé " << *mainChainEnd << std::endl << _END;
		// std::cout << _RED << "on insere " <<  *(bChainEnd-1) << " après " << *custom_lower_bound(mainChainStart, mainChainEnd, *(bChainEnd-1), nbGroupInMain, groupsize) << _END << std::endl;
		// *custom_lower_bound(mainChainStart, mainChainEnd - groupsize, *(bChainEnd - 1), nbGroupInMain, groupsize);
		
		std::vector<int> compared;
		for (std::vector<int>::iterator it = mainChainStart ; *it != *mainChainEnd; it += groupsize)
		{
			compared.push_back(*it);
		}
		std::cout << _RED "tableau comparés : ";
		displayVector(compared);
		std::cout << std::endl << _END;
		std::vector<int>::iterator insertAt = binarySearch(compared, toFind);
		std::cout << _PURPLE << *place << _END << std::endl;
		
		bChain.erase(bChainSart, bChainEnd);
		std::cout << _ORANGE << "New bChain : " _END;
		displayVector(bChain);
		// //MAJ les iterateurs
		insertionCount += 1;
		nbGroupInMain += 2;
	}
	

	if (leftoversInsertionsNb)//attention si cest level 0 (mais normalement en level 0 yaura plus de reste)
	{
		mainChain.insert(mainChain.end() - 1, bChain.begin(), bChain.end());
		bChain.erase(bChain.begin(), bChain.end()); //maybe je peux utiliser clear, maisa a voir ce que fait la fonction
	}
	

	(void) mainChain;
	(void) bChain;
	(void) groupsize;
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
	std::cout << _BOLD _CYAN "Back to recursion level " << exp << std::endl << _END;
	// std::cout << "vec avant remove : ";
	// displayVector(vec);
	// std::cout << "bchain avant remove : ";
	// displayVector(bChain);
	
	if (removeB(vec, bChain, step))
	{
		std::cout << _FOREST_GREEN << "on bouge les left overs" << _END << std::endl;
		removeLeftovers(vec, bChain, step);
	}
	else
		std::cout << _END << "on bouge PAS les left overs" << _END << std::endl;
	std::cout << "vec apres remove : ";
	displayVector(vec);
	std::cout << "bchain apres remove : ";
	displayVector(bChain);

	if (!bChain.empty()) //maybe check avec taille
		insertBChain(vec, bChain, step);
	std::cout << "vec apres insertion : ";
	displayVector(vec);
	std::cout << "bchain apres insertion : ";
	displayVector(bChain);
	std::cout << std::endl << std::endl;
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

	// std::cout << _BOLD _CYAN "Before sorting" << _END << std::endl;
	// displayVector(vec);

	ford_johnson(vec, 0);

	// std::cout << _BOLD _CYAN "After sorting" << _END << std::endl;
	displayVector(vec);

	if (DEBUG)
		std::cout << _CYAN << "NB comp merge: " << comp_merge << " NB comp insert: " << comp_insert  << _END << std::endl;
	return (0);
}