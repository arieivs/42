#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <stdint.h> /* uintptr_t */

typedef struct {
	std::string	name;
	int			age;
	float		height;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
