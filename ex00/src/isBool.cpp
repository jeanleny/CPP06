#include <ScalarConverter.hpp>

bool	quoted(std::string input)
{
	return (input[0] == '\'' && input[2] == '\'');
}

bool	floatLiteral(std::string input)
{
	return (input == "-inff" || input == "+inff" || input == "nanf");
}

bool	doubleLiteral(std::string input)
{
	return (input == "-inf" || input == "+inf" || input == "nan");
}

bool	isSigned(std::string input)
{
	return (input[0] == '+' || input[0] == '-');
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
	return (it == input.end());
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

