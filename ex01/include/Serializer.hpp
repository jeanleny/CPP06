#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.h"
#include <stdint.h>

class Serializer
{
	public :
		static	uintptr_t serialize(Data *ptr);
		static	Data* deserialize(uintptr_t raw);
	private :
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();
};

#endif 
