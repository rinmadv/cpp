#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

size_t	powerTwo(const unsigned int & exponent);

/*************************************************** ALGO ****************************************************/

void	swapPairs(std::deque<unsigned int> & deque, const size_t & step, const size_t & nextStep)
{
	std::deque<unsigned int>::iterator left = deque.begin() + step - 1;
	std::deque<unsigned int>::iterator right = deque.begin() + nextStep - 1;

	std::deque<unsigned int>::iterator end = deque.end();
	while (left < end && right < end)
	{
		std::deque<unsigned int>::iterator tempLeft = left;
		std::deque<unsigned int>::iterator tempRight = right;
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

void	removeB(std::deque<unsigned int> &mainChain, std::deque<unsigned int> &bChain, const size_t & groupsize)
{
	for (size_t i = 0; i >= 0; i += groupsize)
	{
		size_t offset = FIRST_GROUP_TO_BE_INSERTED * groupsize;
		std::deque<unsigned int>::iterator start = mainChain.begin() + offset + i;
		if (start + groupsize > mainChain.end())
			return;
		std::deque<unsigned int>::iterator end = start + groupsize;
		bChain.insert(bChain.begin() + bChain.size() , start, end);
		mainChain.erase(start, end);
	}
}

void	removeLeftovers(std::deque<unsigned int> &mainChain, std::deque<unsigned int> &bChain, const size_t & groupsize)
{
	const size_t offset = mainChain.size() % groupsize;
	if (!offset)
		return;
	std::deque<unsigned int>::iterator start = mainChain.end() - offset;
	std::deque<unsigned int>::iterator end = mainChain.end();
	bChain.insert(bChain.begin() + bChain.size() , start, end);
	mainChain.erase(start, end);
}

int	binarySearch(std::deque<unsigned int> & deque, const unsigned int & toFind)
{
	int left = 0;
	int right = deque.size();

	while (left < right)
	{
		int milieu = left + (right - left) / 2;
		if (deque[milieu] < toFind)
			left = milieu + 1;
		else
			right = milieu;
	}
	return left;
}

void	insertBChain(std::deque<unsigned int> &mainChain, std::deque<unsigned int> &bChain, const size_t & groupsize)
{
	size_t leftoversInsertionsNb = bChain.size() % groupsize;
	
	std::deque<unsigned int>::iterator bChainSart = bChain.begin();
	std::deque<unsigned int>::iterator bChainEnd = bChainSart + groupsize;
	
	size_t insertionCount = 2;
	size_t nbGroupInMain = 2;
	std::deque<unsigned int>::iterator mainChainStart = mainChain.begin() + groupsize - 1;
	std::deque<unsigned int>::iterator mainChainEnd;

	while (bChainEnd <= bChain.end())
	{
		mainChainEnd = mainChainStart + (groupsize * nbGroupInMain);		
		std::deque<unsigned int> compared;
		for (std::deque<unsigned int>::iterator it = mainChainStart ; *it != *mainChainEnd; it += groupsize)
			compared.push_back(*it);
		int insertAt = binarySearch(compared, *(bChainEnd-1));
		std::deque<unsigned int>::iterator placeToInsert = mainChain.begin() + insertAt * groupsize;

		mainChain.insert(placeToInsert, bChainSart, bChainEnd);
		bChain.erase(bChainSart, bChainEnd);
		bChainSart = bChain.begin();
		bChainEnd = bChainSart + groupsize;
		insertionCount += 1;
		nbGroupInMain += 2;
	}

	if (leftoversInsertionsNb)
	{
		mainChain.insert(mainChain.end(), bChain.begin(), bChain.end());
		bChain.erase(bChain.begin(), bChain.end());
	}
}

void	ford_johnsonDeque(std::deque<unsigned int> &deque, const unsigned int & exp)
{
	const size_t step = powerTwo(exp);
	const size_t nextStep = step * 2;
	const size_t size = deque.size();

	if (nextStep > size)
		return;
	swapPairs(deque, step, nextStep);
	ford_johnsonDeque(deque, exp + 1);

	std::deque<unsigned int> bChain;
	removeB(deque, bChain, step);
	if (!bChain.empty())
		removeLeftovers(deque, bChain, step);
	if (!bChain.empty())
		insertBChain(deque, bChain, step);
}
