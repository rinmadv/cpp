#include "../includes/MutantStack.hpp"
#include "../includes/Format.hpp"

#include <vector>
#include <list>
#include <limits.h>

static void displayTitle1(std::string str)
{
	std::cout << std::endl << _BOLD _AQUAMARINE << "⏳ " << str << "... ⌛" << _END << std::endl;
}

// static void displayTitle2(std::string str)
// {
// 	std::cout << std::endl << _ITALIC _MAGENTA << "✨ " << str << "... ✨" << _END << std::endl;
// }

// static void displayTitle3(std::string str)
// {
// 	std::cout << std::endl << _GREY << str << _END << std::endl;
// }

int main()
{
	displayTitle1("Test sur stack");
	{
		std::stack<int> stack;
		stack.push(5);
		stack.push(17);
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.size() << std::endl;
		stack.push(3);
		stack.push(5);
		stack.push(737);
		stack.push(0);
		// std::stack<int>::iterator it = stack.begin();
		// std::stack<int>::iterator ite = stack.end();
		// ++it;
		// --it;
		// while (it != ite)
		// {
		// std::cout << *it << std::endl;
		// ++it;
		// }
		std::stack<int> s(stack);
	}

	displayTitle1("Test sur mutant stack");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	displayTitle1("Test sur list");
	std::list<int> myList;

    myList.push_back(5);
    myList.push_back(17);

    std::cout << myList.back() << std::endl;

    myList.pop_back();

    std::cout << myList.size() << std::endl;

    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();
    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::list<int> s(myList);

	return 0;
}
