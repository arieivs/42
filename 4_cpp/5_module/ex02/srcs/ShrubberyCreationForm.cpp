#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Shrubbery Creation Form", 145, 137),
	_target("target") {
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(target) {
	std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(src._target) {
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	return ;
}

/* private variables, thus they cannot be changed */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
	return ;
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!Form::canExecute(executor))
		return (false);
	writeAsciiTree();
	return (true);
}

void	ShrubberyCreationForm::writeAsciiTree(void) const {
	// TODO
	std::cout << "To actually write an Ascii Tree..." << std::endl;
}

