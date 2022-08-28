#include "conversion.hpp"

int	main(int ac, char **av) {
	int	type;

	if (ac != 2) {
		std::cout << "Wrong number of arguments." << std::endl
				  << "Please provide a char, int, float or double." << std::endl;
		return (1);
	}
	type = check_type(av[1]);
	std::cout << type << std::endl;
	return (0);
}
