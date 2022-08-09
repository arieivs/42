#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	std::cout << "POINTS" << std::endl;
	DEBUG(std::cout << std::endl << "CONSTRUCTORS" << std::endl;)
	Point	x;
	Point	y(2.2f, 4.f);
	Point	z(y);

	DEBUG(std::cout << std::endl << "TESTS" << std::endl;)
	std::cout << "x = " << x << std::endl;
	x = y;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "z = " << z << std::endl;

	std::cout << std::endl << "TRIANGLE" << std::endl;
	DEBUG(std::cout << std::endl << "CONSTRUCTORS" << std::endl;)
	Point const a(0.0f, 0.0f);
	Point const b(2.0f, 2.0f);
	Point const c(2.5f, 1.0f);
	Point const p1(1.5f, 1.0f);
	Point const p2(1.5f, 0.5f);
	Point const p3(1.0f, 1.0f);
	Point const p4(-0.1f, -0.1f);
	Point const p5(1.0f, 0.5f);

	DEBUG(std::cout << std::endl << "TESTS" << std::endl;)
	std::cout << "Test Point 1: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	std::cout << "Test Point 2: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	std::cout << "Test Point 3: " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
	std::cout << "Test Point 4: " << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;
	std::cout << "Test Point 5: " << (bsp(a, b, c, p5) ? "true" : "false") << std::endl;

	DEBUG(std::cout << std::endl << "CLEAN UP" << std::endl;)
	return (0);
}