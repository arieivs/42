#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>
# include <exception>
# include "Bureaucrat.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);

		virtual bool	execute(Bureaucrat const & executor) const;
	
	private:
		std::string	_target;

		void		performRobotomy(void) const;
};

#endif
