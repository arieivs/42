#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <stdlib.h>
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
}	conversions_t;

/* Parsing */
conversions_t	initialize_conversions(void);
int				check_type(std::string arg, conversions_t* conversions);

#endif
