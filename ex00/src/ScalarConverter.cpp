#include <ScalarConverter.hpp>
#include <ScalarBool.h>

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
	if (isFloat(input) && !isDisplayable(input))
	{
		std::cout << "char : undisplayable" << std::endl;
		return ;
	}
	if (isFloat(input))
		result = std::atoi(input.c_str());
	else
		result = *input.c_str();
	std::cout << "char : '" << static_cast<char>(result) << "'" << std::endl;
}


void	displayCast(std::string input)
{
	if (input.length() == 3 && quoted(input))
	{
		input = input[1];
		if (std::isdigit(input[0]))
			std::cout << "char : '" << static_cast<char>(input[0]) << "'" << std::endl;
		else
			displayChar(input);
	}
	else 
		displayChar(input);
	displayInt(input);
	displayFloat(input);
	displayDouble(input);
}

void	ScalarConverter::convert(std::string input)
{
	displayCast(input);
}
