#include <ScalarConverter.hpp>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (1);
	}
	std::cout << "Please enter only one argument" << std::endl;
}
