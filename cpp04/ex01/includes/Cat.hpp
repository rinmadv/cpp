#ifndef DEF_CAT
#define DEF_CAT

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & src);
		~Cat();

		Cat & operator=(Cat const & rhs);
		void makeSound() const;
		std::string const &  getIdea(const int id) const;
		void setIdea(const int id, const std::string& idea);
		
	private:
		Brain *_brain;
};

#endif
