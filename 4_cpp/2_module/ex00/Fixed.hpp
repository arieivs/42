#ifndef FIXED_HPP
# define FIXED_HPP

# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		//Fixed(parameters?);
		//Fixed(Fixed const & src);
		~Fixed(void);

		//Fixed&	operator=(Fixed const & src);

	private:
		// instance variables
};

#endif