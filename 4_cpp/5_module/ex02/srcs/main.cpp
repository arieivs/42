#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat	john = Bureaucrat("John", 5);
	Bureaucrat	simon = Bureaucrat("Simon", 147);

	std::cout << std::endl << "CREATING AND COPYING SPECIAL FORMS" << std::endl;
	ShrubberyCreationForm	shrub_form("eden");
	ShrubberyCreationForm	shrub_form_2(shrub_form);
	RobotomyRequestForm		robot_form("Wall-e");
	RobotomyRequestForm		robot_form_2(robot_form);
	PresidentialPardonForm	pres_form("Arthur Dent");
	PresidentialPardonForm	pres_form_2(pres_form);

	std::cout << std::endl << "PLANTING SHRUBS" << std::endl;
	std::cout << shrub_form << std::endl << std::endl;
	john.executeForm(shrub_form);
	john.signForm(&shrub_form);
	john.executeForm(shrub_form);
	simon.executeForm(shrub_form);

	std::cout << std::endl << "TO ROBOTOMIZE OR NOT TO ROBOTOMIZE" << std::endl;
	std::cout << robot_form << std::endl << std::endl;
	john.executeForm(robot_form);
	john.signForm(&robot_form);
	john.executeForm(robot_form);
	simon.executeForm(robot_form);

	std::cout << std::endl << "GRANTING PARDONS" << std::endl;
	std::cout << pres_form << std::endl << std::endl;
	john.executeForm(pres_form);
	john.signForm(&pres_form);
	john.executeForm(pres_form);
	simon.executeForm(pres_form);

	std::cout << std::endl;
	return (0);
}
