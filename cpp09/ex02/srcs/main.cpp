#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

//vector
//deque

//check arguments : pas encore faite : ex 800e (a faire plus tard) + only UI
//check si sort ou pas
//error
//time

int comp_merge = 0;
int comp_insert = 0;

void	parsing(std::vector<unsigned int> & vec, int argc, char **argv);
void	ford_johnson(std::vector<unsigned int> &vec, const unsigned int & exp);

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

/*************************************************** MAIN ****************************************************/

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"), EXIT_FAILURE);

	std::vector<unsigned int> vec;
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