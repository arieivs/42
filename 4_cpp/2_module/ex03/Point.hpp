#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & src);
		~Point(void);

		Point	operator=(Point const & src);
		Fixed const &	getX(void) const;
		Fixed const &	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream &	operator<<(std::ostream & out, Point const & p);

#endif