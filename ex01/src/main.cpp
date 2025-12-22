#include "Serializer.hpp"

int main ()
{
	Data	*test = new Data;
	test->c = 'a';
	test->nb = 8;
	std::cout << "Data adress = " << test << std::endl;
	std::cout << "Data char = " << test->c << std::endl;
	std::cout << "Data int = " << test->nb << std::endl;

	uintptr_t key = Serializer::serialize(test);
	std::cout << "Key = " << key << std::endl;\

	Data	*result = Serializer::deserialize(key);
	std::cout << "Result adress = "<< result << std::endl;
	std::cout << "Result char = " << result->c << std::endl;
	std::cout << "Result nb = " << result->nb << std::endl;

	std::cout << "--NULL VALUES--" << std::endl;
	Data *riengue = NULL;
	uintptr_t nkey = Serializer::serialize(riengue);
	std::cout << nkey << std::endl;
	Data	*nresult = Serializer::deserialize(nkey);
	std::cout << "Nresult adress = "<< nresult << std::endl;
	delete test;
}
