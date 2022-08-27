#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Robotomy Request Form", 72, 45),
	_target("target") {
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Robotomy Request Form", 72, 45),
	_target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	Form("Robotomy Request Form", 72, 45),
	_target(src._target) {
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	return ;
}

/* private variables, thus they cannot be changed */
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
	return ;
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!Form::canExecute(executor))
		return (false);
	performRobotomy();
	return (true);
}

void	RobotomyRequestForm::performRobotomy(void) const {
	int	success;

	std::cout << "VRRUUMMM VRRUUMMM SQUIIIKK CLASH PUFF" << std::endl;
	/* initiallize random seed - without it, it won't be random */
	srand (time(NULL));
	success = rand() % 2;
	if (success == 1)
		std::cout << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << _target << "'s robotomy has failed" << std::endl; 
}

