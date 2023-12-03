#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif