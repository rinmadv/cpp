#include "../includes/Format.hpp"
#include "../includes/PMergeMe.hpp"

#include <vector>
#include <deque>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

//vector
//deque

//check arguments : pas encore faite : ex 800e (a faire plus tard) + only UI
//check si sort ou pas
//error
//time

void	insertVec1(std::vector<int> &vector)
{
	int temp;
	for (size_t i = 0; i <= vector.size() - 1; i+=4) //utiliser les puissances de 2
	{
		if (!vector[i + 1] || !vector[i + 2] || !vector[i + 3])
			break;
		std::cout << "vector [" << i << "] " << vector[i] << " " << "vector [" << i + 1 << "] " << vector[i+1] << " vector [" << i+2 << "] " << vector[i+2] << " " << "vector [" << i + 3 << "] " << vector[i+3] << " --> ";
		if (vector[i] > vector[i + 2])
		{
			temp = vector[i];
			vector[i] = vector[i + 2];
			vector[i + 2] = temp;
		}
		std::cout << vector[i] << " " << vector[i+1] << " " << vector[i+2] << " " << vector[i+3] <<std::endl;
	}
		std::cout << _MAGENTA _BOLD "Sorted sequence1 : " _END;
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;
}

void	insertVec0(std::vector<int> &vector)
{
	int temp;
	for (size_t i = 0; i <= vector.size() - 1; i+=2)
	{
		if (!vector[i + 1])
			break;
		std::cout << "vector [" << i << "] " << vector[i] << " " << "vector [" << i + 1 << "] " << vector[i+1] << " --> ";
		if (vector[i] > vector[i + 1])
		{
			temp = vector[i];
			vector[i] = vector[i + 1];
			vector[i + 1] = temp;
		}
		std::cout << vector[i] << " " << vector[i+1] << std::endl;
	}
		std::cout << _MAGENTA _BOLD "Sorted sequence0 : " _END;
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;
}

// void	PMergeMeVector(std::vector<int> vector)
// {

// }


int main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error : no input" << std::endl, 1);
	std::vector<int> vec;
	std::deque<int> deque;

	int nb;
	for (int i = 1; i < argc; i++)
	{
		nb = atoi(argv[i]);
		vec.push_back(nb);
		deque.push_back(nb);
		if (i == argc - 1 && DEBUG)
			std::cout << _FOREST_GREEN _BOLD "i = " << i << std::endl;
	}
	if (DEBUG)
	{
		std::cout << _MAGENTA _BOLD "Unsorted sequence : " _END;
		for (size_t i = 0; i < vec.size() || i < deque.size(); i++)
		{
			std::cout << vec[i] << " ";
			if (vec[i] != deque[i])
			{
				std::cout << "error" << std::endl;
				break;
			}
			if (i == vec.size() - 1 && i == deque.size() - 1)
				// std::cout << _FOREST_GREEN _BOLD "i = " << i << std::endl;
				std::cout << std::endl;
		}
	}
	insertVec0(vec);
	insertVec1(vec);
	std::cout << _MAGENTA _BOLD "Time to sort vector : " _END << std::endl;
	std::cout << _MAGENTA _BOLD "Time to sort deque : " _END << std::endl;
	return 0;
}

// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort