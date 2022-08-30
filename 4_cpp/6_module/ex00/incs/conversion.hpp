#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include <cfloat>
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define OTHER 5

typedef struct {
	char	c;
	int		n;
	float	f;
	double	d;
	bool	is_char_possible;
	bool	is_int_possible;
	bool	is_float_possible;
	bool	is_double_possible;
}	conversions_t;

/* Parsing */
conversions_t	initialize_conversions(void);
void			convert_str_to_i(std::string str, conversions_t* conversions);
void			convert_str_to_f(std::string str, conversions_t* conversions);
void			convert_str_to_d(std::string str, conversions_t* conversions);
int				get_original_type(std::string arg, conversions_t* conversions);

#endif
