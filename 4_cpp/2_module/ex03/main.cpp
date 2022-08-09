#include "Point.hpp"

int	main(void) {
	DEBUG(std::cout << "CONSTRUCTORS" << std::endl;)
	Point a;
	Point b(2.2f, 4.f);

	std::cout << std::endl << "= ASSIGNMENT" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << a << std::endl;
	a = b;
	std::cout << "a = " << a << std::endl;

	DEBUG(std::cout << std::endl << "CLEAN UP" << std::endl;)
	return (0);
}