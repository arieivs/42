#include "Fixed.hpp"

int	main(void) {
	Fixed	fixed_point_nb_stack = Fixed();
	Fixed*	fixed_point_nb_heap = new Fixed();

	delete fixed_point_nb_heap;
	return (0);
}