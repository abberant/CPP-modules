#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		*_inventory[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource();

		MateriaSource	&operator=(MateriaSource const &rhs);

		void			learnMateria(AMateria*);
		AMateria		*createMateria(std::string const &type);
};