#include "Fixed.hpp"

int	main(void) {
	std::cout << "CONSTRUCTORS" << std::endl;
	Fixed a(-9.99f);
	Fixed b(-9.99f);

	std::cout << std::endl << "COMPARISON OPERATORS" << std::endl;
	std::cout << ((a > b) ? "a > b" : "a is not > b") << std::endl;
	std::cout << ((a >= b) ? "a >= b" : "a is not >= b") << std::endl;
	std::cout << ((a < b) ? "a < b" : "a is not < b") << std::endl;
	std::cout << ((a <= b) ? "a <= b" : "a is not <= b") << std::endl;
	std::cout << ((a == b) ? "a == b" : "a is not == b") << std::endl;
	std::cout << ((a != b) ? "a != b" : "a is not != b") << std::endl;

	std::cout << std::endl << "CLEAN UP" << std::endl;
	return (0);
}