#include <iostream>
#include <sstream>
#include <vector>
// #include <utility>

# define _CYAN "\1\033[36m"
# define _END "\1\033[0m\2"

int    displayMessage(std::string message)
{
	std::cout << message << _END << std::endl;
	return (0);
}
template<typename T>
int tri(std::vector<T> vector)
{
	//pair
	displayMessage(_CYAN"Pairer");
	std::cout << "Taille vecteur : " << vector.size() << std::endl;
	
	std::vector<std::pair<T, T>> pairs;
	for (size_t i = 0; i < vector.size() - 1; i+=2)
		pairs.push_back(std::make_pair(vector[i], vector[i + 1]));

	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::ostringstream message;
		message <<"Paire " << i << "--> first = " << pairs[i].first << ", second = " << pairs[i].second;
		displayMessage(message.str());
	}

	//compare
	displayMessage(_CYAN"\nComparer");
	std::vector<std::pair<T, T>> merged;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if(pairs[i].first > pairs[i].second)
			merged.push_back(  )
	}
	if (pairs.size() <= 1)
		return 0;
	
	for (size_t i = 0; i < pairs.size() - 1; i += 2)
		merged.push_back(std::make_pair(pairs[i].first, pairs[i].second));
	// //recursion tri si taille != 1
	if (pairs.size() > 2)
		tri(merged);
	std::cout << "ciao" << std::endl;
	//insersion
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"));

	// std::vector<std::pair<int, int>> vec;
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		// displayMessage(argv[i]);
		vec.push_back(atoi(argv[i]));
	}
	tri(vec);
	return (0);
}