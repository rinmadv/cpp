#ifndef DEF_ICE
#define DEF_ICE

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:

	public:
		Ice();
		Ice(Ice const & src);
		~Ice();

		Ice & operator=(Ice const & rhs);

		Ice* clone() const;
		void use(ICharacter& target);
	};

#endif
