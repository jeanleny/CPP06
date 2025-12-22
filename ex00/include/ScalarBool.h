#ifndef SCALAR_BOOL_H
# define SCALAR_BOOL_H

#include <ScalarConverter.hpp>

bool	quoted(std::string input);
bool	floatLiteral(std::string input);
bool	doubleLiteral(std::string input);
bool	isSigned(std::string input);
bool 	isDisplayable(std::string input);
bool	 isInt(std::string input);
bool	isFloatComp(char c);
bool	isFloat(std::string input);

#endif
