#include "Fixed.hpp"

int	main(void) {
	std::cout << "CONSTRUCTING..." << std::endl;
	Fixed a(5.05f);
	Fixed b(2);
	Fixed c(0);
	Fixed d(999.9f);
	Fixed e(419430);

	std::cout << std::endl << "COMPARISON OPERATORS" << std::endl;
	std::cout << ((a > b) ? "a > b" : "a is not > b") << std::endl;
	std::cout << ((a >= b) ? "a >= b" : "a is not >= b") << std::endl;
	std::cout << ((a < b) ? "a < b" : "a is not < b") << std::endl;
	std::cout << ((a <= b) ? "a <= b" : "a is not <= b") << std::endl;
	std::cout << ((a == b) ? "a == b" : "a is not == b") << std::endl;
	std::cout << ((a != b) ? "a != b" : "a is not != b") << std::endl;

	std::cout << std::endl << "ARITHMETIC OPERATORS" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a * d = " << (a * d) << std::endl;
	std::cout << "b * d = " << (b * d) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "a / d = " << (a / d) << std::endl;
	std::cout << "d / b = " << (d / b) << std::endl;
	std::cout << "c / a = " << (c / a) << std::endl;
	std::cout << "d / c = " << (d / c) << std::endl;
	std::cout << "e * b = " << (e * b) << std::endl;

	std::cout << std::endl << "CLEAN UP" << std::endl;
	return (0);
}