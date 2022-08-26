#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	john = Bureaucrat("John", 5);
	Bureaucrat	simon = Bureaucrat("Simon", 147);

	std::cout << std::endl << "PLANTING SHRUBS" << std::endl;
	ShrubberyCreationForm	shrub_form = ShrubberyCreationForm("target");

	std::cout << std::endl << shrub_form << std::endl << std::endl;
	john.executeForm(shrub_form);
	john.signForm(&shrub_form);
	john.executeForm(shrub_form);
	simon.executeForm(shrub_form);

	std::cout << std::endl;
	return (0);
}
