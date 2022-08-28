#include "conversion.hpp"

int	main(int ac, char **av) {
	conversions_t	conversions;
	int	type;

	if (ac != 2) {
		std::cout << "Wrong number of arguments." << std::endl
				  << "Please provide a char, int, float or double." << std::endl;
		return (1);
	}
	conversions = initialize_conversions();
	type = check_type(av[1], &conversions);
	switch(type) {
		case 1:
			std::cout << "CHAR " << conversions.c << std::endl;
			break;
		case 2:
			std::cout << "INT " << conversions.n << std::endl;
			break;
		case 3:
			std::cout << "FLOAT " << conversions.f << std::endl;
			break;
		case 4:
			std::cout << "DOUBLE " << conversions.d << std::endl;
			break;
		default:
			std::cout << "Wrong type of argument." << std::endl
					  << "Please provide a char, int, float or double."
					  << std::endl;
	}
	return (0);
}
