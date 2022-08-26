#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat&	operator=(Bureaucrat const & src);
		~Bureaucrat(void);

		std::string const	getName(void) const;
		int					getGrade(void) const;
		void				decrementGrade(void);
		void				incrementGrade(void);
		
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
		int					_grade;

		int	sanitizeGrade(int grade);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & b);

#endif
