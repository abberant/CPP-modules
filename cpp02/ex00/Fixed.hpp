#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:

		static const int	_fractionalBits = 8;
		int					_rawBits;
	
	public:

		Fixed(void);
		Fixed(const Fixed &other);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif