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
		
		john.decrementGrade();
		john2.incrementGrade();
		std::cout << john << std::endl << john2 << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "EXCEPTIONAL PEOPLE" << std::endl;
		Bureaucrat	simon = Bureaucrat("Simon", 160);
		Bureaucrat	laura = Bureaucrat("Laura", -2);
		
		std::cout << std::endl << simon << std::endl
				  << laura << std::endl << std::endl;

		simon.decrementGrade();
		laura.incrementGrade();
		std::cout << simon << std::endl << laura << std::endl << std::endl;
	}
	return (0);
}
