#include <iostream>
#include <sstream>
#include <vector>
// #include <utility>

# define _CYAN "\1\033[36m"
# define _FOREST_GREEN "\1\033[32m\2"
# define _BOLD "\1\033[1m\2"
# define _END "\1\033[0m\2"

int    displayMessage(std::string message)
{
	std::cout << message << _END << std::endl;
	return (0);
}


int puissanceDeDeux(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }
    return result;
}

template<typename T>
int    displayVector(std::vector<T> vector, int level = 0)
{
	int iter = puissanceDeDeux(level);
	std::cout << _BOLD _CYAN << "Level " << level  << " (incrementation = " << iter << ")" << _END << std::endl;
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (!vector[i])
			break;
		std::cout << vector[i];
		if (!(i % iter))
			std::cout << " ";
		else
			std::cout << "\n";
	}
	std::cout << std::endl;	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (displayMessage("No number"));

	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		// displayMessage(argv[i]);
		vec.push_back(atoi(argv[i]));
	}
	for (int expolevel = 0; expolevel < 5; expolevel++)
	displayVector(vec, expolevel);
	// tri(vec);
	// displayVector(vec);
	return (0);
}