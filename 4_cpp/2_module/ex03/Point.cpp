#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed()) {
	return ;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
	return ;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y) {
	return ;
}

/* operator= overload should return a reference, so that a = b = c is possible
however, since _x and _y are constant it won't work
alternatives are the one below or returning a Point const &
either way, = assignment won't work... cos _x and _y are constant
so we might as well just return *this and do nothing...
*/
Point	Point::operator=(Point const & src) {
	Point	temp(src);
	return (temp);
}

Point::~Point(void) {
}

Fixed const &	Point::getX(void) const {
	return this->_x;
}

Fixed const &	Point::getY(void) const {
	return this->_y;
}

std::ostream &	operator<<(std::ostream & out, Point const & p) {
	out << "(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ")";
	return (out);
}
