#include "../includes/C.hpp"

/*********** CONSTRUCTORS, DESTRUCTORS AND AFFECTATION OPERATOR ***********/

C::C() : Base(){
	if (DEBUG)
		std::cout << "Class C created" << std::endl;
}
C::~C(){}

/*********** MEMBER FUNCTION ***********/

// uintptr_t A::serialize(Data* ptr){
// 	if (DEBUG)
// 	{
// 		std::cout << _BOLD _PURPLE"Serialize function: " << _END << std::endl;
// 		std::cout << "Address of ptr: " << ptr << std::endl;
// 		std::cout << "Integer representation: " << reinterpret_cast<uintptr_t>(ptr) << std::endl;
// 		std::cout << std::endl;

// 	}
//     return reinterpret_cast<uintptr_t>(ptr);
// }

// Data* A::deserialize(uintptr_t rawValue){
// 	if (DEBUG)
// 	{
// 		std::cout << _BOLD _PURPLE"Deserialize function: " << _END << std::endl;
// 		std::cout << "Integer representqtion of ptr: " << rawValue << std::endl;
// 		Data *ptr = reinterpret_cast<Data*>(rawValue);
// 		std::cout << "New pointer: " << ptr << std::endl;
// 		std::cout << "Data from new pointer: " << ptr->name << " " << ptr->surname << ", " << ptr->age << std::endl;
// 		std::cout << std::endl;
// 	}
// 	return reinterpret_cast<Data*>(rawValue);
// }

