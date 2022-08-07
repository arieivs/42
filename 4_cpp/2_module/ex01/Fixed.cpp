#include "Fixed.hpp"

int const	Fixed::_n_fractional_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return ;
}

/* int = 32 bits
fixed point = 24 bits int + last 8 bits for fractional part
thus we need to shit 8 bits to the left */
Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << _n_fractional_bits;
	DEBUG(std::cout << "Value stored: " << this->_n << std::endl;)
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

/* we need to shit 8 bits to the right */
int		Fixed::toInt(void) const {
	int	n;

	n = this->_n >> _n_fractional_bits;
	return (n);
}

float	Fixed::toFloat(void) const {
	float	f;
	// TODO
	f = 1.2; // tmp
	return (f);
}
