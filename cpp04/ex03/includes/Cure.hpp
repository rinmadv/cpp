#ifndef DEF_CURE
#define DEF_CURE

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:

	public:
		Cure();
		Cure(Cure const & src);
		~Cure();

		Cure & operator=(Cure const & rhs);

		Cure* clone() const;
		void use(ICharacter& target);
	};

#endif
