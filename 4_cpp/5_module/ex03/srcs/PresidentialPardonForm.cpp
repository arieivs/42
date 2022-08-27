#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential Pardon Form", 25, 5),
	_target("target") {
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("Presidential Pardon Form", 25, 5),
	_target(target) {
	std::cout << "PresidentialPardonForm parameterized constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	Form("Presidential Pardon Form", 25, 5),
	_target(src._target) {
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	return ;
}

/* private variables, thus they cannot be changed */
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor" << std::endl;
	return ;
}

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!Form::canExecute(executor))
		return (false);
	grantPresidentialPardon();
	return (true);
}

void	PresidentialPardonForm::grantPresidentialPardon(void) const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

