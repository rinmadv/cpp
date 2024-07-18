#include "../includes/easyfind.hpp"
#include "../includes/Format.hpp"

#include <vector>
#include <deque>
#include <list>
#include <limits>

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

// Test with duplicate values
    vec.push_back(3);
    value = 3;
    std::cout << "🔍 Looking for " << value << " (duplicate) in vector ..." << std::endl;
    pair_vec = std::make_pair(vec, value);
    std::cout << pair_vec << std::endl;
    std::cout << std::endl;

    // Test with empty vector
    std::vector<int> empty_vec;
    std::pair<std::vector<int>, int> pair_empty_vec;
    value = 1;
    std::cout << "🔍 Looking for " << value << " in empty vector ..." << std::endl;
    pair_empty_vec = std::make_pair(empty_vec, value);
    std::cout << pair_empty_vec << std::endl;
    std::cout << std::endl;

    // Test with extreme values
    vec.push_back(std::numeric_limits<int>::max());
    value = std::numeric_limits<int>::max();
    std::cout << "🔍 Looking for max int value in vector ..." << std::endl;
    pair_vec = std::make_pair(vec, value);
    std::cout << pair_vec << std::endl;
    std::cout << std::endl;

    vec.push_back(std::numeric_limits<int>::min());
    value = std::numeric_limits<int>::min();
    std::cout << "🔍 Looking for min int value in vector ..." << std::endl;
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

// Test with duplicate values
    deq.push_back(3);
    value = 3;
    std::cout << "🔍 Looking for " << value << " (duplicate) in deque ..." << std::endl;
    pair_deq = std::make_pair(deq, value);
    std::cout << pair_deq << std::endl;
    std::cout << std::endl;

    // Test with empty deque
    std::deque<int> empty_deq;
    std::pair<std::deque<int>, int> pair_empty_deq;
    value = 1;
    std::cout << "🔍 Looking for " << value << " in empty deque ..." << std::endl;
    pair_empty_deq = std::make_pair(empty_deq, value);
    std::cout << pair_empty_deq << std::endl;
    std::cout << std::endl;

    // Test with extreme values
    deq.push_back(std::numeric_limits<int>::max());
    value = std::numeric_limits<int>::max();
    std::cout << "🔍 Looking for max int value in deque ..." << std::endl;
    pair_deq = std::make_pair(deq, value);
    std::cout << pair_deq << std::endl;
    std::cout << std::endl;

    deq.push_back(std::numeric_limits<int>::min());
    value = std::numeric_limits<int>::min();
    std::cout << "🔍 Looking for min int value in deque ..." << std::endl;
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

// Test with duplicate values
    lst.push_back(3);
    value = 3;
    std::cout << "🔍 Looking for " << value << " (duplicate) in list ..." << std::endl;
    pair_lst = std::make_pair(lst, value);
    std::cout << pair_lst << std::endl;
    std::cout << std::endl;

    // Test with empty list
    std::list<int> empty_lst;
    std::pair<std::list<int>, int> pair_empty_lst;
    value = 1;
    std::cout << "🔍 Looking for " << value << " in empty list ..." << std::endl;
    pair_empty_lst = std::make_pair(empty_lst, value);
    std::cout << pair_empty_lst << std::endl;
    std::cout << std::endl;

    // Test with extreme values
    lst.push_back(std::numeric_limits<int>::max());
    value = std::numeric_limits<int>::max();
    std::cout << "🔍 Looking for max int value in list ..." << std::endl;
    pair_lst = std::make_pair(lst, value);
    std::cout << pair_lst << std::endl;
    std::cout << std::endl;

    lst.push_back(std::numeric_limits<int>::min());
    value = std::numeric_limits<int>::min();
    std::cout << "🔍 Looking for min int value in list ..." << std::endl;
    pair_lst = std::make_pair(lst, value);
    std::cout << pair_lst << std::endl;
    std::cout << std::endl;
	return 0;
}

