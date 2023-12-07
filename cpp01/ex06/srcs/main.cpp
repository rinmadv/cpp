#include <iostream>
#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage : ./HarlFilter [filter level]" << std::endl;
        return (EXIT_FAILURE);
    }
    Harl h;

    h.complain(argv[1]);
    return 0;
}