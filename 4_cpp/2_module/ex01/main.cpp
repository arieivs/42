#include "Fixed.hpp"

int	main(void) {
	std::cout << "DEFAULT" << std::endl;
	Fixed a;

	std::cout << std::endl << "FROM INT" << std::endl;
	Fixed const b( -10 );

	std::cout << std::endl << "FROM FLOAT" << std::endl;
	Fixed const c( -0.042f );

	std::cout << std::endl << "COPY" << std::endl;
	Fixed const d( b );

	std::cout << std::endl << "OPERATOR =" << std::endl;
	a = Fixed( 1234.4321f );

	// std::cout << std::endl << "CHECK VALUES" << std::endl;
	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	std::cout << std::endl << "CONVERT TO FLOAT" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	std::cout << std::endl << "CONVERT TO INT" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "CLEAN UP" << std::endl;
	return (0);
}