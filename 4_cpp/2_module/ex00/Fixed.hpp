#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(Fixed const & src);

	private:
		int					_n;
		static int const	_n_fractional_bits;
};

#endif