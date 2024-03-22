#include "../includes/ScalarConverter.hpp"

class ScalarConverter;

int	main(int argc, char **argv)
{
	if (argc != 2)
    {
        std::cout << "usage : ./ScalarConvertor <arg>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}
