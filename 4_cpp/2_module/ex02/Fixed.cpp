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
	return ;
}

/* Float to Fixed point:
n * (1 << _n_fractional_bits) => we're multiplying by 2^_n_fractional_bits
this way, we will convert it to an int, 2^_n_fractional_bits bigger than what it "should" be
so that we accomodate for the bits being used for the fractional part
https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
*/
Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->_n = (int)roundf(n * (1 << _n_fractional_bits));
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

	DEBUG(std::cout << "Converting Fixed point to Int" << std::endl;)
	n = this->_n >> _n_fractional_bits;
	return (n);
}

float	Fixed::toFloat(void) const {
	float	f;
	
	DEBUG(std::cout << "Converting Fixed point to Float" << std::endl;)
	f = (float)this->_n / (float)(1 << _n_fractional_bits);
	return (f);
}

std::ostream &	operator<<(std::ostream & out, Fixed const & n) {
	out << n.toFloat();
	return out;
}

bool	Fixed::operator>(Fixed const & other) const {
	return this->_n > other._n;
}

bool	Fixed::operator<(Fixed const & other) const {
	return this->_n < other._n;
}

bool	Fixed::operator>=(Fixed const & other) const {
	return this->_n >= other._n;
}

bool	Fixed::operator<=(Fixed const & other) const {
	return this->_n <= other._n;
}

bool	Fixed::operator==(Fixed const & other) const {
	return this->_n == other._n;
}

bool	Fixed::operator!=(Fixed const & other) const {
	return this->_n != other._n;
}

Fixed	Fixed::operator+(Fixed const & other) const {
	return this->_n + other._n;
}

Fixed	Fixed::operator-(Fixed const & other) const {
	return this->_n - other._n;
}

Fixed	Fixed::operator*(Fixed const & other) const {
	return this->_n * other._n;
}

Fixed	Fixed::operator/(Fixed const & other) const {
	return this->_n / other._n; // TODO check for edge cases
}
