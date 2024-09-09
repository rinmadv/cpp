#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    if (argc < 2)
    {    
        std::cout << "No argument in input" << std::endl;
        return (EXIT_FAILURE);
    }
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
	}

    size_t size = vec.size();
    for (size_t i = 0; i < size; i++)
	{
		if (i < size - 1 && vec[i] > vec[i+1])
        {
            std::cerr << "Pas trie " << std::endl;
            return (EXIT_FAILURE);
        };
    }
    std::cerr << "Trie" << std::endl;
    return (EXIT_SUCCESS);
}