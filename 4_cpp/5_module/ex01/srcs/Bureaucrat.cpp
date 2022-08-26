#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	_name("Nobody Owens"),
	_grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) :
	_name(name) {
	std::cout << "Bureaucrat parameterized constructor" << std::endl;
	_grade = sanitizeGrade(grade);
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

void	Bureaucrat::decrementGrade(void) {
	_grade = sanitizeGrade(_grade + 1);
}

void	Bureaucrat::incrementGrade(void) {
	_grade = sanitizeGrade(_grade - 1);
}

void	Bureaucrat::signForm(Form* f) {
	if (f->beSigned(this))
		std::cout << _name << " signed " << f->getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << f->getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! The highest possible grade will be given.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! The lowest possible grade will be given.";
}

int	Bureaucrat::sanitizeGrade(int grade) {
	try {
		if (grade < HIGHEST_GRADE) 
			throw Bureaucrat::GradeTooHighException();
		if (grade > LOWEST_GRADE)
			throw Bureaucrat::GradeTooLowException();
		return (grade);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
		return (HIGHEST_GRADE);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		return (LOWEST_GRADE);
	}
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}

