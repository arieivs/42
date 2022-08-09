#include "Point.hpp"

Point::Point(void) {
	DEBUG(std::cout << "Default constructor called" << std::endl;)
	this->_x = Fixed();
	this->_y = Fixed();
	return ;
}

Point::Point(float const x, float const y) {
	DEBUG(std::cout << "Float constructor called" << std::endl;)
	this->_x = Fixed(x);
	this->_y = Fixed(y);
	return ;
}

Point &	Point::operator=(Point const & src) {
	DEBUG(std::cout << "Copy assignment operator called" << std::endl);
	if (this != &src) {
		this->_x = src._x;
		this->_y = src._y;
	}
	return (*this);
}

Point::Point(Point const & src) {
	DEBUG(std::cout << "Copy constructor called" << std::endl;)
	*this = src;
	return ;
}

Point::~Point(void) {
	DEBUG(std::cout << "Destructor called" << std::endl;)
}

std::ostream &	Point::operator<<(std::ostream & out, Point const & p) {
	out << p
}