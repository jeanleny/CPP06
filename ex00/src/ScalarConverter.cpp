#include <ScalarConverter.hpp>
#include <stdlib.h>
#include <limits>
#include <limits.h>
#include <iomanip>

bool	specialData(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

void	displayInt(long double result)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		std::cout << "Int : Overflow" << std::endl;
		return ;
	}
	std::cout << std::setprecision(1) << static_cast<int>(result) << std::endl;
}

void	displayCast(std::string input)
{
	long double result = std::strtold(input.c_str(), NULL);
	displayInt(result);
	//displayFloat(result);
	//displayDouble(result);
	//displayChar(result);
}

void	ScalarConverter::convert(std::string input)
{
	displayCast(input);
	//double result = std::strtod(input.c_str(), NULL);
}
