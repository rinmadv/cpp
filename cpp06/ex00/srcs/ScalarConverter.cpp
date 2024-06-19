#include "../includes/ScalarConverter.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src){*this = src;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){ (void) rhs; return (*this);}

/*********** MEMBER FUNCTION ***********/


//verifs float, grandeur
//voir comment convert double et float sans perte de precision...

/*********** CONVERT ***********/

void	convertImpossible()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\timpossible"<< std::endl;
	std::cout << "double:\timpossible"<< std::endl;
}

void	convertNan()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\tnanf"<< std::endl;
	std::cout << "double:\tnan"<< std::endl;
}

void	convertInf()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\tinff"<< std::endl;
	std::cout << "double:\tinf"<< std::endl;
}

void	convertMInf()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\t-inff"<< std::endl;
	std::cout << "double:\t-inf"<< std::endl;
}

void	convertChar(char c)
{
	std::cout << "char:\t"<< c << std::endl;
	std::cout << "int:\t"<< static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << ".0 " << std::endl;
}

void	convertInt(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "char:\t"<< static_cast<char>(i) << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	std::cout << "int:\t"<< i << std::endl;
	std::cout << "float:\t" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << ".0 " << std::endl;
}

/*********** IDENTIFY TYPE ***********/

bool	isChar(std::string literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
	{
		std::cout << "C'est un char" << std::endl;
		convertChar(literal[0]);
		return (true);
 	}
	return (false);
}

bool	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	isFloat(std::string literal)
{
	// std::cout << literal << std::endl;
	size_t	size = literal.size();
	size_t	countMantisse = 0;
	if (!literal.compare("-inff"))
	{
		convertMInf();
		return (true);
	}
	else if (!literal.compare("inff"))
	{
		convertInf();
		return (true);
	}
	else if (!literal.compare("nanf"))
	{
		convertNan();
		return (true);
	}
	if (literal[size - 1] == 'f')
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			if (literal[i] == '.' && countMantisse == 0)
				countMantisse++;
			else if ((literal[i] == '.' && countMantisse > 0 ) || !isDigit(literal[i]))
				return (false);
		}
		std::cout << "C'est un float\n";
		return (true);
	}
	return (false);
}

bool	isInt(std::string literal)
{
	size_t	i = 0;
	long	nb = 0;
	int		sign = 1;

	while (literal[i] != '\0')
	{
		while (literal[i] == 32 || (literal[i] >= 9 && literal[i] <= 13))
			i++;
		if ((literal[i] == '-') || (literal[i] == '+'))
		{
			if (literal[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (literal[i])
		{
			if (!isdigit(literal[i]))
				return (false);
			nb = nb * 10 + literal[i] - '0';
			i++;
		}
		nb *= sign;
		if (nb < INT_MIN || nb > INT_MAX)
			return (false);
		std::cout << "C'est un int" << std::endl;
		convertInt(static_cast<int>(nb));
		return (true);
	}
	return (false);
}


bool	isString(std::string literal)
{
	size_t size = literal.size();
	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(literal[i]))
		{
			std::cout << "C'est une string\n";
			convertImpossible();
			return (true);
		}
	}
	return (false);
}

bool	isDouble(std::string literal)
{
	std::cout << literal << std::endl;
	size_t	size = literal.size();
	size_t	countMantisse = 0;
	if (!literal.compare("-inf"))
	{
		convertMInf();
		return (true);
	}
	else if (!literal.compare("inf"))
	{
		convertInf();
		return (true);
	}
	else if (!literal.compare("nan"))
	{
		convertNan();
		return (true);
	}
	for (size_t i = 0; i < size; i++)
	{
		if (literal[i] == '.' && countMantisse == 0 && literal[i + 1])
			countMantisse++;
		else if ((literal[i] == '.' && countMantisse > 0 ) || !isDigit(literal[i]))
			return (false);
	}
	// convertDouble();
	return (true);
}

void	ScalarConverter::convert(std::string input)
{
	// Check if input is empty
	if (input.empty())
		return ;


	// Convert string into double and keeping the possible end string value
	char	*inputTail = NULL;
	double	nb = strtod(input.c_str(), &inputTail);
	std::string stringPart(inputTail);
	(void) nb;

	std::cout << "int min = " << INT_MIN << " int max = " << INT_MAX << std::endl; 
	
	if (isChar(input))
		return ;
	else if (isFloat(input))
		return ;
	else if (isInt(input))
		return ;
	else if (isDouble(input))
		return ;
	else if (isString(input))
		return ;


	// // Checking type of the input
	// if (stringPart.size() > 1)
	// 	std::cout << "C'est une string";
	// else if (input.size() == 1 && !isdigit(input[0]))
	// 	// convertChar(input[0]);
	// 	std::cout << "C'est un char";
	// else if (!input.compare("-inff") || !input.compare("inff") || !input.compare("nanf") || !stringPart.compare("f")) // et une autre conditions
	// 	std::cout << "C'est un float";
	// else if (!input.compare("-inf") || !input.compare("inf") || !input.compare("nan")) // et une autre conditions
	// 	std::cout << "C'est un double";
	// else
	// 	std::cout << "C'est un int";
	



	// if (!input.compare("nan") || !input.compare("nanf"))
	// 	convertNan();
	// else if (!input.compare("-inf"))
	// 	convertMInf();
	// else if (!input.compare("inf"))
	// 	convertInf();
	// else if (input.size() == 1 && !isdigit(input[0]))
	// 	convertChar(input[0]);
	// else if (stringPart.empty() && atol(input.c_str()) <= INT_MAX && atol(input.c_str()) >= INT_MIN)
	// 	convertInt(atoi(input.c_str()));
	// else if (!stringPart.compare("f"))
	// 	convertFloat(strtof(input.c_str(), &inputTail));
	// else if (!stringPart.empty())
	// 	convertImpossible();
	// else if (atof(input.c_str()))


	// else if (std::stoi(input))
	// //else if (!stringPart.empty() && stringPart.size() == 1 && (inputTail[0] == 'f' || inputTail[0] == 'F'))
	// 	convertFloat(nb, stringPart);
	// else if (stringPart.empty() && isInt(input))
	// 	convertInt(nb);
	// // // Nan
	// // else
	// {
	// 	std::cout << "char:\timpossible"<< std::endl;
	// 	std::cout << "int:\timpossible"<< std::endl;
	// 	std::cout << "float:\timpossible"<< std::endl;
	// 	std::cout << "double:\timpossible"<< std::endl;
	// }
}

void	ScalarConverter::convertChar(char c)
{
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << i << std::endl;
	std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;
}

void ScalarConverter::convertInt(int i)
{
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (c < 0 || c > 127)
		std::cout << "char:\tImpossible" << std::endl;
	else if (c < 32 || c >= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << i << std::endl;
	std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;
}




/*std::cout << "converti via un int" << std::endl;

	char	c = static_cast<char>(nb);
	int		i = static_cast<int>(nb);
	float	f = static_cast<float>(nb);
	double	d = static_cast<double>(nb);

	if (c < 0 || c > 127)
		std::cout << "char:\tImpossible" << std::endl;
	else if (c < 32 || c >= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;
	if (nb > INT_MAX || nb < INT_MIN)
		std::cout << "int:\tImpossible due to int overflow" << std::endl;
	else
		std::cout << "int:\t" << i << std::endl;
	std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;*/

void ScalarConverter::convertFloat(float f)
{
	std::cout << "converti via un float" << f << std::endl;

	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	
	// int precision = 7;
	// while (/* condition */)
	// {
	// 	/* code */
	// }
	
	if (c < 0 || c > 127)
		std::cout << "char:\tImpossible" << std::endl;
	else if (c < 32 || c >= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << i << std::endl;
	if (f > FLT_MAX)
		std::cout << "float:inf\t" << f << "f" <<std::endl;
	else if (f < -FLT_MAX)
		std::cout << "float:-inf\t" << f << "f" <<std::endl;
	else
		std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;
}



