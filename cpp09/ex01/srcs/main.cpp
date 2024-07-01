#include "../includes/Format.hpp"

#include <iostream>
#include <stack>
#include <sstream>

int displayError(std::string str)
{
	std::cerr << _BOLD _RED << "⚠️ Error: " << str << " ⚠️" << _END << std::endl;
	return (1);
}

bool	isOperator(char c)
{
	return ((c == '+' || c == '-' || c == '*' || c == '/'));
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (displayError("Wrong number of arguments"));
	
	std::stack<int> stack;
	int i = 0;
	while (argv[1][i])
	{
		char c = argv[1][i];
		if (isspace(c))
			;
		else if (isdigit(c))
		{
			if (argv[1][i+1] && !isspace(argv[1][i+1]))
				return (displayError("Wrong arguments"));
			stack.push(c - '0');
		}
		else if (isOperator(c))
		{
			if (!stack.empty() && stack.size() < 2)
                return displayError("Wrong arguments");
			
			int a =  stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();

            switch (c) {
                case '+':
                    stack.push(b + a);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(b * a);
                    break;
                case '/':
                    if (a == 0) {
                        return displayError("Division by zero is impossible");
                    }
                    stack.push(b / a);
                    break;
            }
		}
		else
			return (displayError("Wrong arguments"));
		i++;
	}
	if (stack.size() != 1)
		return (displayError("Wrong arguments"));
	std::cout << stack.top() << std::endl;
	return (0);
}