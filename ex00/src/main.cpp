#include <ScalarConverter.hpp>

/*int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (1);
	}
	std::cout << "Please enter only one argument" << std::endl;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobourge <tobourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:34:47 by tobourge          #+#    #+#             */
/*   Updated: 2025/10/19 14:33:00 by tobourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Error : Arguments needed : 1" << std::endl;
        return 1;
    }
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
    	std::cout << "\036[33m" << ">>>>> CHAR <<<<<<" << "\036[0m" << std::endl;

    	std::cout << "----------Test 'c'----------" << std::endl;
        ScalarConverter::convert("'c'");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '0'----------" << std::endl;
        ScalarConverter::convert("'0'");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '\\'----------" << std::endl;
        ScalarConverter::convert("'\\'");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '*'----------" << std::endl;
        ScalarConverter::convert("'*'");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test ' '----------" << std::endl;
        ScalarConverter::convert("' '");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '''----------" << std::endl;
        ScalarConverter::convert("'''");
    	std::cout << std::endl << std::endl;

    	std::cout << "\033[33m" << ">>>>> INT <<<<<<" << "\033[0m" << std::endl;
        
    	std::cout << "----------Test '0'----------" << std::endl;
        ScalarConverter::convert("0");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '42'----------" << std::endl;
        ScalarConverter::convert("42");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '+9'----------" << std::endl;
        ScalarConverter::convert("+9");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-99'----------" << std::endl;
        ScalarConverter::convert("-99");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'INT MAX'----------" << std::endl;
        ScalarConverter::convert("2147483647");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'INT MAX + 1'----------" << std::endl;
        ScalarConverter::convert("2147483648");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'INT MIN'----------" << std::endl;
        ScalarConverter::convert("-2147483648");
    	std::cout << std::endl << std::endl;

    	std::cout << "\033[33m" << ">>>>> FLOAT <<<<<<" << "\033[0m" << std::endl;

    	std::cout << "----------Test '42.0f'----------" << std::endl;
        ScalarConverter::convert("42.0f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-42.3f'----------" << std::endl;
        ScalarConverter::convert("-42.3f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-12.f'----------" << std::endl;
        
        ScalarConverter::convert("-12.f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '+1.2345678f'----------" << std::endl;
        ScalarConverter::convert("+1.2345678f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'long float'----------" << std::endl;
        ScalarConverter::convert("340282346638528859811704183484516925440.0000000f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'negative long float'----------" << std::endl;
        ScalarConverter::convert("-340282346638528859811704183484516925440.0000000f");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-inff'----------" << std::endl;
        ScalarConverter::convert("-inff");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '+inff'----------" << std::endl;
        ScalarConverter::convert("+inff");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'nanf'----------" << std::endl;
        ScalarConverter::convert("nanf");
    	std::cout << std::endl << std::endl;

    	std::cout << "\033[33m" << ">>>>> DOUBLE <<<<<<" << "\033[0m" << std::endl;
    	
        std::cout << "----------Test '42.0'----------" << std::endl;
        ScalarConverter::convert("42.0");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '2147483648.0'----------" << std::endl;
        ScalarConverter::convert("2147483648.0");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-2147483649.0'----------" << std::endl;
        ScalarConverter::convert("-2147483649.0");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'loooong double'----------" << std::endl;
        ScalarConverter::convert("-42000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '46.0000000'----------" << std::endl;
        ScalarConverter::convert("46.0000000");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '43.'----------" << std::endl;
        ScalarConverter::convert("43.");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '-inf'----------" << std::endl;
        ScalarConverter::convert("-inf");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test '+inf'----------" << std::endl;
        ScalarConverter::convert("+inf");
    	std::cout << std::endl << std::endl;

    	std::cout << "----------Test 'nan'----------" << std::endl;
        ScalarConverter::convert("nan");
    	std::cout << std::endl << std::endl;

    }
    return 0; 
}
