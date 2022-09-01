#include <iostream>
#include "whatever.hpp"

int	main(void) {
	int a = 2;
	int b = 3;

	std::cout << "INT" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap<int>( a, b );
	std::cout << "Swap! a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max<int>( a, b ) << std::endl;
	/* Explicit instaciation of the templates */

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << std::endl << "STRING" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Swap! c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	/* Implicit instaciation of the templates */
	/* :: are necessary to specify the template defined by us
	   else the call to max and min are ambiguous as these functions
	   already exist for strings, for e.g. */

	float	e = 2.f;
	float	f = -2.f;

	std::cout << std::endl << "FLOAT" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "Swap! e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << max( e, f ) << std::endl;
	
	return (0);
}

