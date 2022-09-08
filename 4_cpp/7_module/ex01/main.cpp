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

/* EVAL SHEET */
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & out, Awesome const & a) {
	out << a.get();
	return (out);
}

template<typename T>
void print( T const & x ) { std::cout << x << std::endl; return; }

int	main(void) {
	int			arr_ints[] = {1, 2, 3, 4, 5};
	std::string	arr_strs[] = {"Hello darkness", "My old friend"};

	iter(arr_ints, 5, &print_double);
	iter(arr_strs, 2, &print_louder);

	/* EVAL SHEET */
	const int tab[] = { 0, 1, 2, 3, 4 };
	const Awesome tab2[] = { Awesome(), Awesome(), Awesome(), Awesome(), Awesome()};
	iter( tab, 5, print );
	iter( tab2, 5, print );

	// TODO find how to test template function

	return (0);
}
