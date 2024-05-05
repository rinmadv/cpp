#include "../includes/easyfind.hpp"
#include "../includes/Format.hpp"

#include <vector>
#include <deque>
#include <list>

int main() {
	std::cout << _BOLD _AQUAMARINE "⏳ TESTS ON VECTORS... ⌛" _END << std::endl;

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << std::endl;

	int value;
	std::pair<std::vector<int>, int> pair_vec;
	
	value = 3;
	std::cout << _BOLD _GREY "🔍 Looking for " << value << " in array ..." _END << std::endl;
	pair_vec = std::make_pair(vec, value);
	std::cout << pair_vec << std::endl;
	std::cout << std::endl;

	value = 6;
	std::cout << _BOLD _GREY "🔍 Looking for " << value << " in array ..." _END << std::endl;
	pair_vec = std::make_pair(vec, value);
	std::cout << pair_vec << std::endl;
	std::cout << std::endl;

	value = 'a';
	std::cout << _BOLD _GREY "🔍 Looking for " << value << " in array ..." _END << std::endl;
	pair_vec = std::make_pair(vec, value);
	std::cout << pair_vec << std::endl;
	std::cout << std::endl;

	vec.push_back('a');
	value = 'a';
	std::cout << _BOLD _GREY "🔍 Looking for " << value << " in array ..." _END << std::endl;
	pair_vec = std::make_pair(vec, value);
	std::cout << pair_vec << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _AQUAMARINE "⏳ TESTS ON DEQUES... ⌛" _END << std::endl;

	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	std::cout << std::endl;

	std::pair<std::deque<int>, int> pair_deq;

	value = 3;
	std::cout << "🔍 Looking for " << value << " in deque ..." << std::endl;
	pair_deq = std::make_pair(deq, value);
	std::cout << pair_deq << std::endl;
	std::cout << std::endl;

	value = 6;
	std::cout << "🔍 Looking for " << value << " in deque ..." << std::endl;
	pair_deq = std::make_pair(deq, value);
	std::cout << pair_deq << std::endl;
	std::cout << std::endl;

	std::cout << _BOLD _AQUAMARINE "⏳ TESTS ON LISTS... ⌛" _END << std::endl;

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	std::cout << std::endl;

	std::pair<std::list<int>, int> pair_lst;

	value = 3;
	std::cout << "🔍 Looking for " << value << " in list ..." << std::endl;
	pair_lst = std::make_pair(lst, value);
    std::cout << pair_lst << std::endl;
    std::cout << std::endl;

    value = 6;
    std::cout << "🔍 Looking for " << value << " in list ..." << std::endl;
    pair_lst = std::make_pair(lst, value);
    std::cout << pair_lst << std::endl;
    std::cout << std::endl;

	return 0;
}