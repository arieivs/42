#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string name, int grade_sign, int grade_exec);
		Form(Form const & src);
		Form&	operator=(Form const & src);
		~Form(void);

		std::string const	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				beSigned(Bureaucrat* b);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_grade_sign;
		int const			_grade_exec;

		int	sanitizeGrade(int grade);
};

std::ostream&	operator<<(std::ostream& o, Form const & b);

#endif
