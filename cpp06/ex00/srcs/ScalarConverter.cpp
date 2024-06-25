#include "../includes/ScalarConverter.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src){*this = src;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){ (void) rhs; return (*this);}

/*********** CONVERT ***********/

bool	convertImpossible()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\timpossible"<< std::endl;
	std::cout << "double:\timpossible"<< std::endl;
	return (true);
}

bool	convertChar(char c)
{
	if (c <= 32 || c >= 126)
		std::cout << "char:\tNon printable" << std::endl;
	else
		std::cout << "char:\t"<< c << std::endl;
	std::cout << "int:\t"<< static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << ".0 " << std::endl;
	return (true);
}

bool	convertInt(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "char:\t'"<< static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	std::cout << "int:\t"<< i << std::endl;
	std::cout << "float:\t" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << ".0 " << std::endl;
	return (true);
}

bool	convertFloat(float f)
{
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	
	if (f < 0 || f > 127)
		std::cout << "char:\tImpossible" << std::endl;
	else if (c < 32 || c >= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;

	if (static_cast<long>(f) > INT_MAX || static_cast<long>(f) < INT_MIN)
		std::cout << "int:\tImpossible" << std::endl;
	else
		std::cout << "int:\t" << i << std::endl;
	std::cout << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;
	return (true);
}


bool	convertDouble(double d)
{
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	
	if (c < 0 || c > 127)
		std::cout << "char:\tImpossible" << std::endl;
	else if (c < 32 || c >= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << i << std::endl;
	std::cout << "float:\t" << f << "f" <<std::endl;
	std::cout << "double:\t" << d << std::endl;
	return (true);
}
bool	convertNan()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\tnanf"<< std::endl;
	std::cout << "double:\tnan"<< std::endl;
	return (true);
}

bool	convertInf()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\tinff"<< std::endl;
	std::cout << "double:\tinf"<< std::endl;
	return (true);
}

bool	convertMInf()
{
	std::cout << "char:\timpossible"<< std::endl;
	std::cout << "int:\timpossible"<< std::endl;
	std::cout << "float:\t-inff"<< std::endl;
	std::cout << "double:\t-inf"<< std::endl;
	return (true);
}

/*********** IDENTIFY TYPE ***********/

bool	isChar(std::string literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
		return (convertChar(literal[0]));
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
	if (!literal.compare("-inff"))
		return (convertMInf());
	else if (!literal.compare("inff"))
		return (convertInf());
	else if (!literal.compare("nanf"))
		return (convertNan());
	if (literal[literal.size() - 1] == 'f' || literal[literal.size() - 1] == 'F')
	{
		const char	*str = literal.c_str();
		char		*endPtr;
		float		floatVal = std::strtof(str, &endPtr);
		if (endPtr == str)
			return (convertImpossible());
		if (floatVal < -FLT_MAX || floatVal > FLT_MAX)
			return (convertImpossible());
		return (convertFloat(floatVal));
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
		convertInt(static_cast<int>(nb));
		return (true);
	}
	return (false);
}

bool	isDouble(std::string literal)
{
	if (!literal.compare("-inf"))
		return (convertMInf());
	else if (!literal.compare("inf"))
		return (convertInf());
	else if (!literal.compare("nan"))
		return (convertNan());
	const char	*str = literal.c_str();
	char		*endPtr;
	double		doubleVal = std::strtod(str, &endPtr);
	if (endPtr[0] || literal[literal.size() - 1] == '.')
		return (convertImpossible());
	if (doubleVal < DBL_MIN || doubleVal > DBL_MAX)
		return (convertImpossible());
	return (convertDouble(doubleVal));
}

void	ScalarConverter::convert(std::string input)
{
	if (input.empty())
		return ;
	else if (isChar(input))
		return ;
	else if (isInt(input))
		return ;
	else if (isFloat(input))
		return ;
	else if (isDouble(input))
		return ;
	convertImpossible();
}




