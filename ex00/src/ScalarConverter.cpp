#include <ScalarConverter.hpp>
#include <stdlib.h>
#include <limits>
#include <limits.h>
#include <float.h>
#include <iomanip>
#include <cctype>
#include <unistd.h>

bool	isSigned(std::string input)
{
	if (input[0] == '+' || input[0] == '-')
		return(true);
	return (false);
}

bool isDisplayable(std::string input)
{
	int nb = std::atoi(input.c_str());
	if (nb > 0 && nb < 127)
	{
		if (std::isprint(nb))
			return (true);
	}
	return (false);
}

bool	 isInt(std::string input)
{
	std::string::iterator it = input.begin();

	if (isSigned(input))
		it++;
	while(it != input.end() && std::isdigit(*it))
		it++;
	if (it == input.end())
		return (true);
	return (false);
}

bool	isFloatComp(char c)
{
	return (c == '.' || c == 'f' || c == '-' || c == '+');
}

bool	isFloat(std::string input)
{
	std::string::iterator it = input.begin();

	while (it != input.end() && (std::isdigit(*it) || isFloatComp(*it)))
		it++;
	if (it == input.end())
		return (true);
	return (false);
}

bool	floatLiteral(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	return (false);
}

bool	doubleLiteral(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

void	displayInt(std::string input)
{
	long double result;

	if (!isInt(input) && !isFloat(input) && input.size() != 1)
	{
		std::cout << "int : Impossible" << std::endl;
		return ;
	}
	if (!isInt(input) && input.size() == 1)
		result = *input.c_str();
	else
		result = std::strtold(input.c_str(), NULL);
	if (result > INT_MAX || result < INT_MIN)
	{
		std::cout << "int : Overflow" << std::endl;
		return ;
	}
	std::cout << "int : " << std::setprecision(1) << static_cast<int>(result) << std::endl;
}

void	displayDouble(std::string input)
{
	long double result;
	bool		literal = true;
	
	if (!doubleLiteral(input))
		literal = false;
	if ((!isFloat(input) && input.size() != 1) && !literal)
	{
		std::cout << "double : Impossible" << std::endl;
		return;
	}
	if (!isFloat(input) && input.size() == 1)
		result = *input.c_str();
	else
		result = std::strtold(input.c_str(), NULL);
	if (!literal)
	{
		if (result > DBL_MAX)
		{
			std::cout << "double : Overflow" << std::endl;
			return ;
		}
	}
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(result) << std::endl;
}


void	displayFloat(std::string input)
{
	long double result;
	bool		literal = true;
	
	if (!doubleLiteral(input) && !floatLiteral(input))
		literal = false;
	if ((!isFloat(input) && input.size() != 1) && !literal && !isInt(input))
	{
			std::cout << "float : Impossible" << std::endl;
			return;
	}
	if (!isFloat(input) && input.size() == 1)
		result = *input.c_str();
	else
		result = std::strtold(input.c_str(), NULL);
	if (!literal)
	{
		if (result > FLT_MAX || result < -FLT_MAX)
		{
			std::cout << "float : Overflow" << std::endl;
			return ;
		}
	}
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
}

void	displayChar(std::string input)
{
	int result;

	if (!isFloat(input) && !isInt(input) && input.size() != 1)
	{
		std::cout << "char : Impossible" << std::endl;
		return ;
	}
	if (isInt(input) && !isDisplayable(input))
	{
		std::cout << "char : undisplayable" << std::endl;
		return ;
	}
	if (isInt(input))
		result = std::atoi(input.c_str());
	else
		result = *input.c_str();
	std::cout << "char : '" << static_cast<char>(result) << "'" << std::endl;
}

bool	quoted(std::string input)
{
	return (input[0] == '\'' && input[2] == '\'');
}

void	displayCast(std::string input)
{
	if (input.length() == 3 && quoted(input))
		input = input[1];
	displayChar(input);
	displayInt(input);
	displayFloat(input);
	displayDouble(input);
}

void	ScalarConverter::convert(std::string input)
{
	displayCast(input);
}
