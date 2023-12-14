#ifndef DEF_DOG
#define DEF_DOG

#include <Animal.hpp>

class Dog
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & rhs);

	private:
		std::string _type;
};

#endif
