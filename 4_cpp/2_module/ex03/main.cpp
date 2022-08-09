#include "Point.hpp"

int	main(void) {
	DEBUG(std::cout << "CONSTRUCTORS" << std::endl;)
	Point	a;
	Point	b(2.2f, 4.f);
	Point	c(Fixed(3), Fixed(5.5f));
	Point	d(b);

	std::cout << std::endl << "POINTS" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	a = b = c = d;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	DEBUG(std::cout << std::endl << "CLEAN UP" << std::endl;)
	return (0);
}