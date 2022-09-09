#include <iostream>
#include <string>
#include <stdio.h>
#include "iter.hpp"

/* normal functions */
void	printDouble(int& n) {
	std::cout << (n * 2) << std::endl;
}

void	printLouder(std::string& str) {
	size_t	i;

	for (i = 0; i < str.length(); i++)
		putchar(toupper(str[i]));
	std::cout << "!" << std::endl;
}

/* template function with parameter (T&) */
template <typename T>
void	printTripple(T& t) {
	std::cout << t * 3 << std::endl;
}

/* template function with parameter (T const &) */
template<typename T>
void	print( T const & x ) {
	std::cout << x << std::endl;
}

/* a more complex data type */
class FakeInt {
	public:
		FakeInt(void) : _n(42) { return; }
		int	get(void) const { return this->_n; }
	private:
		int	_n;
};
std::ostream & operator<<(std::ostream & out, FakeInt const & a) {
	out << a.get();
	return (out);
}

int	main(void) {
	std::cout << "TESTING function" << std::endl;
	int			arr_ints[] = {1, 2, 3, 4, 5};
	std::string	arr_strs[] = {"Hello darkness", "My old friend"};

	iter(arr_ints, 5, printDouble);
	iter(arr_strs, 2, printLouder);

	std::cout << std::endl << "TESTING template function with parameter (T&)" << std::endl;
	float	arr_flts[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter(arr_flts, 5, printTripple);
	/* if we instatiate it like this, the generic case works: */
	/*iter(arr_flts, 5, printTripple<float>);*/

	std::cout << std::endl << "TESTING template function with parameter (T const &)" << std::endl;
	const int		tab[] = { 0, 1, 2, 3, 4 };
	const FakeInt	tab2[] = { FakeInt(), FakeInt(), FakeInt(), FakeInt(), FakeInt()};
	
	iter(tab, 5, print);
	iter(tab2, 5, print);
	/* if we instatiate them like this, the generic case works: */
	/*iter(tab, 5, print<const int>);
	iter(tab2, 5, print<const FakeInt>);*/
	return (0);
}
