#ifndef POINT_HPP
# define POINT_HPP

# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(float const x, float const y);
		Point &	operator=(Point const & src);
		Point(Point const & src);
		~Point(void);

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream &	operator<<(std::ostream & out, Point const & p);

#endif