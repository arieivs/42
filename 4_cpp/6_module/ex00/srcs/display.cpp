#include "conversion.hpp"

static bool	is_non_displayable(char c) {
	/* white space: 9-13 and 32 */
	if ((c >= 9 && c <= 13) || (c >= 32 && c <= 126))
		return (false);
	return (true);
}

void	display(conversions_t* conversions) {
	std::cout << "char: ";
	if (conversions->is_char_impossible)
		std::cout << "impossible" << std::endl;
	else if (is_non_displayable(conversions->c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << conversions->c << "'" << std::endl;
	
	std::cout << "int: ";
	if (conversions->is_int_impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << conversions->n << std::endl;
	
	std::cout << "float: ";
	std::cout << conversions->f << "f" << std::endl;

	std::cout << "double: ";
	std::cout << conversions->d << std::endl;
	// TODO think .0 at the end
}
	
