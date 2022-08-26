#include "Bureaucrat.hpp"

int	main(void) {
	{
		std::cout << "A LOT OF REGULAR JOHNS" << std::endl;
		Bureaucrat	john = Bureaucrat("John", 100);
		Bureaucrat	john2 = Bureaucrat(john);
		Bureaucrat	john3;

		john3 = john;
		std::cout << std::endl << john << std::endl << john2 << std::endl
				  << john3 << std::endl << std::endl;
		
		// try increment and decrement within normal
	}
	{
		std::cout << "EXCEPTIONAL PEOPLE" << std::endl;
		Bureaucrat	simon = Bureaucrat("Simon", 160);
		Bureaucrat	laura = Bureaucrat("Laura", -2);
		
		std::cout << std::endl << simon << std::endl << laura << std::endl;
		// do we still create the bureaucrat?
		// increment and decrement to outside boundaries
	}
	return (0);
}
