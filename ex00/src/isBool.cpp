#include <ScalarConverter.hpp>

bool	isSigned(std::string input)
{
	return (input[0] == '+' || input[0] == '-');
}

bool	multSign(std::string input)
{
	size_t i = 0;
	while (input[i] && (input[i] == '+' || input [i] == '-'))
	{
		i++;
		if (i > 1)
			return (true);
	}
	return (false);
}

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

bool	onlySign(std::string input)
{
	return (input.size() == 1 && isSigned(input));
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

bool	isFloatComp(char c, bool *p, bool *f)
{
	if (c == '.' && *p)
		return(false);
	else if (c == '.')
		*p = true;
	if ((c == 'f' || c == 'F') && *f)
		return(false);
	else if (c == 'f' || c == 'F')
		*f = true;
	return (c == '.' || c == 'f' || c == 'F' || c == '-' || c == '+');
}

bool	isFloat(std::string input)
{
	std::string::iterator it = input.begin();
	bool	p = false;
	bool	f = false;

	while (it != input.end() && (std::isdigit(*it) || isFloatComp(*it, &p, &f)))
		it++;
	if (it == input.end())
		return (true);
	return (false);
}

