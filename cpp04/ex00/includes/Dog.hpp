#ifndef DEF_DOG
#define DEF_DOG

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & rhs);
		void makeSound() const;

	private:
};

#endif
