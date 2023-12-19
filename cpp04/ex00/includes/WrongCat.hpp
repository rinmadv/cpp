#ifndef DEF_WRONGCAT
#define DEF_WRONGCAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat & operator=(WrongCat const & rhs);

	private:
		void makeSound() const;
};

#endif
