#include <iostream>
#include <sstream>
#include <vector>
// #include <utility>

# define _CYAN "\1\033[36m"
# define _FOREST_GREEN "\1\033[32m\2"
# define _BOLD "\1\033[1m\2"
# define _END "\1\033[0m\2"
# define FIRST_GROUP_TO_BE_INSERTED 3
# define DEBUG true
int comp_merge = 0;
int comp_insert = 0;


/*

To do 10/09

- reussir a determiner le end ; ex : quand jinsere mon b2, il faut que je retrouve ou es mon a2 pour le definir comme fin (ou fin - 1) et ainsi eviter des comparaisons inutiles
--> ca doit pas etre si dur a faire si jarrive a incrementer a chaque fois un nombre afin de dire quon va a vec.end() - ce nombre comme limite

--->> tester avec moins de nombre !
->>>> retester etape par etape car la va yavoir des bug c sur
*/


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


void	swapPairs(std::vector<int> & vec, const size_t & size, const size_t & step, const size_t & nextStep)
{
	size_t indice_a;
	size_t indice_b;

	for (size_t i = 0; i < size; i += nextStep)
	{
		indice_a = i + step - 1;
		indice_b = i + nextStep - 1;

		if (indice_b < size && vec[indice_a] > vec[indice_b])
		{
			for (size_t k = 0; k < step; k++)
				std::swap(vec[indice_a - k], vec[indice_b - k]);
		}
		comp_merge++;
	}
}

size_t binarySearchInsertPosition(const std::vector<int>& vec, int val, size_t end)
{
	size_t begin = 0;
    while (begin < end)
	{
        size_t mid = (begin + end) / 2;
        if (val < vec[mid]) {
            end = mid;
        }
		else {
            begin = mid + 1;
        }
		comp_insert++;
    }
    return begin;
}

void insertElement(std::vector<int>& vec, int val, size_t end)
{
	size_t pos = binarySearchInsertPosition(vec, val, end);
	vec.insert(vec.begin() + pos, val);
}

void	ford_johnson(std::vector<int> &vec, int exp)
{
	//checker si le truc nest pas deja trie

	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = vec.size();
		
	/*If we only have one element, comparisirion is not possible and thus, this element is considered as sorted and recursion stops*/
	if (nextStep > size)
		return;
	swapPairs(vec, size, step, nextStep);
	ford_johnson(vec, exp + 1);

	const size_t groupSize = step; 
	std::vector<int> bChain;
    bool lastToSave = false;
	if (size % groupSize != 0)
		lastToSave = true;
	for (size_t i = FIRST_GROUP_TO_BE_INSERTED * groupSize - 1; i < size; i += groupSize * 2)
    {
        if (i + groupSize < size)
		{
			for (size_t k = 0; k < groupSize; k++)
			{
            	bChain.push_back(vec[i + k + groupSize]);
			}
			vec.erase(vec.begin() + i - groupSize, vec.begin() + i);
		}
    }
	
	if (lastToSave)
	{
		bChain.push_back(vec.back());
		vec.pop_back();
	}
	size_t bChainSize = bChain.size(); 
	size_t aChainSize = vec.size(); 
	for (size_t i = 0 ; i < bChainSize; i++)
	{
        insertElement(vec, bChain[0], i - step + 1);
		bChainSize -= 1;
		aChainSize +=1;
    }
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