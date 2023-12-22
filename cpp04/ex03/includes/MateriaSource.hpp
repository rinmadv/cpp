#ifndef DEF_MATERIASOURCE
#define DEF_MATERIASOURCE

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:// ou private ?
		AMateria	*_inventory[INVENTORYSIZE];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const & rhs);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	};

#endif
