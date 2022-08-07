#ifndef FIXED_HPP
# define FIXED_HPP

# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

# define INT_SIZE 32
/* Float Exponent Mask: 01111111100000000000000000000000
equivalent to 1.0 * 2^(255-127) = 3,402823669E38 
# define EXP_MASK 2139095040*/ // old stuff
# define SIG_BITS 1
# define EXP_BITS 8
# define MANT_BITS 23
# define EXP_BIAS 127
# include <iostream>
# include <cmath>

typedef union	{
	float		f;
	struct
	{
		unsigned int	mantissa : MANT_BITS;
		unsigned int	exponent : EXP_BITS;
		unsigned int	signal : SIG_BITS;
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