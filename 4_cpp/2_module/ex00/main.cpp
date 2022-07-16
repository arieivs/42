#include "Fixed.hpp"

int	main(void) {
	std::cout << "DEFAULT" << std::endl;
	Fixed a;

	std::cout << std::endl << "COPY" << std::endl;
	Fixed b(a);

	std::cout << std::endl << "OPERATOR =" << std::endl;
	Fixed c;
	c = b;

	std::cout << std::endl << "CHECK VALUES" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << "CLEAN UP" << std::endl;
	return (0);
}