#ifndef DEF_ANIMAL
#define DEF_ANIMAL

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();

		Animal & operator=(Animal const & rhs);

		std::string const & getType() const;
		virtual void makeSound() const;

	protected:
		std::string _type;
};

#endif
