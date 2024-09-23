#ifndef DEF_PMERGEME
#define DEF_PMERGEME

#include <iostream>
#include <sstream>
#include <stdexcept>

#include <algorithm>
#include <iterator>

#include <vector>
#include <deque>
#include <set>

#include <ctime>

#include <limits.h>
#include <stdlib.h>

#include "../includes/Format.hpp"

#define FIRST_GROUP_TO_BE_INSERTED 2
#define DEBUG false

void	parsing(std::vector<unsigned int> & vec, std::deque<unsigned int> & deque, int argc, char **argv, size_t &nbVal);
void	ford_johnsonVec(std::vector<unsigned int> &vec, const unsigned int & exp);
void	ford_johnsonDeque(std::deque<unsigned int> &deque, const unsigned int & exp);
size_t	powerTwo(const unsigned int & exponent);

#endif