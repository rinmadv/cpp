#ifndef DEF_ANIMAL
#define DEF_ANIMAL

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & src);
		~Animal();

		Animal & operator=(Animal const & rhs);

	private:
		std::string _type;
};

#endif
