#ifndef DEF_Serializer
#define DEF_Serializer

#include <iostream>
#include "Format.hpp"
#include "data.h"

#define DEBUG true

class Serializer
{
	public:
		~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t rawValue);
       
	private:
		Serializer();
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & rhs);
};

#endif
