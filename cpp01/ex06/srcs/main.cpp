#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{ 
    if (argc != 2)
    {
        std::cout << "Usage : ./HarlFilter [DEBUG / INFO / WARNING / ERROR]";
        return (1);
    }
    Harl h;
    h.complain(argv[1]);
    return 0;
}