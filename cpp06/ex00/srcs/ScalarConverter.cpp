#include "../includes/ScalarConverter.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src){*this = src;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){ (void) rhs; return (*this);}

/*********** MEMBER FUNCTION ***********/

bool	isInt(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
		if (!isdigit(input[i]))
			return false;
	return true; 
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

	// // Checking type of the input
	if (!input.compare("nan"))
		convertNan();
	else if (!input.compare("-inf"))
		convertMInf();
	else if (!input.compare("inf"))
		convertInf();
	else if (input.size() == 1 && !isdigit(input[0]))
		convertChar(input[0]);
	else if (stringPart.empty() && atol(input.c_str()) <= INT_MAX && atol(input.c_str()) >= INT_MIN)
		convertInt(atoi(input.c_str()));
	else if (!stringPart.compare("f"))
		convertFloat(strtof(input.c_str(), &inputTail));
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
	
	int precision = 7;
	while (/* condition */)
	{
		/* code */
	}
	
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



