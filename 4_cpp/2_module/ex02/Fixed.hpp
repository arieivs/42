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
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		bool	Fixed>(Fixed cosnt & other) const;

	private:
		int					_n;
		static int const	_n_fractional_bits;
};

std::ostream &	operator<<(std::ostream & out, Fixed const & n);

#endif