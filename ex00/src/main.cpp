#include <iostream>

#include "ScalarConverter.hpp"

static void displayTest(const std::string& testName)
{
	std::cout << std::endl << std::endl;
	std::cout << "\033[33m" << "---------- " << testName << " Test ----------" << "\033[0m" << std::endl;
}

static void unitTestChar()
{
	displayTest("'c'");
	ScalarConverter::convert("'c'");
	
	displayTest("'0'");
	ScalarConverter::convert("'0'");
	
	displayTest("'\\'");
	ScalarConverter::convert("'\\'");
	
	displayTest("'*'");
	ScalarConverter::convert("'*'");
	
	displayTest("'\t'");
	ScalarConverter::convert("'\t'");
	
	displayTest("' '");
	ScalarConverter::convert("' '");
	
	displayTest("'''");
	ScalarConverter::convert("'''");
}

static void unitTestInt()
{
	displayTest("0");
	ScalarConverter::convert("0");

	displayTest("42");
	ScalarConverter::convert("42");

	displayTest("00");
	ScalarConverter::convert("00");

	displayTest("+9");
	ScalarConverter::convert("+9");

	displayTest("-99");
	ScalarConverter::convert("-99");

	displayTest("-09");
	ScalarConverter::convert("-09");

	displayTest("2147483647");
	ScalarConverter::convert("2147483647");
	std::cout << 2147483647 << " <=> " << static_cast<float>(2147483647) << " <=> " << static_cast<double>(2147483647) << std::endl;

	displayTest("-2147483648");
	ScalarConverter::convert("-2147483648");
}

static void unitTestFloat()
{
	displayTest("42.0f");
	ScalarConverter::convert("42.0f");
	
	displayTest("-42.3f");
	ScalarConverter::convert("-42.3f");
	
	displayTest("-07.2F");
	ScalarConverter::convert("-07.2F");
	
	displayTest("-12.f");
	ScalarConverter::convert("-12.f");
	
	displayTest("+12.F");
	ScalarConverter::convert("+12.F");
	
	displayTest("+1.2345678f");
	ScalarConverter::convert("+1.2345678f");
	
	displayTest("340282346638528859811704183484516925440.0000000f");
	ScalarConverter::convert("340282346638528859811704183484516925440.0000000f");
	
	displayTest("-340282346638528859811704183484516925440.0000000f");
	ScalarConverter::convert("-340282346638528859811704183484516925440.0000000f");

	displayTest("-inff");
	ScalarConverter::convert("-inff");

	displayTest("+inff");
	ScalarConverter::convert("+inff");

	displayTest("nanf");
	ScalarConverter::convert("nanf");
}

static void unitTestDouble()
{
	displayTest("42.0");
	ScalarConverter::convert("42.0");

	displayTest("2147483648.0");
	ScalarConverter::convert("2147483648.0");

	displayTest("-2147483649.0");
	ScalarConverter::convert("-2147483649.0");
	std::cout << static_cast<float>(-2147483649.0) << " <=> " << -2147483649.0 << std::endl;

	displayTest("-42000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	ScalarConverter::convert("-42000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	std::cout << -42000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0 << std::endl;

	displayTest("46.0000000");
	ScalarConverter::convert("46.0000000");

	displayTest("43.");
	ScalarConverter::convert("43.");

	displayTest("-inf");
	ScalarConverter::convert("-inf");

	displayTest("+inf");
	ScalarConverter::convert("+inf");

	displayTest("nan");
	ScalarConverter::convert("nan");
}

static void unitTestError()
{
	displayTest(" ");
	ScalarConverter::convert(" ");

	displayTest("s");
	ScalarConverter::convert("s");

	displayTest("'24'");
	ScalarConverter::convert("'24'");

	displayTest("''");
	ScalarConverter::convert("''");

	displayTest("'38");
	ScalarConverter::convert("'38");

	displayTest("");
	ScalarConverter::convert("");

	displayTest("         ");
	ScalarConverter::convert("            ");

	displayTest("1234 ");
	ScalarConverter::convert("1234 ");

	displayTest("56 78");
	ScalarConverter::convert("56 78");

	displayTest(" 9876");
	ScalarConverter::convert(" 9876");

	displayTest("54v32");
	ScalarConverter::convert("54v32");

	displayTest("-+34");
	ScalarConverter::convert("-+34");

	displayTest("1*12");
	ScalarConverter::convert("1*12");

	displayTest("2147483648");
	ScalarConverter::convert("2147483648");

	displayTest("-2147483649");
	ScalarConverter::convert("-2147483649");

	displayTest("-inf.");
	ScalarConverter::convert("-inf.");

	displayTest("+inf.f");
	ScalarConverter::convert("+inf.f");

	displayTest(".nan");
	ScalarConverter::convert(".nan");
}

static void unitTest()
{
	unitTestChar();
	unitTestInt();
	unitTestFloat();
	unitTestDouble();
	unitTestError();
}

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		std::cout << "Too many parameters" << std::endl;
		return 1;
	}
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		unitTest();
	return 0;
}
