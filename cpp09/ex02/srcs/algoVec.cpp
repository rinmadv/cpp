#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

/*************************************************** ALGO ****************************************************/

void	swapPairs(std::vector<unsigned int> & vec, const size_t & step, const size_t & nextStep)
{
	std::vector<unsigned int>::iterator left = vec.begin() + step - 1;
	std::vector<unsigned int>::iterator right = vec.begin() + nextStep - 1;

	std::vector<unsigned int>::iterator end = vec.end();
	while (left < end && right < end)
	{
		std::vector<unsigned int>::iterator tempLeft = left;
		std::vector<unsigned int>::iterator tempRight = right;
		if (*left > *right)
		{
			for (size_t i = 0; i < step; i++)
			{
				std::swap(*left, *right);
				left--;
				right--;
			}
		}
		left = tempLeft  + nextStep;
		right = tempRight  + nextStep;
	}
}

void	removeB(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &bChain, const size_t & groupsize)
{
	for (size_t i = 0; i >= 0; i += groupsize)
	{
		size_t offset = FIRST_GROUP_TO_BE_INSERTED * groupsize;
		std::vector<unsigned int>::iterator start = mainChain.begin() + offset + i;
		if (start + groupsize > mainChain.end())
			return;
		std::vector<unsigned int>::iterator end = start + groupsize;
		bChain.insert(bChain.begin() + bChain.size() , start, end);
		mainChain.erase(start, end);
	}
}

void	removeLeftovers(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &bChain, const size_t & groupsize)
{
	const size_t offset = mainChain.size() % groupsize;
	if (!offset)
		return;
	std::vector<unsigned int>::iterator start = mainChain.end() - offset;
	std::vector<unsigned int>::iterator end = mainChain.end();
	bChain.insert(bChain.begin() + bChain.size() , start, end);
	mainChain.erase(start, end);
}

int	binarySearch(std::vector<unsigned int> & vec, const unsigned int & toFind)
{
	int left = 0;
	int right = vec.size();

	while (left < right)
	{
		int milieu = left + (right - left) / 2;
		if (vec[milieu] < toFind)
			left = milieu + 1;
		else
			right = milieu;
	}
	return left;
}

void	insertBChain(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &bChain, const size_t & groupsize)
{
	size_t leftoversInsertionsNb = bChain.size() % groupsize;
	
	std::vector<unsigned int>::iterator bChainSart = bChain.begin();
	std::vector<unsigned int>::iterator bChainEnd = bChainSart + groupsize;
	
	size_t insertionCount = 2;
	size_t nbGroupInMain = 2;
	std::vector<unsigned int>::iterator mainChainStart = mainChain.begin() + groupsize - 1;
	std::vector<unsigned int>::iterator mainChainEnd;

	while (bChainEnd <= bChain.end())
	{
		mainChainEnd = mainChainStart + (groupsize * nbGroupInMain);		
		std::vector<unsigned int> compared;
		for (std::vector<unsigned int>::iterator it = mainChainStart ; *it != *mainChainEnd; it += groupsize)
			compared.push_back(*it);
		int insertAt = binarySearch(compared, *(bChainEnd-1));
		std::vector<unsigned int>::iterator placeToInsert = mainChain.begin() + insertAt * groupsize;

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

void	ford_johnsonVec(std::vector<unsigned int> &vec, const unsigned int & exp)
{
	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = vec.size();

	if (nextStep > size)
		return;
	swapPairs(vec, step, nextStep);
	ford_johnsonVec(vec, exp + 1);

	std::vector<unsigned int> bChain;
	removeB(vec, bChain, step);
	if (!bChain.empty())
		removeLeftovers(vec, bChain, step);
	if (!bChain.empty())
		insertBChain(vec, bChain, step);
}
