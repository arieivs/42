#include "conversion.hpp"

conversions_t	initialize_conversions(void) {
	conversions_t	conversions;

	conversions.c = 0;
	conversions.n = 0;
	conversions.f = 0.0f;
	conversions.d = 0.0;
	conversions.is_char_possible = false;
	conversions.is_int_possible = false;
	return (conversions);
}

int	check_type(std::string arg, conversions_t* conversions) {
	std::size_t	i = 0;

	/* if len=1 it's either a char or a single digit int */
	if (arg.length() == 1 && !(arg[0] >= '0' && arg[0] <= '9')) {
		conversions->c = arg[0];
		return (CHAR);
	}
	/* double special cases */
	if (arg.compare("nan") == 0 || arg.compare("-inf") == 0 ||
		arg.compare("+inf") == 0) {
		conversions->d = std::stod(arg); // CANNOT DO THIS
		return (DOUBLE);
	}
	/* float special cases */
	if (arg.compare("nanf") == 0 || arg.compare("-inff") == 0 ||
		arg.compare("+inff") == 0) {
		conversions->f = std::stof(arg); // CANNOT DO THIS
		return (FLOAT);
	}
	/* int, float, double may start with + or - */
	if (arg[0] && (arg[0] == '+' || arg[0] == '-'))
		i++;
	while (i != std::string::npos && (arg[i] >= '0' && arg[i] <= '9'))
		i++;
	if (!arg[i]) {
		conversions->n = std::stoi(arg); // CANNOT DO THIS
		return (INT);
	}
	if (arg[i] && arg[i] == '.')
		i++;
	while (i != std::string::npos && (arg[i] >= '0' && arg[i] <= '9'))
		i++;
	if (!arg[i]) {
		conversions->d = std::stod(arg); // CANNOT DO THIS
		return (DOUBLE);
	}
	if (arg[i] && arg[i] == 'f' && !arg[i + 1]) {
		conversions->f = std::stof(arg); // CANNOT DO THIS
		return (FLOAT);
	}
	return (OTHER);
}

// TO THINK what if it exceeds the limit for int or float? (or double)

