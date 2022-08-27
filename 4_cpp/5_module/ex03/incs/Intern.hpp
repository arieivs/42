#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern&	operator=(Intern const & src);
		~Intern(void);

		Form*	makeForm(std::string form_name, std::string target);

	private:
		Form*	makeShrubberyForm(std::string target);
		Form*	makeRobotomyForm(std::string target);
		Form*	makePresidentialForm(std::string target);
};

#endif
