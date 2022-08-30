#include "conversion.hpp"

void	convert_from_char(conversions_t* conversions) {
	conversions->n = static_cast<int>(conversions->c);
	conversions->f = static_cast<float>(conversions->n);
	conversions->d = static_cast<double>(conversions->n);
}

void	convert_from_int(conversions_t* conversions) {
	if (conversions->is_int_impossible) {
		conversions->is_char_impossible = true;
		conversions->is_pseudo_literal = true;
		conversions->f = (1.0/0.0);
		conversions->d = (1.0/0.0);
		return ;
	}
	conversions->c = static_cast<char>(conversions->n);
	conversions->f = static_cast<float>(conversions->n);
	conversions->d = static_cast<double>(conversions->n);
}

void	convert_from_float(conversions_t* conversions) {
	long int	long_n;

	conversions->d = static_cast<double>(conversions->f);
	if (conversions->is_pseudo_literal) {
		conversions->is_char_impossible = true;
		conversions->is_int_impossible = true;
		return ;
	}
	conversions->n = static_cast<int>(conversions->f);
	long_n = static_cast<long int>(conversions->f);
	if (conversions->n != long_n) {
		conversions->is_int_impossible = true;
		conversions->is_char_impossible = true;
		return ;
	}
	conversions->c = static_cast<char>(conversions->n);
}

void	convert_from_double(conversions_t* conversions) {
	long int	long_n;

	conversions->f = static_cast<float>(conversions->d);
	if (conversions->is_pseudo_literal) {
		conversions->is_char_impossible = true;
		conversions->is_int_impossible = true;
		return ;
	}
	conversions->n = static_cast<int>(conversions->d);
	long_n = static_cast<long int>(conversions->d);
	if (conversions->n != long_n) {
		conversions->is_int_impossible = true;
		conversions->is_char_impossible = true;
		return ;
	}
	conversions->c = static_cast<char>(conversions->n);
}	

