#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

//vector
//deque

//check arguments : pas encore faite : ex 800e (a faire plus tard) + only UI
//check si sort ou pas
//error
//time


void	parsing(std::vector<unsigned int> & vec, std::deque<unsigned int> & deque, int argc, char **argv);
void	ford_johnsonVec(std::vector<unsigned int> &vec, const unsigned int & exp);
void	ford_johnsonDeque(std::deque<unsigned int> &deque, const unsigned int & exp);

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

/*************************************************** MAIN ****************************************************/

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"), EXIT_FAILURE);

	std::vector<unsigned int> vec;
	std::deque<unsigned int> deque;

	try
	{
		parsing(vec, deque, argc, argv);
	}
	catch(const std::exception& e)
	{
		return (std::cerr << e.what() << '\n', EXIT_FAILURE);
	}
	ford_johnsonVec(vec, 0);
	displayVector(vec);
	ford_johnsonDeque(deque, 0);
	displayDeque(deque);
	return (EXIT_SUCCESS);
}