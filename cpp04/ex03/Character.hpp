#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character();
		Character(std::string const &name);
		Character(Character const &other);
		virtual ~Character();

		Character	&operator=(Character const &rhs);

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};