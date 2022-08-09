#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed()) {
	DEBUG(std::cout << "Default constructor called" << std::endl;)
	return ;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
	DEBUG(std::cout << "Float constructor called" << std::endl;)
	return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {
	DEBUG(std::cout << "Fixed constructor called" << std::endl;)
	return ;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y) {
	DEBUG(std::cout << "Copy constructor called" << std::endl;)
	return ;
}

/* const or non const TODO*/
Point	Point::operator=(Point const & src) {
	DEBUG(std::cout << "Copy assignment operator called" << std::endl);
	Point	temp(src);
	return (temp);
}

Point::~Point(void) {
	DEBUG(std::cout << "Destructor called" << std::endl;)
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