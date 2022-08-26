#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	_name("Nobody Owens"),
	_grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";// improve
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!"; // improve
}

Bureaucrat::Bureaucrat(std::string const name, int grade) :
	_name(name) {
	std::cout << "Bureaucrat parameterized constructor" << std::endl;
	//_grade = grade;
	try {
		if (grade < HIGHEST_GRADE) 
			throw Bureaucrat::GradeTooHighException();
		else if (grade > LOWEST_GRADE)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
		_grade = HIGHEST_GRADE;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		_grade = LOWEST_GRADE;
	}
	// TODO with exception
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
	_name(src._name) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	_grade = src._grade;
	return ;
}

/* const name, thus it cannot be changed */
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & src) {
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor" << std::endl;
	return ;
}

std::string const	Bureaucrat::getName(void) const {
	return _name;
}

int	Bureaucrat::getGrade(void) const {
	return _grade;
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}

