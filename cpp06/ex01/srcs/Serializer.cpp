#include "../includes/Serializer.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

Serializer::Serializer() {}
Serializer::Serializer(Serializer const & src){*this = src;}
Serializer::~Serializer(){}
Serializer & Serializer::operator=(Serializer const & rhs){ (void) rhs; return (*this);}

/*********** MEMBER FUNCTION ***********/

uintptr_t Serializer::serialize(Data* ptr)
{
	if (DEBUG)
	{
		std::cout << _BOLD _PURPLE"Serialize function: " << _END << std::endl;
		std::cout << "Address of ptr: " << ptr << std::endl;
		std::cout << "Integer representation: " << reinterpret_cast<uintptr_t>(ptr) << std::endl;
		std::cout << std::endl;
	}
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t rawValue)
{
	if (DEBUG)
	{
		std::cout << _BOLD _PURPLE"Deserialize function: " << _END << std::endl;
		std::cout << "Integer representation of ptr: " << rawValue << std::endl;
		Data *ptr = reinterpret_cast<Data*>(rawValue);
		std::cout << "New pointer: " << ptr << std::endl;
		std::cout << "Data from new pointer: " << ptr->name << " " << ptr->surname << ", " << ptr->age << std::endl;
		std::cout << std::endl;
	}
	return reinterpret_cast<Data*>(rawValue);
}

