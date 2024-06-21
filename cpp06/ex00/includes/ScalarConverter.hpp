#ifndef DEF_ScalarConverter
#define DEF_ScalarConverter

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <climits>
#include <float.h>
#include <string>
#include <cfloat>

class ScalarConverter
{
	public:
		~ScalarConverter();

		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs);
};

#endif
