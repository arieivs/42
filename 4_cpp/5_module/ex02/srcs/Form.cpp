#include "Form.hpp"

Form::Form(void) :
	_name("Unnamed Form"),
	_is_signed(false),
	_grade_sign(150),
	_grade_exec(150) {
	std::cout << "Form default constructor" << std::endl;
	return ;
}

Form::Form(std::string name, int grade_sign, int grade_exec) :
	_name(name),
	_is_signed(false),
	_grade_sign(sanitizeGrade(grade_sign)),
	_grade_exec(sanitizeGrade(grade_exec)) {
	std::cout << "Form parameterized constructor" << std::endl;
	return ;
}

Form::Form(Form const & src) :
	_name(src._name),
	_is_signed(src._is_signed),
	_grade_sign(src._grade_sign),
	_grade_exec(src._grade_exec) {
	std::cout << "Form copy constructor" << std::endl;
	return ;
}

/* const variables, thus they cannot be changed */
Form&	Form::operator=(Form const & src) {
	std::cout << "Form copy assignment operator" << std::endl;
	_is_signed = src._is_signed;
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form destructor" << std::endl;
	return ;
}

std::string const	Form::getName(void) const {
	return _name;
}

bool	Form::getIsSigned(void) const {
	return _is_signed;
}

int	Form::getGradeSign(void) const {
	return _grade_sign;
}

int	Form::getGradeExec(void) const {
	return _grade_exec;
}

bool	Form::beSigned(Bureaucrat* b) {
	try {
		if (b->getGrade() > _grade_sign)
			throw Form::GradeTooLowException();
		_is_signed = true;
		return (true);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
}

bool	Form::canExecute(Bureaucrat const & executor) const {
	try {
		if (executor.getGrade() > _grade_exec)
			throw Form::GradeTooLowException();
		if (!_is_signed)
			throw Form::FormNotSignedException();
		return (true);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
	catch (Form::FormNotSignedException& e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char*	Form::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

int	Form::sanitizeGrade(int grade) {
	try {
		if (grade < HIGHEST_GRADE) 
			throw Form::GradeTooHighException();
		if (grade > LOWEST_GRADE)
			throw Form::GradeTooLowException();
		return (grade);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
		return (HIGHEST_GRADE);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		return (LOWEST_GRADE);
	}
}

std::ostream&	operator<<(std::ostream& o, Form const & f) {
	o << f.getName() << ", signature grade: " << f.getGradeSign()
	  << ", execution grade: " << f.getGradeExec()
	  << (f.getIsSigned() ? ", Signed" : ", Not Signed");
	return (o);
}

