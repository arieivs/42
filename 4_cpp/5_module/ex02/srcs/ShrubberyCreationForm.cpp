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
	return (writeAsciiTree());
}

/* if open/close fail, an ios_base::failure exception should be thrown
 * https://cplusplus.com/reference/fstream/fstream/open/
 * thus I'm not creating my own exception */
bool	ShrubberyCreationForm::writeAsciiTree(void) const {
	std::ofstream	out_file;
	std::string		content;

	out_file.open((_target + "_shrubbery").c_str());
	if (out_file.fail()) {
		std::cout << "Could not create target file" << std::endl;
		return (false);
	}
	out_file << "   x" << std::endl
			 << "  xxx" << std::endl
			 << " xxxxx" << std::endl
			 << "xxxxxxx" << std::endl
			 << "   x" << std::endl
			 << "   x" << std::endl;
	out_file.close();
	if (out_file.fail()) {
		std::cout << "Could not close targetfile" << std::endl;
		return (false);
	}
	return (true);
}

