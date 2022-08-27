#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	Intern		ben;
	Bureaucrat	john = Bureaucrat("John", 5);
	{
		Form*		form;

		std::cout << std::endl;
		form = ben.makeForm("robotomy request", "Wall-e");
		john.signForm(form);
		john.executeForm(*form);
	}
	{
		Form*		form;

		std::cout << std::endl;
		form = ben.makeForm("shrubbery creation", "narnia");
		john.signForm(form);
		john.executeForm(*form);
	}
	{
		Form*		form;

		std::cout << std::endl;
		form = ben.makeForm("presidential pardon", "Marvin");
		john.signForm(form);
		john.executeForm(*form);
	}
	{
		Form*		form;

		std::cout << std::endl;
		form = ben.makeForm("form 404", "Someone");
	}
	return (0);
}
