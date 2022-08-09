#ifndef FIXED_HPP
# define FIXED_HPP

# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed &	operator=(Fixed const & src);
		Fixed(Fixed const & src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(Fixed const & other) const;
		bool	operator<(Fixed const & other) const;
		bool	operator>=(Fixed const & other) const;
		bool	operator<=(Fixed const & other) const;
		bool	operator==(Fixed const & other) const;
		bool	operator!=(Fixed const & other) const;

		Fixed	operator+(Fixed const & other) const;
		Fixed	operator-(Fixed const & other) const;
		Fixed	operator*(Fixed const & other) const;
		Fixed	operator/(Fixed const & other) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed &			max(Fixed & foo, Fixed & bar);
		static Fixed const &	max(Fixed const & foo, Fixed const & bar);
		static Fixed &			min(Fixed & foo, Fixed & bar);
		static Fixed const &	min(Fixed const & foo, Fixed const & bar);

	private:
		int					_n;
		static int const	_n_fractional_bits;
};

std::ostream &	operator<<(std::ostream & out, Fixed const & n);

#endif