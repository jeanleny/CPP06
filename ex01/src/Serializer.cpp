#include <Serializer.hpp>

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t key;

	key = reinterpret_cast<uintptr_t>(ptr);
	return (key);	
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	key;
	
	key = reinterpret_cast<Data*>(raw);
	return(key);
}
