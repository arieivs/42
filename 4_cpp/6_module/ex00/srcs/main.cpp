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
	type = get_original_type(av[1], &conversions);
	switch(type) {
		case 1:
			convert_from_char(&conversions);
			DEBUG(std::cout << "CHAR " << conversions.c << std::endl;)
			break;
		case 2:
			convert_from_int(&conversions);
			DEBUG(std::cout << "INT " << conversions.n << std::endl;)
			break;
		case 3:
			convert_from_float(&conversions);
			DEBUG(std::cout << "FLOAT " << conversions.f << std::endl;)
			break;
		case 4:
			convert_from_double(&conversions);
			DEBUG(std::cout << "DOUBLE " << conversions.d << std::endl;)
			break;
		default:
			std::cout << "Wrong type of argument." << std::endl
					  << "Please provide a char, int, float or double."
					  << std::endl;
			return (1);
	}
	display(&conversions);
	return (0);
}
