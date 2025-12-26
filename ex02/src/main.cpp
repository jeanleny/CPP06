#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand(time(NULL));
	if (rand() % 3 == 0)
	{
		std::cout << "A class generated" << std::endl;
		return (new A);
	}
	if (rand() % 2 == 0)
	{
		std::cout << "B class generated" << std::endl;
		return (new B);
	}
	std::cout << "C class generated" << std::endl;
	return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast <A *>(p))
		std::cout << "Base pointer is A" << std::endl;
	if (dynamic_cast <B *>(p))
		std::cout << "Base pointer is B" << std::endl;
	if (dynamic_cast <C *>(p))
		std::cout << "Base pointer is C" << std::endl;
	std::cout << "Unkown base pointer" << std::endl;
}

void identify(Base &p)
{
	Base test;
	try 
	{
		test = dynamic_cast<A &>(p);
		std::cout << "Base reference is A" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try 
	{
		test = dynamic_cast<B &>(p);
		std::cout << "Base reference is B" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try 
	{
		test = dynamic_cast<C &>(p);
		std::cout << "Base reference is C" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	std::cout << "Unkown Base reference" << std::endl;
}

int main()
{
	Base *rdm = NULL;
	identify(rdm);
	identify (*rdm);
}
