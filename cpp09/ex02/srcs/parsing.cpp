#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

/************************************************  PARSING ************************************************/

bool	isNumber(const std::string &arg)
{
	const size_t size = arg.size();
	for (size_t i = 0; i < size; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
	}
	return (true);
}

bool	hasDuplicates(const std::vector<unsigned int> &vec)
{
	std::set<unsigned int> uniqueElements(vec.begin(), vec.end());
	return (uniqueElements.size() != vec.size());
}

void	parsing(std::vector<unsigned int> & vec, std::deque<unsigned int> & deque, int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isNumber(argv[i]))
		{
			throw (std::runtime_error("Error: Wrong argument (non numerical caractere in input)"));
		}
		if (atol(argv[i]) > UINT_MAX)
		{
			throw (std::runtime_error("Error: Wrong argument (number > to UINTMAX)"));
		}
		vec.push_back(atoi(argv[i]));
	}
	if (hasDuplicates(vec))
	{
		throw (std::runtime_error("Error: Wrong argument (duplicate in input)"));
	}

	const size_t sizeVec = vec.size();
	for (size_t i = 0; i < sizeVec; i++)
	{
		deque.push_back(vec[i]);
	}
}