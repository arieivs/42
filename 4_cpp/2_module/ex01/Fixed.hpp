#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_n;
		static int const	_n_fractional_bits;
};

#endif