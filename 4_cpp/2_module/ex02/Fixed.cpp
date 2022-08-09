#include "Fixed.hpp"

int const	Fixed::_n_fractional_bits = 8;

Fixed::Fixed(void) {
	DEBUG(std::cout << "Default constructor called" << std::endl;)
	this->_n = 0;
	return ;
}

/* Int to Fixed point:
We need extra 8 bits in the end for fixed point fractional bits,
thus we need to shit 8 bits to the left. */
Fixed::Fixed(int const n) {
	DEBUG(std::cout << "Int constructor called" << std::endl;)
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
	DEBUG(std::cout << "Float constructor called" << std::endl;)
	this->_n = (int)roundf(n * (1 << _n_fractional_bits));
	return ;
}

Fixed::Fixed(Fixed const & src) {
	DEBUG(std::cout << "Copy constructor called" << std::endl;)
	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	DEBUG(std::cout << "Destructor called" << std::endl;)
	return ;
}

Fixed&	Fixed::operator=(Fixed const & src) {
	DEBUG(std::cout << "Copy assignment operator called" << std::endl;)
	if (this != &src)
		this->_n = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	DEBUG(std::cout << "getRawBits member function called" << std::endl;)
	return this->_n;
}

void	Fixed::setRawBits(int const raw) {
	DEBUG(std::cout << "setRawBits member function called" << std::endl;)
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
	Fixed	result;

	result.setRawBits(this->_n + other._n);
	return result;
}

Fixed	Fixed::operator-(Fixed const & other) const {
	Fixed	result;

	result.setRawBits(this->_n - other._n);
	return result;
}

/* Multiplication:
Fixed point => we're multiplying the "int" represented there by 2^-_fractional_bits
thus a * b = bin_a * 2^-8 * bin_b * 2_-8 = bin_a * bin_b * 2^-16 = a * bin_b * 2^-8
thus we need to correct the order of magnitude afterwards by * 2^-8
which is why we bitshift >> _n_fractional_bits
https://www.allaboutcircuits.com/technical-articles/multiplication-examples-using-the-fixed-point-representation/
Note that the highest value a fixed point can have is 2^(32-1-8) = 2^23 = 8 388 608
thus we cast it to (signed long long) to be less limiting.
*/
Fixed	Fixed::operator*(Fixed const & other) const {
	Fixed	result;

	result.setRawBits(((signed long long)this->_n * (signed long long)other._n) >> _n_fractional_bits);
	return result;
}

/* Division by 0 leads to error */
Fixed	Fixed::operator/(Fixed const & other) const {
	Fixed	result;

	result.setRawBits(((signed long long)this->_n << _n_fractional_bits) / other._n);
	return result;
}

/* Pre and Post In/decrementing:
Pre - in/decrement it and then return it to do whatever with the updated value
Post - create a copy, in/decrement the original, and then return the copy to do
       whatever with the old value
	 - it receives a dummy int (standard/for differentiation purposes I think)
https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
*/
Fixed	Fixed::operator++(void) {
	this->_n++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	copy = Fixed(*this);

	this->_n++;
	return (copy);
}

Fixed	Fixed::operator--(void) {
	this->_n--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	copy = Fixed(*this);

	this->_n--;
	return (copy);
}

Fixed &	Fixed::max(Fixed & foo, Fixed & bar) {
	if (bar > foo)
		return (bar);
	return (foo);
}

Fixed const &	Fixed::max(Fixed const & foo, Fixed const & bar) {
	if (bar > foo)
		return (bar);
	return (foo);
}

Fixed &	Fixed::min(Fixed & foo, Fixed & bar) {
	if (bar < foo)
		return (bar);
	return (foo);
}

Fixed const &	Fixed::min(Fixed const & foo, Fixed const & bar) {
	if (bar < foo)
		return (bar);
	return (foo);
}
