#include "Fixed.hpp"

int const	Fixed::_n_fractional_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return ;
}

/* Int to Fixed point:
We need extra 8 bits in the end for fixed point fractional bits,
thus we need to shit 8 bits to the left. */
Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << _n_fractional_bits;
	DEBUG(std::cout << "Value stored: " << this->_n << std::endl;)
	return ;
}

Fixed::Fixed(float const n) {
	int			exponent;
	union_float	uf;

	std::cout << "Float constructor called" << std::endl;
	/* previous ideas
	rounded = roundf(n);
	exponent_f = (n * (1 << 23) * (1 >> 24)); // not working
	exponent = (int)(n * (1 << 1) * (1 >> 23)) - 127; // not working
	std::cout << "Exponent of " << n << ": " << exponent_f << " h " << exponent << " r " << rounded << std::endl;
	*/
	uf.f = n;
	DEBUG(std::cout << "Signal: " << uf.signal << " Exponent: " << uf.exponent << " Mantissa: " << uf.mantissa << std::endl;)
	exponent = uf.exponent - EXP_BIAS;
	DEBUG(std::cout << "Actual exponent (bias corrected): " << exponent << std::endl;)
	
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
