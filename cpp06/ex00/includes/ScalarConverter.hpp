#ifndef DEF_ScalarConverter
#define DEF_ScalarConverter

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <climits>
#include <float.h>
#include <string>

class ScalarConverter
{
	public:
		~ScalarConverter();


		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs);

		static void convertChar(char c);
		static void convertInt(int i);
		static void convertFloat(float f);
		static void convertDouble(double d);




};

#endif
