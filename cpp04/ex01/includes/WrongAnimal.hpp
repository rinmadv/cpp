#ifndef DEF_WRONGANIMAL
#define DEF_WRONGANIMAL

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal();

		WrongAnimal & operator=(WrongAnimal const & rhs);

		std::string const & getType() const;
		
		void makeSound() const;

	protected:
		std::string _type;
};

#endif
