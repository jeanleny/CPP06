#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <limits.h>
#include <float.h>
#include <iomanip>
#include <cctype>

class ScalarConverter
{
	public :
		static void	convert(std::string input);
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
};

#endif
