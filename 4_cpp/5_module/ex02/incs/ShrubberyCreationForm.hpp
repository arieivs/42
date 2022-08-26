#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

		virtual bool	execute(Bureaucrat const & executor) const;
	
	private:
		std::string	_target;

		void		writeAsciiTree(void) const;
};

#endif
