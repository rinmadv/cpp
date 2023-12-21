#ifndef DEF_DOG
#define DEF_DOG

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & rhs);

		void makeSound() const;
		std::string const &  getIdea(const int id) const;
		void setIdea(const int id, const std::string& idea);

	private:
		Brain *_brain;
};

#endif
