#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

/************************************************ UTILS MATHS ************************************************/

size_t	powerTwo(const unsigned int & exponent)
{
	size_t result = 1;
	for (unsigned int i = 0; i < exponent; ++i)
		result *= 2;
	return result;
}

/************************************************  DISPLAY ************************************************/

void	displayMessage(const std::string & message)
{
	std::cout << message << _END << std::endl;
}

void	displayVector(const std::vector<unsigned int> & vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	displayDeque(const std::deque<unsigned int> & deque)
{
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}

void 	displayTime(size_t nbElements, std::string type, double time)
{
	std::cout << "Time to process a range of " << nbElements << " with std::" << type << " : " _MAGENTA << time << " us" _END << std::endl;
}

/*************************************************** MAIN ****************************************************/

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"), EXIT_FAILURE);

	std::vector<unsigned int> vec;
	std::deque<unsigned int> deque;
	size_t nbVal;

	try
	{
		parsing(vec, deque, argc, argv, nbVal);
	}
	catch(const std::exception& e)
	{
		return (std::cerr << e.what() << '\n', EXIT_FAILURE);
	}

	std::cout << _BOLD _CYAN "Before : " _END;
	displayVector(vec);
	double timeVector;
	double timeDeque;

	std::clock_t timerStart;
	std::clock_t timerEnd;

	{
		timerStart = std::clock();
		ford_johnsonVec(vec, 0);
		timerEnd = std::clock();
		timeVector = (timerEnd - timerStart) * static_cast<double>(1000) / CLOCKS_PER_SEC;
	}

	{
		timerStart = std::clock();
		ford_johnsonDeque(deque, 0);
		timerEnd = std::clock();
		timeDeque = (timerEnd - timerStart) * static_cast<double>(1000) / CLOCKS_PER_SEC;
	}

	std::cout << _BOLD _CYAN "After : " _END;
	displayVector(vec);
	displayTime(nbVal, "vector", timeVector);
	displayTime(nbVal, "deque", timeDeque);
	
	return (EXIT_SUCCESS);
}