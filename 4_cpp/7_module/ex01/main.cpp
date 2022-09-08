#include <iostream>
#include <string>
#include <stdio.h>
#include "iter.hpp"

void	print_double(int& n) {
	std::cout << (n * 2) << std::endl;
}

void	print_louder(std::string& str) {
	size_t	i;

	for (i = 0; i < str.length(); i++)
		putchar(toupper(str[i]));
	std::cout << "!" << std::endl;
}

int	main(void) {
	int			arr_ints[] = {1, 2, 3, 4, 5};
	std::string	arr_strs[] = {"Hello darkness", "My old friend"};

	iter(arr_ints, 5, &print_double);
	iter(arr_strs, 2, &print_louder);
	return (0);
}
