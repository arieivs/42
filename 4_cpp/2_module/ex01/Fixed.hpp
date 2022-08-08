#ifndef FIXED_HPP
# define FIXED_HPP

# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

# include <iostream>
# include <cmath>

typedef union	{
	float		f;
	struct
	{
		unsigned int	mantissa : 23;
		unsigned int	exponent : 8;
		unsigned int	signal : 1;
	};
}	union_float;

class Fixed {
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed&	operator=(Fixed const & src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_n;
		static int const	_n_fractional_bits;
};

#endif