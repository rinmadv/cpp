#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#define LIMIT 5000

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

void	hasDuplicates(const std::vector<unsigned int> &vec, size_t &nbVal)
{
	std::set<unsigned int> uniqueElements(vec.begin(), vec.end());
	if (uniqueElements.size() != nbVal)
		throw(std::runtime_error("Error: Wrong argument (duplicate in input)"));
}

void	parsing(std::vector<unsigned int> & vec, std::deque<unsigned int> & deque, int argc, char **argv, size_t & nbVal)
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
		try
		{
			vec.push_back(atoi(argv[i]));
		}
		catch(const std::exception& e)
		{
			throw (std::runtime_error("Error: memory allocation failed"));
		}
		
	}
	nbVal = vec.size();
	if (nbVal > LIMIT)
	{
		std::ostringstream errorMessage;
		errorMessage << "Error: max input number is limited to " << LIMIT << " numbers";
		throw (std::runtime_error(errorMessage.str()));
	}
	try
	{
		hasDuplicates(vec, nbVal);
	}
	catch(const std::exception& e)
	{
		throw (std::runtime_error(e.what()));
	}

	const size_t sizeVec = vec.size();
	try
	{
		for (size_t i = 0; i < sizeVec; i++)
		{
			deque.push_back(vec[i]);
		}
	}
	catch(const std::exception& e)
	{
		throw (std::runtime_error("Error: memory allocation failed"));
	}
	
}