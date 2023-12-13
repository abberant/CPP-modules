#pragma once

#include "ICharacter.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria();

		AMateria & operator=(AMateria const & rhs);

		std::string const & getType() const;

		virtual void		use(ICharacter& target);
		virtual AMateria	*clone() const = 0;
};