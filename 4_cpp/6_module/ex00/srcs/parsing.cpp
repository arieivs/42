#include "conversion.hpp"

conversions_t	initialize_conversions(void) {
	conversions_t	conversions;

	conversions.c = 0;
	conversions.n = 0;
	conversions.f = 0.0f;
	conversions.d = 0.0;
	conversions.is_char_impossible = false;
	conversions.is_int_impossible = false;
	conversions.is_float_impossible = false;
	conversions.is_double_impossible = false;
	conversions.is_pseudo_literal = false;
	return (conversions);
}

void	convert_str_to_i(std::string str, conversions_t* conversions) {
	std::stringstream	ss1(str);
	std::stringstream	ss2(str);
	int					n;
	long int			long_n;

	ss1 >> n;
	ss2 >> long_n;
	if (n != long_n)
		conversions->is_int_impossible = true;
	else
		conversions->n = n;
}

void	convert_str_to_f(std::string str, conversions_t* conversions) {
	std::stringstream	ss1(str.substr(0, str.length() - 1));		
	std::stringstream	ss2(str.substr(0, str.length() - 1));		
	float				f;
	double				d;

	ss1 >> f;
	ss2 >> d;
	if (d >= std::numeric_limits<float>::max()) {
		conversions->f = (1.0/0.0);
		conversions->is_pseudo_literal = true;
	}
	else
		conversions->f = f;
}

void	convert_str_to_d(std::string str, conversions_t* conversions) {
	std::stringstream	ss1(str);
	std::stringstream	ss2(str);
	double				d;
	long double			long_d;

	ss1 >> d;
	ss2 >> long_d;
	if (long_d >= std::numeric_limits<double>::max()) {
		conversions->d = (1.0/0.0);
		conversions->is_pseudo_literal = true;
	}
	else
		conversions->d = d;
}

int	get_original_type(std::string arg, conversions_t* conversions) {
	std::size_t	i = 0;

	/* if len=1 it's either a char or a single digit int */
	if (arg.length() == 1 && !(arg[0] >= '0' && arg[0] <= '9')) {
		conversions->c = arg[0];
		return (CHAR);
	}
	/* double special cases - pseudo literals */
	if (arg.compare("nan") == 0 || arg.compare("-inf") == 0 ||
		arg.compare("+inf") == 0 || arg.compare("inf") == 0) {
		convert_str_to_d(arg, conversions);
		conversions->is_pseudo_literal = true; /* needed for NAN */
		return (DOUBLE);
	}
	/* float special cases - pseudo literals */
	if (arg.compare("nanf") == 0 || arg.compare("-inff") == 0 ||
		arg.compare("+inff") == 0 || arg.compare("inff") == 0) {
		convert_str_to_f(arg, conversions);
		conversions->is_pseudo_literal = true; /* needed for NAN */
		return (FLOAT);
	}
	/* int, float, double may start with + or - */
	if (arg[0] && (arg[0] == '+' || arg[0] == '-'))
		i++;
	while (i != std::string::npos && (arg[i] >= '0' && arg[i] <= '9'))
		i++;
	if (!arg[i]) {
		convert_str_to_i(arg, conversions);
		return (INT);
	}
	if (arg[i] && arg[i] == '.')
		i++;
	while (i != std::string::npos && (arg[i] >= '0' && arg[i] <= '9'))
		i++;
	if (!arg[i]) {
		convert_str_to_d(arg, conversions);
		return (DOUBLE);
	}
	if (arg[i] && arg[i] == 'f' && !arg[i + 1]) {
		convert_str_to_f(arg, conversions);
		return (FLOAT);
	}
	return (OTHER);
}

