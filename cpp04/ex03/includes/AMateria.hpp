#ifndef DEF_AMATERIA
#define DEF_AMATERIA

#include <iostream>
#include "ICharacter.hpp"

#define INVENTORYSIZE 4

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria();

		AMateria & operator=(AMateria const & rhs);

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
