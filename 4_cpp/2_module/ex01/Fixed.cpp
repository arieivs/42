#include "Fixed.hpp"

int const	Fixed::_n_fractional_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	(void) n; // tmp
	// TODO
	return ;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	(void) n; // tmp
	// TODO
	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_n = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_n;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}

float	Fixed::toFloat(void) const {
	float	f;
	// TODO
	f = 1.2; // tmp
	return (f);
}

int		Fixed::toInt(void) const {
	int	n;
	// TODO
	n = 1; // tmp
	return (n);
}
