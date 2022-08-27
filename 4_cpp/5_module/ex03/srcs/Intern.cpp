#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor" << std::endl;
	return ;
}

Intern::Intern(Intern const & src) {
	std::cout << "Intern copy constructor" << std::endl;
	(void)src;
	return ;
}

Intern&	Intern::operator=(Intern const & src) {
	std::cout << "Intern copy assignment operator" << std::endl;
	(void)src;
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "Intern destructor" << std::endl;
	return ;
}

/* Array of pointers to derivative classes member functions:
- it's not possible to have pointers to constructors
- it won't work if the functions are defined in different classes,
  even if the class is a child or sibling
*/
Form*	Intern::makeForm(std::string form_name, std::string target) {
	std::string	form_names[3] = {"shrubbery creation",
								 "robotomy request",
								 "presidential pardon"};
	Form*	(Intern::*form_makers[3])(std::string) = {&Intern::makeShrubberyForm,
							  &Intern::makeRobotomyForm,
							  &Intern::makePresidentialForm};
	Form*	form;
	int		i;

	for (i = 0; i < 3; i++) {
		if (form_names[i].compare(form_name) == 0) {
			std::cout << "Intern creates " << form_name << " form" << std::endl;	
			form = (this->*form_makers[i])(target);
			return (form);
		}
	}
	std::cout << "Unknown form. The available form types are:" << std::endl
			  << "- shrubbery creation" << std::endl << "- robotomy request"
			  << std::endl << "- presidential pardon" << std::endl << std::endl;
	return (0);
}

Form*	Intern::makeShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form*	Intern::makePresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}

