#include <iostream>
#include "../includes/Harl.hpp"

int main() {
    Harl h;

    std::cout << "Complaining about debug" << std::endl;
    h.complain("DEBUG");
    std::cout << "\nComplaining about info" << std::endl;
    h.complain("INFO");
    std::cout << "\nComplaining about warning" << std::endl;
    h.complain("WARNING");
    std::cout << "\nComplaining about error" << std::endl;
    h.complain("ERROR"); 
    std::cout << "\nComplaining about invalid level" << std::endl;
    h.complain("INVALID");
    std::cout << "\nComplaining about level out of range" << std::endl;
    h.complain("OUT_OF_RANGE");
    return 0;
}