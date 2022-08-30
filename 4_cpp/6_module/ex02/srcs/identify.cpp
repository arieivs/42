#include "identify.hpp"

Base*	generate(void) {
	int	which_class;

	srand (time(NULL));
	which_class = rand() % 3;
	switch (which_class) {
		case 0:
			DEBUG(std::cout << "Generating A" << std::endl;)
			return (new A());
		case 1:
			DEBUG(std::cout << "Generating B" << std::endl;)
			return (new B());
		case 2:
			DEBUG(std::cout << "Generating C" << std::endl;)
			return (new C());
		default:
			std::cout << "Something went wrong with the Random generation"
					  << std::endl;
	}
	return (new Base());
}

void	identify(Base* p) {
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "object of type A" << std::endl;
	if (b != NULL)
		std::cout << "object of type B" << std::endl;
	if (c != NULL)
		std::cout << "object of type C" << std::endl;
}

void	identify(Base& p) {
	bool	is_a = true;
	bool	is_b = true;
	bool	is_c = true;

	try {
		A&	a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (std::bad_cast& e) {
		is_a = false;
	}
	try {
		B&	b = dynamic_cast<B&>(p);
		(void)b;
	}
	catch (std::bad_cast& e) {
		is_b = false;
	}
	try {
		C&	c = dynamic_cast<C&>(p);
		(void)c;
	}
	catch (std::bad_cast& e) {
		is_c = false;
	}
	if (is_a)
		std::cout << "object of type A" << std::endl;
	if (is_b)
		std::cout << "object of type B" << std::endl;
	if (is_c)
		std::cout << "object of type C" << std::endl;
}

