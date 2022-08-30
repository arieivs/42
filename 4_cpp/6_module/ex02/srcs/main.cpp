#include "identify.hpp"

int	main(void) {
	Base*	base;

	base = generate();
	identify(base);
	identify(*base);
	return (0);
}
