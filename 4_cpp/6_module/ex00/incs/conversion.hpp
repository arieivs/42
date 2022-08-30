#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include <cfloat>
# include <iomanip>
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define OTHER 5
# ifdef DEBUG_MODE
#  define DEBUG(x) x
# else
#  define DEBUG(x)  
# endif

typedef struct {
	char	c;
	int		n;
	float	f;
	double	d;
	bool	is_char_impossible;
	bool	is_int_impossible;
	bool	is_pseudo_literal; /* NAN, +-INF */
}	conversions_t;

/* Parsing */
conversions_t	initialize_conversions(void);
void			convert_str_to_i(std::string str, conversions_t* conversions);
void			convert_str_to_f(std::string str, conversions_t* conversions);
void			convert_str_to_d(std::string str, conversions_t* conversions);
int				get_original_type(std::string arg, conversions_t* conversions);

/* Further Conversions */
void	convert_from_char(conversions_t* conversions);
void	convert_from_int(conversions_t* conversions);
void	convert_from_float(conversions_t* conversions);
void	convert_from_double(conversions_t* conversions);


/* Display */
void	display(conversions_t* conversions);

#endif
